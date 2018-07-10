//
//  main.cpp
//  5.4
//
//  Created by 景思阳 on 6/5/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE_LIMIT = 50;

void fillArray(int arr[][2], int& sizeArr)
{
    cout << "Please enter less than " << SIZE_LIMIT << " numbers ended with 999" << " :\n";
    int count=0;
    do
    {
        cin >> arr[count][0];
        if (arr[count][0]==999)
            break;
        else count++;
    }
    while (count<SIZE_LIMIT);
    sizeArr = count;
}

// fillArray is correct

int repeat(const int value, const int currentPosition,  int arr[][2])
{
    for (int count=0;count<currentPosition;count++)
    {
        if (value == arr[count][0])
            return count;
    }
    return -1;
}

// repeat is correct


int findPosition(const int value, const int limit, const int arr[][2])
{
    for(int count = 0; count < limit; count++)
    {
        if (value <= arr[count][0])
            return count;
    }
    return limit;
}

// findposition is correct

void insertSort(const int currentPosition, const int sortArrSize, int arr[][2])
{
    int positionOfValue = findPosition(arr[currentPosition][0], sortArrSize, arr);
    for (int count=sortArrSize; count>positionOfValue;count--)
    {
        arr[count][0] = arr[count-1][0];
        arr[count][1] = arr[count-1][1];
    }
    arr[positionOfValue][0] = arr[currentPosition][0];
    arr[positionOfValue][1] = 1;
}

// insertSort is correct

void countRepeats(int& sizeArr, int arr[][2])
{
    int currentPosition=1;
    int pointer2=1;
    int positionRepeat;
    arr[0][1]=1;
    while (currentPosition<sizeArr)
    {
        positionRepeat = repeat(arr[currentPosition][0],pointer2,arr);
        if (positionRepeat+1)
        {
            arr[currentPosition][0]=0;
            arr[positionRepeat][1]++;
            currentPosition++;
        }
        else
        {
            insertSort(currentPosition, pointer2, arr);
            pointer2++;
            currentPosition++;
        }
    }
    sizeArr = pointer2;
}

void getOutput(const int sizeArr, int arr[][2]) // From big to small
{
    cout << setw(8) << "N" << setw(8) << "Count" << endl;
    for (int count=sizeArr-1; count>=0; count--)
    {
        cout << setw(8) << arr[count][0] << setw(8) << arr[count][1] << endl;
    }
}

int main()
{
    char ans;
    do
    {
        int arr[SIZE_LIMIT][2];
        int sizeArr;
        fillArray(arr, sizeArr);
        countRepeats(sizeArr, arr);
        getOutput(sizeArr,arr);
        cout << "Run again? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    
    return 0;
}
