//
//  mergeSort.cpp
//  Homework4
//
//  Created by apple on 8/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
using namespace std;
void mergeSort(int a[], int n)
{
    if (n<=1)
        return;
    int n1=n/2, n2=n-n1;
    mergeSort(a,n1);
    mergeSort(a+n1,n2);
    int* res=new int[n];
    int* sechalf=a+n1;
    int i=0, j=0, k=0;
    while (i<n1 || j<n2)
    {
        if (i==n1) res[k++]=sechalf[j++];
        else if (j==n2) res[k++]=a[i++];
        else if (a[i]<=sechalf[j]) res[k++]=a[i++];
        else res[k++]=sechalf[j++];
    }
    for (int i=0; i<n; i++)
        a[i]=res[i];
    delete [] res;
}

int main()
{
    int n=5;
    int a[5]={9,8,7,5,6};
    mergeSort(a, n);
    for (int i=0;i<n;i++)
        cout << a[i] << endl;
}
