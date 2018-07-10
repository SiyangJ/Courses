//
//  Oct6Question4.c
//  COMP411
//
//  Created by apple on 10/6/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <stdio.h>

#define N 8
#define SWAP(X,Y) {register int t = X; X = Y; Y = t;}

int a[N] = { 6, 5, 8, 4, 2, 7, 1, 3 };

int _n = 0;

void quicksort(int array[], int low, int high) {
    _n++;
    printf("Number: %d\narray:\n",_n);
    for (int i=0;i<N;i++)
    {
        printf("%d",array[i]);
    }
    printf("low=%d high=%d\n",low,high);
    int pivot,i,j,k;
    if (low < high) {
        k = (low+high)>>1;
        SWAP(array[low],array[k]);
        pivot = array[low];
        i = low+1;
        j = high;
        while (i <= j) {
            while ((i <= high) && (array[i] <= pivot))
                i++;
            while ((j >= low) && (array[j] > pivot))
                j--;
            if (i < j)
                SWAP(array[i],array[j]);
        }
        SWAP(array[low],array[j]);
        quicksort(array, low, j-1);
        quicksort(array, j+1, high);
    }
}

int main() {
    quicksort(a,0,N-1);
    printf("Total number of calls: %d\n",_n);
}