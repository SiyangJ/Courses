//
//  main.cpp
//  Final
//
//  Created by apple on 4/4/18.
//  Copyright © 2018 UNC. All rights reserved.

#include <iostream>
#include <stdio.h>
#include <algorithm>

#include "Eigen/Dense"
#include "Eigen/Sparse"

#include <Accelerate/Accelerate.h>

#include "DTArguments.h"
#include "DTSaveError.h"

#include "DTDoubleArray.h"
#include "DTIntArray.h"
#include "DTMatlabDataFile.h"

#include "DTDoubleArrayOperators.h"
#include "DTTimer.h"
#include "DTUtilities.h"

#include "DTDictionary.h"
#include "DTMesh2D.h"
#include "DTFunction2D.h"

#include "DTSeriesMesh2D.h"

#include <math.h>
#include <vector>

using namespace std;
using namespace Eigen;

double maxnorm(double* v,int l)
{
    double res = 0;
    for(int i=0;i<l;i++)
    {
        res = max(res,abs(v[i]));
    }
    return res;
}

// On the issue of storing order & indexing order:
//      Eigen uses column-major
//      Therefore, I better also use column-major
//      Index order is (x,y)
//      which means each x corresponds to a row
//      which means we first traverse x, then traverse y

//         -1
// A = [-1, 4,-1]
//         -1
// b = rhs
void Axminusb(const double* x,const double* b,double* output, const int& N)
{
    int dim = N+1;
    int it = 0;
    int i=0,j=0;
    // i=0;
    for(j=0;j<=N;j++)
    {
        output[it++]=0;
    }
    for(i=1;i<N;i++)
    {
        // j=0;
        output[it++] = 0;
        for(j=1;j<N;j++)
        {
            output[it] = 4*x[it]-
                             x[it+1]-
                             x[it-1]-
                             x[it+dim]-
                             x[it-dim]-
                             b[it];
            it++;
        }
        // j=N;
        output[it++] = 0;
    }
    // i=N;
    for(j=0;j<=N;j++)
    {
        output[it++]=0;
    }
}

//         -1
// A = [-1, 4,-1]
//         -1
// b = rhs
// D^-1 = 1/4
void WeightedJacobiSweep(const double* rhs,
                         const double* input,double* output,
                         const int& N, const double& w)
{
    int dim = N+1;
    int it = 0;
    int i=0,j=0;
    double wd4 = w/4;
    // i=0;
    for(j=0;j<=N;j++)
    {
        output[it++]=0;
    }
    for(i=1;i<N;i++)
    {
        // j=0;
        output[it++] = 0;
        for(j=1;j<N;j++)
        {
            output[it] = (1-w)*input[it] +
                            wd4*(input[it+1] +
                                 input[it-1] +
                                 input[it+dim] +
                                 input[it-dim] +
                                 rhs[it]);
            it++;
        }
        // j=N;
        output[it++] = 0;
    }
    // i=N;
    for(j=0;j<=N;j++)
    {
        output[it++]=0;
    }
}

// Pre:  input: 0 to (N+1)^2 contain x
void Coarsen(double* input, const int& N)
{
    int dim_fine = N+1;
    int Nd2 = N/2;
    int dim_coarse = Nd2+1;
    int coarsesize = dim_coarse*dim_coarse;
    double* output = input+dim_fine*dim_fine;
    int it_coarse = 0;
    int it_fine;
    int i=0,j=0;
    // i=0;
    for(j=0;j<=N;j+=2)
    {
        output[it_coarse++]=0;
    }
    it_fine = 2*dim_fine;
    // i=2 to N-2
    for(i=2;i<N;i+=2)
    {
        // j=0;
        output[it_coarse++] = 0;
        it_fine += 2;
        // j=2 to N-2
        for(j=2;j<N;j+=2)
        {
            output[it_coarse] = input[it_fine]/2+(
                                           input[it_fine+1]+
                                           input[it_fine-1]+
                                           input[it_fine+dim_fine]+
                                           input[it_fine-dim_fine])/8;
            it_coarse++;
            it_fine+=2;
        }
        // j=N;
        output[it_coarse++] = 0;
        it_fine += dim_fine+1;
    }
    // i=N;
    for(j=0;j<=N;j+=2)
    {
        output[it_coarse++]=0;
    }
    
    copy(output,output+coarsesize,input);
}
// Post: input: xcoarse are contained in the first (N/2+1)^2 entries



// Pre:  input: the second (N/2+1)^2 entries contain xcoarse
//           TODO: I know this is weird. Need to figure out
// This too is so freaking stupid.
void Refine(double* input, const int& N)
{
    int dim_fine = N+1;
    int Nd2 = N/2;
    int dim_coarse = Nd2+1;
    int coarsesize = dim_coarse*dim_coarse;
    int finesize = dim_fine*dim_fine;
    
    double* xcoarse__ = input+coarsesize;
    double* xcoarse=input+finesize;
    
    copy(xcoarse__,xcoarse__+coarsesize,xcoarse);
    
    double* output = input;
    int it_coarse = 0, it_fine = 0;
    int i=0,j=0;
    
    for(i=0;i<Nd2;i++)
    {
        for(j=0;j<Nd2;j++)
        {
            
            output[it_fine] = xcoarse[it_coarse];
            
            output[it_fine+1] = (xcoarse[it_coarse]+
                                 xcoarse[it_coarse+1])/2;
            
            output[it_fine+dim_fine] = (xcoarse[it_coarse]+
                                        xcoarse[it_coarse+dim_coarse])/2;
            
            output[it_fine+1+dim_fine] = (
                                   xcoarse[it_coarse]+
                                   xcoarse[it_coarse+1]+
                                   xcoarse[it_coarse+dim_coarse]+
                                   xcoarse[it_coarse+1+dim_coarse])/4;
            
            it_coarse++;
            it_fine+=2;
        }
        // j=Nd2;
        output[it_fine] = 0;
        output[it_fine+dim_fine] = 0;
        it_fine+=1+dim_fine;
        it_coarse++;
    }
    // i=Nd2;
    fill(output+it_fine,output+it_fine+N,0.0);
}
// Post: input: contains xfine


void ExactSolver(double* rhs,double* input, double* aux, int N)
{
    
    int nx = N-1;
    int ny = N-1;
    
    int innerarraysize = (N-1)*(N-1);
    
    // Eigen rhs_
    VectorXd rhs_(innerarraysize);
    int it = 0;
    for(int i=1;i<=ny;i++)
    {
        for(int j=1;j<=nx;j++)
        {
            rhs_(it)= rhs[i*(N+1)+j];
            it++;
        }
    }
    // RHS completed
    
    // Eigen AB_
    SparseMatrix<double> AB_(innerarraysize,innerarraysize);
    typedef Triplet<double> T;
    vector<T> tripletList;
    tripletList.reserve(3*innerarraysize);
    // TODO
    // Optimize the storage allocations
    for (int j=0;j<innerarraysize;j++)
    {
        if (j>=nx)
            tripletList.push_back(T(j-nx,j,-1));
        if (j%nx!=0)
            tripletList.push_back(T(j-1,j,-1));
        tripletList.push_back(T(j,j,4));
    }
    AB_.setFromTriplets(tripletList.begin(),tripletList.end());
    SimplicialLLT<SparseMatrix<double>,Eigen::Upper> solver;
    solver.compute(AB_);
    // AB completed
    
    VectorXd ans_ = solver.solve(rhs_);
    
    it = 0;
    for(int i=1;i<=ny;i++)
    {
        for(int j=1;j<=nx;j++)
        {
            input[i*(N+1)+j] = ans_(it);
            it++;
        }
    }
    return;
}

void MGSolver(double* rhs, double* x, double* aux, int N,
              const int& Nb, const int& Na, const double& w)
{
    
    int array_size = (N+1)*(N+1);
    
    // Initialize x;
    fill(x,x+array_size,0.0);
    
    if (N<=4)
    {
        // Exact solver
        ExactSolver(rhs,x,aux,N);
        return;
    }
    
    for(int nb=0;nb<Nb;nb++)
    {
        WeightedJacobiSweep(rhs,x, aux, N, w);
        swap(x,aux);
    }
    // Post: x  : contains the updated x
    //       aux: contains work array
    
    Axminusb(x,rhs,aux,N);
    // Post: x  : not changed
    //       aux: r=Ax-b;
    
    Coarsen(aux,N);
    // Post: aux: the first (N/2+1)^2 entries contain rcoarse
    //            the entries from (N/2+1)^2 contain work array
    
    int next_array_size = (N/2+1)*(N/2+1);
    
    // The factor of 4
    // From lhs to rhs
    for(int i=0;i<next_array_size;i++)
        aux[i] *= 4;
    
    MGSolver(aux, aux+next_array_size, aux+next_array_size*2, N/2, Nb,Na,w);
    
    // Pre:  aux: the second (N/2+1)^2 entries contain xcoarse
    //           TODO: I know this is weird. Need to figure out
    Refine(aux, N);
    // Post: aux: contains xfine
    
    // x = x - xfine;
    // This seems very primitive.
    for(int i=0;i<array_size;i++)
    {
        x[i] = x[i]-aux[i];
    }
    // Post: aux: contains trash
    //       x  : contains x
    
    for(int na=0;na<Na;na++)
    {
        WeightedJacobiSweep(rhs,x, aux, N, w);
        swap(x,aux);
    }
    // Post: x  : the updated x
    //       aux: work array
}

// errors: array of size ncycle+1
//         stores the max-norm of residuals after the 0,1,...,ncycle-th cycle
void MGClient(const double* rhs,const int& N, double h,
              const int& Nb, const int& Na, const double& w,
              double* errors,const int& ncycle)
{
    int array_size = (N+1)*(N+1);
    int next_array_size = (N/2+1)*(N/2+1);
    
    vector<double> xvec(array_size,0);
    double* x = xvec.data();
    double* r = new double[array_size*3+next_array_size];
    double* xr = r+array_size;
    double* aux = xr+array_size;
    
    double h2 = h*h;
    
    int i=0;
    while(true)
    {
        Axminusb(x,rhs,r,N);
        errors[i++]=maxnorm(r,array_size)/h2;
        if (i>ncycle)
            break;
        MGSolver(r,xr,aux,N,Nb,Na,w);
        for(int j=0;j<array_size;j++)
        {
            x[j] -= xr[j];
        }
    }
    delete[] r;
}

int main(int argc, const char *argv[])
{
    string inputName = "Input.mat";
    
#if DEBUG
    // Somehow Xcode needs full path.
    inputName = "/Users/wq/Desktop/SP2018/MATH662/Code/Final/Final/Input.mat";
#endif
    
    DTMatlabDataFile inputFile(inputName,DTFile::ReadOnly);
    // Read in the input variables.
    
    DTMesh2D f;
    Read(inputFile,"f",f);
    
    double w = inputFile.ReadNumber("omega");
    int Na = inputFile.ReadNumber("Na");
    int Nb = inputFile.ReadNumber("Nb");
    int ncycle = inputFile.ReadNumber("ncycle");
    
    DTMesh2DGrid grid = f.Grid();
    double h = grid.dx();
    double h2 = h*h;
    DTDoubleArray fData = f.DoubleData();
    
    // Compute the -h^2 factored f
    fData = -h2*fData;
    
    int N = (int)fData.m()-1;
    
    const double* rhs = fData.Pointer();
    
    DTMutableDoubleArray errors(ncycle+1);
    
    MGClient(rhs, N, h, Nb, Na, w, errors.Pointer(), ncycle);
    
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    outputFile.Save(errors,"errors");
}