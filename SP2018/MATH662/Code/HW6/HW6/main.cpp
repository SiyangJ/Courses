//
//  main.cpp
//  HW6
//
//  Created by apple on 4/4/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>
#include <stdio.h>

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

// Compute the max norm of the difference between
// the solutions of the exact solver and the iterative solver
double errorNorm(VectorXd exact,DTMutableDoubleArray iter)
{
    int m=iter.m()-1;
    int n=iter.n()-1;
    double maxErr=0;
    int curp=0;
    for(int j=1;j<n;j++)
    {
        for(int i=1;i<m;i++)
        {
            maxErr = max(abs(exact(curp)-iter(i,j)),maxErr);
            curp++;
        }
    }
    return maxErr;
}

int main(int argc, const char *argv[])
{
    string inputName = "Input.mat";
    
#if DEBUG
    // Somehow Xcode needs full path.
    inputName = "/Users/wq/Desktop/SP2018/MATH662/Code/HW6/HW6/Input.mat";
#endif
    
    DTMatlabDataFile inputFile(inputName,DTFile::ReadOnly);
    // Read in the input variables.
    
    DTMesh2D f;
    Read(inputFile,"f",f);
    DTFunction2D g;
    Read(inputFile,"g",g);
    
    DTMesh2D u0;
    
    Read(inputFile,"u0",u0);
    
    double omega = inputFile.ReadNumber("omega");
    int nIter = inputFile.ReadNumber("howMany");
    int stride = inputFile.ReadNumber("stride");
    
    DTMesh2DGrid grid = f.Grid();
    double h = grid.dx();
    double h2 = h*h;
    DTDoubleArray fData = f.DoubleData();
    
    // Compute the -h^2 factored f
    fData = -h2*fData;
    
    int nx = fData.m()-2;
    int ny = fData.n()-2;
    
    int N = nx*ny;
    
    double xzero = grid.Origin().x;
    double yzero = grid.Origin().y;
    
    ////////////////////////////////////////////////////////////////////////
    // Exact Solver Part
    
    // Eigen rhs_
    VectorXd rhs_(N);
    // TODO
    // Need to optimize the initialization
    int curp = 0;
    for(int j=0;j<ny;j++)
    {
        for(int i=0;i<nx;i++)
        {
            rhs_(curp)= fData(i+1,j+1);
            if (i==0)
            {
                rhs_(curp) += g(xzero,yzero+(j+1)*h);
            }
            else if (i==nx-1)
            {
                rhs_(curp) += g(xzero+(nx+1)*h,yzero+(j+1)*h);
            }
            if (j==0)
            {
                rhs_(curp) += g(xzero+(i+1)*h,yzero);
            }
            else if (j==ny-1)
            {
                rhs_(curp) += g(xzero+(i+1)*h,yzero+(ny+1)*h);
            }
            curp++;
        }
    }
    // RHS completed
    
    // Eigen AB_
    SparseMatrix<double> AB_(N,N);
    typedef Triplet<double> T;
    vector<T> tripletList;
    //tripletList.reserve(5*N);
    tripletList.reserve(3*N);
    // TODO
    // Optimize the storage allocations
    for (int j=0;j<N;j++)
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
    
    ////////////////////////////////////////////////////////////////////////
    // Iterative Solver Part
    
    // Write the output.
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    DTMatlabDataFile errorFile("Erros.mat",DTFile::NewReadWrite);
    DTSeriesMesh2D computed(outputFile,"Var");
    DTMutableDoubleArray error(nIter/stride+1,1);
    
    DTMutableDoubleArray u = u0.DoubleData().Copy();
    
    // Change the boundary values of intitial u to g;
    
    for(int j=0;j<ny+2;j++)
    {
        u(0,j) = g(xzero,yzero+j*h);
        u(nx+1,j) = g(xzero+(nx+1)*h,yzero+j*h);
    }
    
    for(int i=1;i<=nx;i++)
    {
        u(i,0) = g(xzero+i*h,yzero);
        u(i,ny+1) = g(xzero+i*h,yzero+(ny+1)*h);
    }

    int t = 0;
    computed.Add(DTMesh2D(grid,u),t);
    error(0) = errorNorm(ans_,u);
    
    // Iterative steps
    for(t=1;t<=nIter;t++)
    {
        // Control for red or black
        // rb=0:red | rb=1:black
        for(int rb=0;rb<=1;rb++)
        {
            // GS(omega) sweep for the interior points
            for(int i=1;i<=nx;i++)
            {
                for(int j=1;j<=ny;j++)
                {
                    // red:2|i+j ; black:2|i+j+1
                    if((i+j+rb)%2==0)
                    {
                        u(i,j)=(1-omega)*u(i,j)+omega*(u(i-1,j)+u(i+1,j)+u(i,j-1)+u(i,j+1)+fData(i,j))/4;
                    }
                }
            }
        }
        
        if(t%stride==0)
        {
            computed.Add(DTMesh2D(grid,u),t);
            error(t/stride) = errorNorm(ans_,u);
        }
    }
    
    errorFile.Save(error,"errors");
    
    return 0;
}