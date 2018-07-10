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

double maxnorm(const DTDoubleArray& v)
{
    long m=v.m();
    long n=v.n();
    double res = 0;
    for(long i=0;i<m;i++){
        for (long j=0;j<n;j++){
            res = max(res,abs(v(i,j)));
        }
    }
    return res;
}

void Axminusb(const DTDoubleArray& x,
              const DTDoubleArray& b,
              DTMutableDoubleArray& output)
{
    long N = x.m()-1;
    output = 0;
    for (long i=1;i<N;i++){
        for (long j=1;j<N;j++){
            output(i,j) = 4*x(i,j)-x(i+1,j)-x(i-1,j)-x(i,j+1)-x(i,j-1)-b(i,j);
        }
    }
}

DTMutableDoubleArray Axminusb(const DTDoubleArray& x, const DTDoubleArray& b)
{
    long N = x.m()-1;
    DTMutableDoubleArray r(N+1,N+1);
    Axminusb(x,b,r);
    return r;
}

void WeightedJacobiSweep(const DTDoubleArray& rhs,
                         const DTDoubleArray& input,
                         DTMutableDoubleArray& output,
                         const double& w)
{
    long N = input.m()-1;
    double wd4 = w/4;
    double oneMinusW = 1-w;
    
    output = 0;
    
    for(long i=1;i<N;i++){
        for(long j=1;j<N;j++){
            output(i,j) = oneMinusW*input(i,j) +
                    wd4*(input(i+1,j) +
                         input(i-1,j) +
                         input(i,j+1) +
                         input(i,j-1) +
                         rhs(i,j));
        }
    }
}

DTMutableDoubleArray Coarsen(const DTDoubleArray& input)
{
    long N = input.m()-1;
    long Nd2 = N/2;
    DTMutableDoubleArray output(Nd2+1,Nd2+1);
    
    output = 0;
    
    long i2,j2;
    for(long i=1;i<Nd2;i++){
        for(long j=1;j<Nd2;j++){
            i2 = i*2;
            j2 = j*2;
            output(i,j) = input(i2  ,j2)*0.5+(
                          input(i2+1,j2)+
                          input(i2-1,j2)+
                          input(i2  ,j2+1)+
                          input(i2  ,j2-1))*0.125;
        }
    }
    
    return output;
}

void Refine(const DTDoubleArray& input,
            DTMutableDoubleArray& output)
{
    long Nd2 = input.m()-1;
    output = 0;
    
    long i2,j2;
    
    for(long i=0;i<Nd2;i++){
        for(long j=0;j<Nd2;j++){
            i2 = i*2;
            j2 = j*2;
            
            output(i2,j2) = input(i,j);
            
            output(i2+1,j2) = (input(i,j)+
                               input(i+1,j))*0.5;
            
            output(i2,j2+1) = (input(i,j)+
                               input(i,j+1))*0.5;

            output(i2+1,j2+1) = (input(i,  j)+
                                 input(i+1,j)+
                                 input(i,  j+1)+
                                 input(i+1,j+1))*0.25;
        }
    }
}

DTMutableDoubleArray Refine(const DTDoubleArray& input)
{
    long Nd2 = input.m()-1;
    long N = Nd2*2;
    DTMutableDoubleArray output(N+1,N+1);
    
    Refine(input,output);
    
    return output;
}

DTMutableDoubleArray ExactSolver(const DTDoubleArray& rhs)
{
    
    int N = (int)rhs.m()-1;
    
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
            rhs_(it)= rhs(i,j);
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
    
    DTMutableDoubleArray output(N+1,N+1);
    output = 0;
    
    it = 0;
    for(int i=1;i<=ny;i++)
    {
        for(int j=1;j<=nx;j++)
        {
            output(i,j) = ans_(it);
            it++;
        }
    }
    return output;
}


DTMutableDoubleArray MGSolver(const DTDoubleArray& rhs,const int& Nb, const int& Na, const double& w)
{
    
    int N = (int)rhs.m()-1;
    
    // Exact solver
    if (N<=4)
        return ExactSolver(rhs);
    
    DTMutableDoubleArray x(N+1,N+1);
    
    // Initialize x;
    x = 0;
    
    DTMutableDoubleArray aux(N+1,N+1);
    aux = 0;
    
    for(int nb=0;nb<Nb/2;nb++)
    {
        WeightedJacobiSweep(rhs,x,aux,w);
        WeightedJacobiSweep(rhs,aux,x,w);
    }
    // Post: x  : contains the updated x
    //       aux: contains work array
    
    
    Axminusb(x,rhs,aux);
    // Post: x  : not changed
    //       aux: r=Ax-b;
    
    DTMutableDoubleArray rCoarse = Coarsen(aux);
    
    // The factor of 4
    // From lhs to rhs
    rCoarse *= 4;
    
    DTMutableDoubleArray xCoarse = MGSolver(rCoarse,Nb,Na,w);
    
    Refine(xCoarse,aux);
    // Post: aux: contains xfine
    
    // x = x - xfine;
    x -= aux;
     
    // Pre: x  : x
    //      aux: work array
    for(int na=0;na<Na/2;na++)
    {
        WeightedJacobiSweep(rhs,x,aux,w);
        WeightedJacobiSweep(rhs,aux,x,w);
    }
    // Post: x  : the updated x
    //       aux: work array
    
    return x;
}

DTMutableDoubleArray MGClient(const DTDoubleArray& rhs,double h,
                              const int& Nb, const int& Na, const double& w,
                              const int& ncycle)
{
    DTMutableDoubleArray errors(ncycle+1);
    
    int Nplus1 = (int)rhs.m();
    
    DTMutableDoubleArray x(Nplus1,Nplus1);
    DTMutableDoubleArray r(Nplus1,Nplus1);
    DTMutableDoubleArray xr(Nplus1,Nplus1);
    
    double h2 = h*h;
    
    Axminusb(x,rhs,r);
    errors(0) = maxnorm(r)/h2;
    
    for(int i=1;i<=ncycle;i++)
    {
        xr = MGSolver(r,Nb,Na,w);
        x -= xr;
        Axminusb(x,rhs,r);
        errors(i) = maxnorm(r)/h2;
    }
    return errors;
}

int main(int argc, const char *argv[])
{
    string inputName = "Input.mat";
    
#if DEBUG
    // Somehow Xcode needs full path.
    inputName = "/Users/wq/Desktop/SP2018/MATH662/Code/Final/Final/Input.mat";
#endif
    
    DTMatlabDataFile inputFile(inputName,DTFile::ReadOnly);
    
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
    
    DTMutableDoubleArray errors = MGClient(fData,h,Nb,Na,w,ncycle);
    
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    outputFile.Save(errors,"errors");
}