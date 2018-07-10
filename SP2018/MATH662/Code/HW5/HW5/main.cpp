//
//  main.cpp
//  HW5
//
//  Created by apple on 3/3/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>

#include <thread>
#include <mutex>
#include <condition_variable>

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

#include <chrono>

using namespace std;
using namespace Eigen;
using namespace std::chrono;

double solveWithEigen(int dim)
{
    // RHS
    // Value of RHS does not significantly affect the running time.
    // Therefore just set to 1.
    int N = dim*dim;
    VectorXd rhs(N);
    for(int i=0;i<N;i++)
        rhs(i)=1;
    // AB
    SparseMatrix<double> AB(N,N);
    typedef Triplet<double> T;
    vector<T> tripletList;
    tripletList.reserve(3*N);
    for (int j=0;j<N;j++)
    {
        if (j>=dim)
            tripletList.push_back(T(j-dim,j,-1));
        if (j%dim!=0)
            tripletList.push_back(T(j-1,j,-1));
        tripletList.push_back(T(j,j,4));
    }
    AB.setFromTriplets(tripletList.begin(),tripletList.end());
    SimplicialLLT<SparseMatrix<double>,Eigen::Upper> solver;
    
    // Time from factorization to solving the system
    //cerr << "Eigen completes prework\n";
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    solver.compute(AB);
    //cerr << "Eigen completes factorization.\n";
    solver.solve(rhs);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //cerr << "Eigen completes computation.\n";
    duration<double> time_span = t2 - t1;
    return time_span.count();
}

double solveWithLP(int dim)
{
    // RHS
    // Value of RHS does not significantly affect the running time.
    // Therefore just set to 1.
    int N = dim*dim;
    vector<double> rhs(N,1);
    // AB
    
    int KD = dim;
    int NRHS = 1;
    int LDB = N;
    int info;
    int LDAB = KD+1;
    char UPLO = 'L';
    
    vector<int> IPIV(N);
    vector<double> AB(LDAB*N);
    int curp=0;
    for (int j=0;j<N;j++)
    {
        AB[curp++] = 4;
        AB[curp++] = (j+1)%dim==0?0:-1;
        for (int l=1;l<KD-1;l++)
        {
            AB[curp++] = 0;
        }
        AB[curp++] = -1;
    }
    
    // Time from factorization to solving the system
    //cerr << "LAPack completes prework\n";
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    dpbtrf_(&UPLO, &N, &KD, &AB[0], &LDAB, &info);
    //cerr << "LAPack completes factorization\n";
    dpbtrs_(&UPLO, &N, &KD, &NRHS, &AB[0], &LDAB, &rhs[0], &LDB, &info);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //cerr << "LAPack completes computation\n";
    duration<double> time_span = t2 - t1;
    return time_span.count();
}

//////////////////////////////////////////////
//********************************************
double solveWrapper(double wait,bool LP,int dim)
{
    mutex m;
    condition_variable cv;
    double retValue;
    
    thread t([&m, &cv, &retValue, &LP, &dim]()
    {
        if(LP)
            retValue = solveWithLP(dim);
        else
            retValue = solveWithEigen(dim);
        cv.notify_one();
    });
    
    t.detach();
    
    {
        std::unique_lock<std::mutex> l(m);
        if(cv.wait_for(l, duration<double>(wait)) == std::cv_status::timeout)
        {
            
            throw std::runtime_error("Timeout");
        }
    }
    
    return retValue;
}

int main(int argc, const char *argv[])
{
    string inputName = "Input.mat";
    
#if DEBUG
    // Somehow Xcode needs full path.
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
    printf("The first part complete.\n");
    
    ////////////////////////////////////////////////////////////////////////////////
    
    // set threshold
    double th = 20;
    if(argc>1)
        th=atoi(argv[1]);
    int ndims = 100;
    vector<int> dims(ndims);
    for(int i=0;i<ndims;i++)
        dims[i]=100*(i+1);
    
    printf("%5s %25s %25s\n","#","Banded Execution Time(s)","Sparse Execution Time(s)");
    
    for(int i=0;i<ndims;i++)
    {
        double sparse;
        try {
            sparse= solveWrapper(th,false,dims[i]);
        } catch (runtime_error& r) {
            sparse = th+1;
        }
        double banded;
        try {
            banded = solveWrapper(th,true,dims[i]);
        } catch (runtime_error& r) {
            banded = th+1;
        }
        if (sparse<th && banded<th)
            printf("%5d %25.7e %25.7e\n",dims[i],banded,sparse);
        else
        {
            printf("%5d ",dims[i]);
            if (banded<th)
                printf("%25.7e ",banded);
            else
                printf("%25s ","Not Feasible");
            if (sparse<th)
                printf("%25.7e\n",sparse);
            else
                printf("%25s\n","Not Feasible");
            //break;
            exit(0);
        }
    }
    
    return 0;
}