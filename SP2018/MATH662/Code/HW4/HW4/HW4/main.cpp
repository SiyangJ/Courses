//
//  main.cpp
//  HW4
//
//  Created by apple on 2/26/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>

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

DTDoubleArray FortranVectorToDTArray(vector<double> A, ssize_t m)
{
    ssize_t n = A.size()/m;
    DTMutableDoubleArray ret(m,n);
    for (ssize_t j=0;j<n;j++)
    {
        for (ssize_t i=0;i<m;i++)
        {
            ret(i,j)=A[j*m+i];
        }
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    DTSetArguments(argc,argv);
    
    DTMatlabDataFile inputFile("Input.mat",DTFile::ReadOnly);
    // Read in the input variables.
    
    DTMesh2D f;
    Read(inputFile,"f",f);
    DTFunction2D g;
    Read(inputFile,"g",g);
    
    //g.pinfo();
    
    DTMesh2DGrid grid = f.Grid();
    double h = grid.dx();
    double h2 = h*h;
    DTDoubleArray fData = f.DoubleData();
    
    int nx = fData.m()-2;
    int ny = fData.n()-2;
    
    int KU = nx,KL=nx;
    int LDAB = 2*KL+KU+1;
    int N = nx*ny;
    int NRHS = 1;
    int LDB = N;
    int info;
    
    vector<double> rhs(N);
    vector<int> IPIV(N);
    
    double xzero = grid.Origin().x;
    double yzero = grid.Origin().y;
    
    //cerr<<xzero<<' '<<yzero<<' '<<h<<endl;
    
    double curp=0;
    
    for(int j=0;j<ny;j++)
    {
        for(int i=0;i<nx;i++)
        {
            rhs[curp]= h2*fData(i+1,j+1);
            if (i==0)
            {
                rhs[curp] -= g(xzero,yzero+(j+1)*h);
            }
            else if (i==nx-1)
            {
                rhs[curp] -= g(xzero+(nx+1)*h,yzero+(j+1)*h);
            }
            if (j==0)
            {
                rhs[curp] -= g(xzero+(i+1)*h,yzero);
            }
            else if (j==ny-1)
            {
                rhs[curp] -= g(xzero+(i+1)*h,yzero+(ny+1)*h);
            }
            curp++;
        }
    }
    
    // RHS completed
    vector<double> AB(LDAB*N);
    
    curp=0;
    for (int j=0;j<N;j++)
    {
        curp+=KL;
        AB[curp++] = 1;
        for (int l=1;l<KU-1;l++)
        {
            AB[curp++] = 0;
        }
        AB[curp++] = j%nx==0?0:1;
        AB[curp++] = -4;
        AB[curp++] = (j+1)%nx==0?0:1;
        for (int l=1;l<KL-1;l++)
        {
            AB[curp++] = 0;
        }
        AB[curp++] = 1;
    }
    
    // AB completed
    
    dgbsv_(&N,&KL,&KU,&NRHS,&AB[0],&LDAB,&IPIV[0],&rhs[0],&LDB,&info);
    
    // Write the output.
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    
    // Output from computation
    // outputFile.Save(computed,"Var");
    
    DTMutableDoubleArray Var(nx+2,ny+2);
    curp = 0;
    for (int j=1;j<=ny;j++)
    {
        for (int i=1;i<=nx;i++)
        {
            Var(i,j)=rhs[curp++];
        }
    }
    for (int i=0;i<=nx+1;i++)
    {
        Var(i,0) = g(xzero+i*h,yzero);
        Var(i,ny+1) = g(xzero+i*h,yzero+(ny+1)*h);
    }
    for (int j=1;j<=ny;j++)
    {
        Var(0,j) = g(xzero,yzero+j*h);
        Var(nx+1,j) = g(xzero+(nx+1)*h,yzero+j*h);
    }
    
    outputFile.Save(Var,"Var");
    outputFile.Save(info,"INFO");
    
    // The following variables are only needed if you use DataTank to read the output
    outputFile.Save("Array","Seq_Var");
    
    return 0;
}