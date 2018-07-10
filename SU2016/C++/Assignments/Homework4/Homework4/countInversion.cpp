//
//  countInversion.cpp
//  Homework4
//
//  Created by apple on 8/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
using namespace std;
int mergeSortPlusCounting(int a[], int n)
{
    int count=0;
    if (n<=1)
        return 0;
    int n1=n/2, n2=n-n1;
    count+=mergeSortPlusCounting(a,n1);
    count+=mergeSortPlusCounting(a+n1,n2);
    int* res=new int[n];
    int* sechalf=a+n1;
    int i=0, j=0, k=0;
    while (i<n1 || j<n2)
    {
        if (i==n1) res[k++]=sechalf[j++];
        else if (j==n2) res[k++]=a[i++];
        else if (a[i]<=sechalf[j]) res[k++]=a[i++];
        else
        {
            res[k++]=sechalf[j++];
            count+=(n1-i);
        }
    }
    for (int i=0; i<n; i++)
    {
        a[i]=res[i];
    }
    delete [] res;
    return count;
}
int countInversions(int a[], int n)
{
    int* b=new int[n];
    for (int i=1; i<n; i++)
    {
        b[i]=a[i];
    }
    int res=mergeSortPlusCounting(b,n);
    delete [] b;
    return res;
}

int countInversions2(int a[], int n)
{
    int count = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (a[j]<a[i]) count++;
        }
    }
    return count;
}

int main()
{
    int a[5]={5,4,3,2,1};
    cout << countInversions2(a, 5) << endl;
    for (int i=0; i<5; i++)
        cout << a[i] << endl;
}
