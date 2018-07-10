//
//  main.c
//  CTest
//
//  Created by apple on 10/8/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <stdio.h>

/*
int a[] = {30, 40, 50, 10, 20};
int *p[] = {a+4, a+3, a+2, a+1, a};

int min(int array[], int size) {
    int i;
    int minIndex = 0;
    int minValue = array[0];
    for (i = 1; i < size; i++)
        if (array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    return minIndex;
}

void selectionSort(int array[], int N) {
    int i, j, t;
    int *p = array;
    for (i = 0; i < N-1; i++) {
        j = min(p,N-i);
        t = array[i];
        array[i] = array[i+j];
        array[i+j] = t;
        p++;
    }
}

int main( ) {
    int i;
    selectionSort(a, 5);

    for (i = 0; i < 5; i++)
        printf("%d: %d, %d, %d, %d\n", i, a[i], (int) (p[i] - a), (int) p[i] - (int) a, *p[i]);
}
*/

/*

// Checkoff 3
int a[] = {30, 40, 50, 10, 20};
int *p[] = {a+4, a+3, a+2, a+1, a};

int min(int *array[], int size) {
    int i;
    int minIndex = 0;
    int *minValue = array[0];
    for (i = 1; i < size; i++)
        if (*array[i] < *minValue) {
            minValue = array[i];
            minIndex = i;
        }
    return minIndex;
}

void selectionSort(int *array[], int N) {
    int i, j, *t;
    int **p = array;
    for (i = 0; i < N-1; i++) {
        j = min(p,N-i);
        t = array[i];
        array[i] = array[i+j];
        array[i+j] = t;
        p++;
    }
}

int main( ) {
    int i;
    selectionSort(p, 5);
    
    for (i = 0; i < 5; i++)
        printf("%d: %d, %d, %d, %d\n", i, a[i], (int) (p[i] - a), (int) p[i] - (int) a, *p[i]);
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main( ) {
    int max = 10;
    char* str = (char*)malloc(10);
    getline(&str,&max,stdin);
    printf("%s",str);
    
}

