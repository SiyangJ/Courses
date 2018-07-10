//
//  main.cpp
//  5.3
//
//  Created by 景思阳 on 6/5/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int SIZE_LIMIT = 100;

double calculateMain(const double arr[], const int numUsed)
{
    double sum=0;
    for (int count=0;count<numUsed;count++)
        sum +=arr[count];
    return sum/numUsed;
}

double calculateSTDV(const double arr[], const int numUsed)
{
    double main = calculateMain(arr, numUsed);
    double sum=0;
    for (int count=0;count<numUsed;count++)
    {
        sum += pow(arr[count]-main,2);
    }
    return sqrt(sum/numUsed);
}

int main()
{
    int size = 5;
    double arr[] = {3,3,3,3,3};
    cout << calculateSTDV(arr, size) << endl;
    return 0;
}
