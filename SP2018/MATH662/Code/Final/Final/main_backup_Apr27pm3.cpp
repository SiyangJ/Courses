//
//  main.cpp
//  Final
//
//  Created by apple on 4/4/18.
//  Copyright © 2018 UNC. All rights reserved.
//

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
void Axminusb(const double* rhs,const double* input,double* output, const int& N)
{
    int dim = N+1;
    int curp = 0;
    int i=0,j=0;
    // i=0;
    for(j=0;j<=N;j++)
    {
        output[curp++]=0;
    }
    for(i=1;i<N;i++)
    {
        // j=0;
        output[curp++] = 0;
        for(j=1;j<N;j++)
        {
            output[curp] = 4*input[curp]\
                            -input[curp+1]\
                            -input[curp-1]\
                            -input[curp+dim]\
                            -input[curp-dim]\
                            -rhs[curp];
            curp++;
        }
        // j=N;
        output[curp++] = 0;
    }
    // i=N;
    for(j=0;j<=N;j++)
    {
        output[curp++]=0;
    }
}

//         -1
// A = [-1, 4,-1]
//         -1
// b = rhs
// D^-1 = 1/4
void WeightedJacobiSweep(const double* rhs,const double* input,double* output, const int& N, const double& w)
{
    int dim = N+1;
    int curp = 0;
    int i=0,j=0;
    double wd4 = w/4;
    // i=0;
    for(j=0;j<=N;j++)
    {
        output[curp++]=0;
    }
    for(i=1;i<N;i++)
    {
        // j=0;
        output[curp++] = 0;
        for(j=1;j<N;j++)
        {
            output[curp] = (1-w)*input[curp]\
                            +wd4*input[curp+1]\
                            +wd4*input[curp-1]\
                            +wd4*input[curp+dim]\
                            +wd4*input[curp-dim]\
                            +wd4*rhs[curp];
            curp++;
        }
        // j=N;
        output[curp++] = 0;
    }
    // i=N;
    for(j=0;j<=N;j++)
    {
        output[curp++]=0;
    }
}

// Pre:  input: 0 to (N+1)^2 contain x
// TODO Need to think about how to implement
// Probably need a little bit extra space
// But after the function call, should be freed
// So maybe not big deal
// This implementation is SO STUPID!!!
// But I'm tired...
void Coarsen(double* input, const int& N)
{
    int dim = N+1;
    int Nd2 = N/2;
    int coarsedim = Nd2+1;
    int coarsesize = coarsedim*coarsedim;
    vector<double> coarsex(coarsesize);
    double* output = coarsex.data();
    int curp = 0;
    int curp2;
    int i=0,j=0;
    // i=0;
    for(j=0;j<=N;j+=2)
    {
        output[curp++]=0;
    }
    curp2 = 2*dim;
    // i=2 to N-2
    for(i=2;i<N;i+=2)
    {
        // j=0;
        output[curp++] = 0;
        curp2 += 2;
        // j=2 to N-2
        for(j=2;j<N;j+=2)
        {
            // Correct or not?
            // TODO need to figure out
            // Adjoint operator?
            output[curp] = input[curp2]/2 \
                          +input[curp2+1]/8 \
                          +input[curp2-1]/8 \
                          +input[curp2+dim]/8 \
                          +input[curp2-dim]/8;
            curp++;
            curp2+=2;
        }
        // j=N;
        output[curp++] = 0;
        curp2 += dim+1;
    }
    // i=N;
    for(j=0;j<=N;j+=2)
    {
        output[curp++]=0;
    }
    
    copy(output,output+coarsesize,input);
}
// Post: input: xcoarse are contained in the first (N/2+1)^2 entries

// Pre:  input: the second (N/2+1)^2 entries contain xcoarse
//           TODO: I know this is weird. Need to figure out
// This too is so freaking stupid.
// NEED TO OPTIMIZE!!!!!
void Refine(double* input, const int& N)
{
    int dim = N+1;
    int Nd2 = N/2;
    int coarsedim = Nd2+1;
    int coarsesize = coarsedim*coarsedim;
    int finesize = dim*dim;
    vector<double> finex(finesize);
    double* output = finex.data();
    int curp = 0;
    int curp2;
    int i=0,j=0;
    
    // i=0;
    for(j=0;j<=N;j++)
    {
        output[curp++]=0;
    }
    for(i=1;i<N;i++)
    {
        // j=0;
        output[curp++] = 0;
        for(j=1;j<N;j++)
        {
            if (j%2==0)
            {
                if (i%2==0)
                {
                    output[curp] = input[i/2*coarsedim+j/2];
                }
                else
                {
                    output[curp] = input[(i+1)/2*coarsedim+j/2]/2+\
                                   input[(i-1)/2*coarsedim+j/2]/2;
                }
            }
            else if (i%2==0)
            {
                output[curp] = input[i/2*coarsedim+(j+1)/2]/2+\
                               input[i/2*coarsedim+(j-1)/2]/2;
            }
            else
            {
                output[curp] = input[(i+1)/2*coarsedim+(j+1)/2]/4+\
                               input[(i-1)/2*coarsedim+(j+1)/2]/4+\
                               input[(i+1)/2*coarsedim+(j-1)/2]/4+\
                               input[(i-1)/2*coarsedim+(j-1)/2]/4;
            }
            curp++;
        }
        // j=N;
        output[curp++] = 0;
    }
    // i=N;
    for(j=0;j<=N;j++)
    {
        output[curp++]=0;
    }
    
    copy(output,output+finesize,input);
}
// Post: input: contains xfine

// On the issue of allocating memories:
//      It seems that for each stage, we need:
//              1) rhs,
//              2) x,
//              3) auxilliary space
//      The auxilliary space can be used for sweeping, and next stage
//      The spaces needed for 1), 2), and 3) are the same
//      Question is: is 3 large enough for 1', 2' and 3', the spaces of next stage?
//      3*(N/2+1)^2 >= (N+1)^2
//      We get N >= 2(1+sqrt(3))
//      So if N >= 6, it's okay
//      This means when N <= 4, we use exact solver, good result.

// On the issue of storing whole mesh or inner mesh:
//      For now, storing the whole mesh
//      which means index 0 and N are boundries, i.e. zeros,
//      and index 1 to N-1 are valid inner mesh points.
void MGSolver(double* rhs, double* input, double* aux, int N, const int& Nb, const int& Na, const double& w)
{
    
    int wholearraysize = (N+1)*(N+1);
    int innerarraysize = (N-1)*(N-1);
    
    // Initialize x;
    fill(input,input+wholearraysize,0.0);
    
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    // APR 27 3PM
    // TESTED
    // SUCCESSFUL
    if (N<=4)
    {
        // Exact solver
        
        int nx = N-1;
        int ny = N-1;
        
        // Eigen rhs_
        VectorXd rhs_(innerarraysize);
        int curp = 0;
        for(int j=1;j<=ny;j++)
        {
            for(int i=1;i<=nx;i++)
            {
                //////////////////////////
                rhs_(curp)= rhs[j*(N+1)+i];
                curp++;
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

        curp = 0;
        for(int j=1;j<=ny;j++)
        {
            for(int i=1;i<=nx;i++)
            {
                /////////////////////////////
                input[j*(N+1)+i] = ans_(curp);
                curp++;
            }
        }
        return;
    }
    // Exact solver completed.
    // Don't really want to optimize.
    // Although very poorly coded.
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    for(int nb=0;nb<Nb;nb++)
    {
        WeightedJacobiSweep(rhs,input, aux, N, w);
        swap(input,aux);
    }
    // Post: input: contains the updated x
    //       aux:   contains trash
    
    Axminusb(rhs,input,aux,N);
    // Post: input: not changed
    //       aux:   contains r=Ax-b;
    
    Coarsen(aux,N);
    // Post: aux: the first (N/2+1)^2 entries contain rcoarse
    //            the entries from (N/2+1)^2 contain trash
    
    int nextwholearraysize = (N/2+1)*(N/2+1);
    
    MGSolver(aux, aux+nextwholearraysize, aux+nextwholearraysize*2, N/2, Nb,Na,w);
    
    // Pre:  aux: the second (N/2+1)^2 entries contain xcoarse
    //           TODO: I know this is weird. Need to figure out
    Refine(aux, N);
    // Post: aux: contains xfine
    
    // x = x - xfine;
    // This seems very primitive.
    for(int i=0;i<wholearraysize;i++)
    {
        input[i] = input[i]-aux[i];
    }
    // Post: aux:   contains trash
    //       input: contains x
    
    for(int na=0;na<Na;na++)
    {
        WeightedJacobiSweep(rhs,input, aux, N, w);
        swap(input,aux);
    }
    // Post: input: contains the updated x
    //       aux:   contains trash
}

// errors: array of size ncycle+1
//         stores the max-norm of residuals after the 0,1,...,ncycle-th cycle
void MGClient(const double* rhs,const int& N, const int& Nb, const int& Na, const double& w,\
              double* errors,const int& ncycle)
{
    int wholearraysize = (N+1)*(N+1);
    
    vector<double> xvec(wholearraysize,0);
    double* x = xvec.data();
    double* r = new double[wholearraysize*3];
    double* xr = r+wholearraysize;
    double* aux = xr+wholearraysize;
    int i=0;
    while(true)
    {
        Axminusb(rhs,x,r,N);
        errors[i++]=maxnorm(r,wholearraysize);
        if (i>ncycle)
            break;
        MGSolver(r,xr,aux,N,Nb,Na,w);
        for(int j=0;j<wholearraysize;j++)
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
    
    int N = fData.m()-1;
    
    // Row major? Column major?
    const double* rhs = fData.Pointer();
    
    DTMutableDoubleArray errors(ncycle+1);
    
    MGClient(rhs, N, Nb, Na, w, errors.Pointer(), ncycle);
    
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    outputFile.Save(errors,"errors");
}