// The code from Alejandro A. Ortiz Bernardin
// see http://groups.google.com/group/matrixprogramming/t/7326abe5ca51242
//
// g++ -c inverse.cpp
// g++ -o inverse inverse.o L./ -llapack -lf77blas -lcblas -latlas -lg2c
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern "C" int dpotrf_(char *uplo, int *n, double *a, int *lda, int *info);
extern "C" int dpotri_(char *uplo, int *n, double *a, int *lda, int *info);

int main()
{
    int n = 2;
    int info;
    char uplo = 'u';
    
    // dpotrf_ and dpotri_ expect a real symmetric positive definite matrix
    // in a vector ordered by columns
    vector<double> a(n*n);
    a[0] = 1;
    a[1] = 1;
    a[2] = 1;
    a[3] = 1.000000001;
    //"a" is an ill-conditioned matrix and its exact inverse is:
    // [ 1e+9  -1e+9]
    // [-1e+9   1e+9]
    
    // compute Cholesky factorization
    dpotrf_(&uplo,&n,&a[0],&n,&info);
    if (info != 0) cout << "Error in dpotrf_(): Flag is " << info << endl;
    
    // use Cholesky factorization to compute the inverse
    dpotri_(&uplo,&n,&a[0],&n,&info);
    if (info != 0) cout << "Error in dpotri_(): Flag is " << info << endl;
    
    // dpotri_ only works with what we have specified in 'uplo'.
    // In this case the upper part of the matrix. Nothing is done
    // to the lower part. Therefore, since the matrix is symmetric
    // we may manually copy the upper part into the lower part
    
    // copy "a" into a matrix and, at the same time, copy the upper
    // part into the lower part
    vector< vector<double> > ainv(n, vector<double>(n));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ainv[j][i] = a[k];
            ainv[i][j] = ainv[j][i];
            k++;
        }
    }
    
    // print out the inverse
    cout << endl << "The computed inverse is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ainv[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
