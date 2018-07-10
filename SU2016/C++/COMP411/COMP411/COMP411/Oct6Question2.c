//
//  Oct6Question2.c
//  COMP411
//
//  Created by apple on 10/6/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <stdio.h>

#define N 12
#define SWAP(X,Y) {register int t = X; X = Y; Y = t;}

int a[N] = { 6, 5, 8, 4, 2, 7, 1, 3, 9, 10, 11, 12};

int _n = 0;

int min(int array[], int size) {
    int i;
    int minIndex = 0;
    int minValue = array[0];
    for (i = 1; i < size; i++)
    {
        _n++;
        if (array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int i, j;
    int *p = a;
    for (i = 0; i < N-1; i++) {
        j = min(p,N-i);
        SWAP(a[i],a[i+j]);
        p++;
    }
    printf("%d\n",_n);
}