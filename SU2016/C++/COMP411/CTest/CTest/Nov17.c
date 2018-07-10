//
//  Nov17.c
//  CTest
//
//  Created by apple on 11/16/17.
//  Copyright © 2017 UNC. All rights reserved.
//

/*
#include <stdio.h>

int a[] = {30, 40, 50, 10, 20};

int compare(int a, int b)
{
    return a < b;
}

int min(int array[], int size)
{
    int i;
    int minIndex = 0;
    int minValue = array[0];
    
    for (i = 1; i < size; i++)
        if (compare(array[i], minValue)) {
            minValue = array[i];
            minIndex = i;
        }
    return minIndex;
}

void selectionSort(int array[], int N)
{
    int i, j, t;
    int *p = array;
    
    for (i = 0; i < N-1; i++) {
        j = min(p,N-i);
        t = array[i];
        array[i] = array[i+j];
        array[i+j] = t;
        p += 1;
    }
}

int main( )
{
    int i;
    
    for (i = 0; i < 5; i++)
        printf("%d: %d\n", i, a[i]);
    printf("\n");
    
    selectionSort(a, 5);
    
    for (i = 0; i < 5; i++)
        printf("%d: %d\n", i, a[i]);
    printf("\n");
}
*/

/*
#include <stdio.h>

int a[] = {30, 40, 50, 10, 20};

int myCompare(int a, int b)
{
    return a > b;
}

int myMin(int array[], int size, int (*comp)(int,int))
{
    int i;
    int minIndex = 0;
    int minValue = array[0];
    
    for (i = 1; i < size; i++)
        if (comp(array[i], minValue)) {
            minValue = array[i];
            minIndex = i;
        }
    return minIndex;
}

void mySelectionSort(int array[], int N, int (*comp)(int,int))
{
    int i, j, t;
    int *p = array;
    
    for (i = 0; i < N-1; i++) {
        j = myMin(p,N-i,comp);
        t = array[i];
        array[i] = array[i+j];
        array[i+j] = t;
        p += 1;
    }
}

int main( )
{
    int i;
    
    for (i = 0; i < 5; i++)
        printf("%d: %d\n", i, a[i]);
    printf("\n");
    
    mySelectionSort(a, 5,myCompare);
    
    for (i = 0; i < 5; i++)
        printf("%d: %d\n", i, a[i]);
    printf("\n");
}
*/

#include <stdio.h>

typedef int (*int2_1) (int,int);

int a[] = {30, 40, 50, 10, 20};

int myCompare(int a, int b)
{
    return a > b;
}

int myMin(int array[], int size, int2_1 comp)
{
    int i;
    int minIndex = 0;
    int minValue = array[0];
    
    for (i = 1; i < size; i++)
        if (comp(array[i], minValue)) {
            minValue = array[i];
            minIndex = i;
        }
    return minIndex;
}

void mySelectionSort(int array[], int N, int2_1 comp)
{
    int i, j, t;
    int *p = array;
    
    for (i = 0; i < N-1; i++) {
        j = myMin(p,N-i,comp);
        t = array[i];
        array[i] = array[i+j];
        array[i+j] = t;
        p += 1;
    }
}

int main( )
{
    int i;
    
    for (i = 0; i < 5; i++)
        printf("%d: %d\n", i, a[i]);
    printf("\n");
    
    mySelectionSort(a, 5,myCompare);
    
    for (i = 0; i < 5; i++)
        printf("%d: %d\n", i, a[i]);
    printf("\n");
}