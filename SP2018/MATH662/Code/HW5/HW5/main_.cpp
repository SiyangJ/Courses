//
//  main.cpp
//  HW5
//
//  Created by apple on 3/3/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>
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

#include <math.h>
#include <vector>

using namespace std;
using namespace Eigen;

int main(int argc, const char *argv[])
{
    string inputName = "Input.mat";
    
#if DEBUG
    inputName = "/Users/wq/Desktop/SP2018/MATH662/Code/HW5/HW5/Input.mat";
#endif
    
    DTSetArguments(argc,argv);
    
    DTMatlabDataFile inputFile(inputName,DTFile::ReadOnly);
    // Read in the input variables.
    
    DTMesh2D f;
    Read(inputFile,"f",f);
    DTFunction2D g;
    Read(inputFile,"g",g);
        
    DTMesh2DGrid grid = f.Grid();
    double h = grid.dx();
    double h2 = h*h;
    DTDoubleArray fData = f.DoubleData();
    
    int nx = fData.m()-2;
    int ny = fData.n()-2;
    
    //int KU = nx,KL=nx;
    int KD = nx;
    int N = nx*ny;
    int NRHS = 1;
    int LDB = N;
    int info;
    
    vector<int> IPIV(N);
    
    double xzero = grid.Origin().x;
    double yzero = grid.Origin().y;
    
    // LAPACK rhs
    vector<double> rhs(N);
    int curp=0;
    
    for(int j=0;j<ny;j++)
    {
        for(int i=0;i<nx;i++)
        {
            rhs[curp]= -h2*fData(i+1,j+1);
            if (i==0)
            {
                rhs[curp] += g(xzero,yzero+(j+1)*h);
            }
            else if (i==nx-1)
            {
                rhs[curp] += g(xzero+(nx+1)*h,yzero+(j+1)*h);
            }
            if (j==0)
            {
                rhs[curp] += g(xzero+(i+1)*h,yzero);
            }
            else if (j==ny-1)
            {
                rhs[curp] += g(xzero+(i+1)*h,yzero+(ny+1)*h);
            }
            curp++;
        }
    }
    
    // Eigen rhs_
    VectorXd rhs_(N);
    // TODO
    // Need to optimize the initialization
    curp = 0;
    for(int j=0;j<ny;j++)
    {
        for(int i=0;i<nx;i++)
        {
            rhs_(curp)= -h2*fData(i+1,j+1);
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
    
    // LAPACK AB
    int LDAB = KD+1;
    vector<double> AB(LDAB*N);
    
    curp=0;
    for (int j=0;j<N;j++)
    {
        AB[curp++] = 4;
        AB[curp++] = (j+1)%nx==0?0:-1;
        for (int l=1;l<KD-1;l++)
        {
            AB[curp++] = 0;
        }
        AB[curp++] = -1;
    }
    
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
        /*
        if ((j+1)%nx!=0)
            tripletList.push_back(T(j+1,j,-1));
        if (j<N-nx)
            tripletList.push_back(T(j+nx,j,-1));
         */
    }
    AB_.setFromTriplets(tripletList.begin(),tripletList.end());
    SimplicialLLT<SparseMatrix<double>,Eigen::Upper> solver;
    solver.compute(AB_);
    
    // AB completed
    
    char UPLO = 'L';
    
    dpbtrf_(&UPLO, &N, &KD, &AB[0], &LDAB, &info);
    dpbtrs_(&UPLO, &N, &KD, &NRHS, &AB[0], &LDAB, &rhs[0], &LDB, &info);
    
    VectorXd ans_ = solver.solve(rhs_);
    
    // Write the output.
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    
    // Output from computation
    // outputFile.Save(computed,"Var");
    
    DTMutableDoubleArray Var1(nx+2,ny+2);
    DTMutableDoubleArray Var2(nx+2,ny+2);

    curp = 0;
    for (int j=1;j<=ny;j++)
    {
        for (int i=1;i<=nx;i++)
        {
            Var1(i,j)=rhs[curp];
            Var2(i,j)=ans_(curp++);
        }
    }
    for (int i=0;i<=nx+1;i++)
    {
        Var1(i,0) = g(xzero+i*h,yzero);
        Var1(i,ny+1) = g(xzero+i*h,yzero+(ny+1)*h);
        Var2(i,0) = g(xzero+i*h,yzero);
        Var2(i,ny+1) = g(xzero+i*h,yzero+(ny+1)*h);
    }
    for (int j=1;j<=ny;j++)
    {
        Var1(0,j) = g(xzero,yzero+j*h);
        Var1(nx+1,j) = g(xzero+(nx+1)*h,yzero+j*h);
        Var2(0,j) = g(xzero,yzero+j*h);
        Var2(nx+1,j) = g(xzero+(nx+1)*h,yzero+j*h);
    }
    
    outputFile.Save(Var1,"Var1");
    outputFile.Save(Var2,"Var2");
    outputFile.Save(info,"INFO");
    
    // The following variables are only needed if you use DataTank to read the output
    outputFile.Save("Array","Seq_Var");
    
    return 0;
}