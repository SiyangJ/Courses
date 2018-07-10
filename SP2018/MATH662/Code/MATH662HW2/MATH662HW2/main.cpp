//
//  main.cpp
//  MATH662HW2
//
//  Created by apple on 2/2/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

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

using namespace std;

extern "C" void dgetrf_(int* m,int*n,double*A,int*lda,int*IPIV,int*info);
extern "C" void dgecon_(char*norm, int*n, double*A, int*lda, double*anorm, double*rcond, double*work, int*iwork,int*info);
extern "C" void dgetrs_(char* trans,int* n,int* nrhs,double* A,int* lda,int* ipiv,double* B,int* ldb,int* info);
extern "C" void dgerfs_(char*trans, int*n, int*nrhs, double*A, int*lda, double*af, int*ldaf, int*IPIV, double*B, int*ldb, double*x, int*ldx, double*ferr, double*berr, double*work, int*iwork, int*info);

vector<double> DTArrayToFortranVector(DTDoubleArray A)
{
    ssize_t m = A.m();
    ssize_t n = A.n();
    
    vector<double> ret(m*n);
    
    for (ssize_t j=0;j<n;j++)
    {
        for (ssize_t i=0;i<m;i++)
        {
            ret[j*m+i] = A(i,j);
        }
    }
    return ret;
}

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

DTIntArray FortranVectorToDTIntArray(vector<int> A,ssize_t m)
{
    ssize_t n = A.size()/m;
    DTMutableIntArray ret(m,n);
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
    DTDoubleArray A = inputFile.ReadDoubleArray("A");
    DTDoubleArray B = inputFile.ReadDoubleArray("B");
    
    char trans='N';
    char norm;
    int m=A.m();
    int n=A.n();
    int lda=A.m();
    int lda2=m;
    int nrhs=B.n();
    int ldb=B.m();
    int ldb2=lda;
    double anorm;
    double KappaOne;
    double KappaInf;
    
    int info;
    
    vector<double> Avec = DTArrayToFortranVector(A);
    vector<double> AOrig(Avec);
    vector<double> Bvec = DTArrayToFortranVector(B);
    vector<double> BOrig(Bvec);
    vector<int> IPIV(n);
    
    vector<double> ferr(nrhs);
    vector<double> berr(nrhs);
    
    vector<double> work(4*n);
    vector<int> iwork(n);
    
    // The computation.
    norm='1';
    dgecon_(&norm,&n,&Avec[0],&lda,&anorm,&KappaOne,&work[0],&iwork[0],&info);
    norm='I';
    dgecon_(&norm,&n,&Avec[0],&lda,&anorm,&KappaInf,&work[0],&iwork[0],&info);
    dgetrf_(&m,&n,&Avec[0],&lda,&IPIV[0],&info);
    dgetrs_(&trans,&n,&nrhs,&Avec[0],&lda,&IPIV[0],&Bvec[0],&ldb,&info);
    
    DTDoubleArray x = FortranVectorToDTArray(Bvec,ldb);
    
    dgerfs_(&trans,&n,&nrhs,&AOrig[0],&lda2,&Avec[0],&lda,&IPIV[0],&BOrig[0],&ldb2,
            &Bvec[0],&ldb,&ferr[0],&berr[0],&work[0],&iwork[0],&info);
    DTDoubleArray ximproved = FortranVectorToDTArray(Bvec,ldb);
    DTDoubleArray LU = FortranVectorToDTArray(Avec,lda);
    DTIntArray P = FortranVectorToDTIntArray(IPIV,1);
    DTDoubleArray FERR = FortranVectorToDTArray(ferr,1);
    DTDoubleArray BERR = FortranVectorToDTArray(berr,1);
    
    // Write the output.
    DTMatlabDataFile outputFile("Output.mat",DTFile::NewReadWrite);
    
    // Output from computation
    // outputFile.Save(computed,"Var");
    
    outputFile.Save(LU,"LU");
    outputFile.Save(P,"P");
    outputFile.Save(x,"x");
    outputFile.Save(KappaOne,"KappaOne");
    outputFile.Save(KappaInf,"KappaInf");
    outputFile.Save(ximproved,"ximproved");
    outputFile.Save(FERR,"FERR");
    outputFile.Save(BERR,"BERR");
    outputFile.Save(info,"info");
    
    // The following variables are only needed if you use DataTank to read the output
    outputFile.Save("Array","Seq_Var");
    
    // The execution time.
    outputFile.Save("Real Number","Seq_ExecutionTime");
    
    // The errors.
    DTSaveError(outputFile,"ExecutionErrors");
    outputFile.Save("StringList","Seq_ExecutionErrors");
    
    return 0;
}