//
//  main.cpp
//  HW3
//
//  Created by apple on 2/18/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#define ONLINUX true

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

#include <math.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    DTSetArguments(argc,argv);
    
    DTMatlabDataFile inputFile("Input.mat",DTFile::ReadOnly);
    // Read in the input variables.
    DTDoubleArray xy = inputFile.ReadDoubleArray("xy");
    DTDoubleArray x = inputFile.ReadDoubleArray("x");
    
    int N = xy.n()-2;
    
    vector<double> dy(N+1);
    vector<double> dx(N+1);
    
    for(int i=0;i<=N;i++)
    {
        dy[i] = xy(1,i+1)-xy(1,i);
        dx[i] = xy(0,i+1)-xy(0,i);
    }
    
    int LDB = N;
    int NRHS = 1;
    int INFO;
    
    vector<double> DL(N-1);
    vector<double> DU(N-1);
    vector<double> D(N);
    vector<double> B(N+2);
    
    for(int i=0;i<N-1;i++)
    {
        DL[i] = dx[i+1];
        DU[i] = DL[i];
        D[i] = 2*(dx[i]+dx[i+1]);
    }
    
    D[N-1] = 2*(dx[N-1]+dx[N]);

    for (int i=1;i<=N;i++)
    {
        B[i] = 6*(dy[i]/dx[i]-dy[i-1]/dx[i-1]);
    }
    
    dgtsv_(&N,&NRHS,&DL[0],&D[0],&DU[0],&B[1],&LDB,&INFO);
    
    B[0]=0;
    B[N+1]=0;
    
    int m=x.n();
    DTMutableDoubleArray y(1,m);
    int last=-1;
    int j=0;
    double a,b,c,d,diff1,diff2;
    for(int i=0;i<m;i++)
    {
        for(;j<N;j++)
        {
            if(x(i)<=xy(0,j+1))
                break;
        }
        if(j!=last)
        {
            last=j;
            a=B[j]/6/dx[j];
            b=B[j+1]/6/dx[j];
            c=xy(1,j+1)/dx[j]-dx[j]/6*B[j+1];
            d=xy(1,j)/dx[j]-dx[j]/6*B[j];
        }
        diff1=xy(0,j+1)-x(i);
        diff2=x(i)-xy(0,j);
        y(i)=a*pow(diff1,3)+b*pow(diff2,3)+c*diff2+d*diff1;
    }
    
    
    // Write the output.
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    
    // Output from computation
    // outputFile.Save(computed,"Var");
    
    outputFile.Save(y,"y");
    
    // The following variables are only needed if you use DataTank to read the output
    outputFile.Save("Array","Seq_Var");
    
    return 0;
}