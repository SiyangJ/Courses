//
//  main.cpp
//  5.5
//
//  Created by 景思阳 on 6/5/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

const int SIZE_LIMIT = 20;

void getInput(char arr[], int& maxCount)
{
    cout << "Please enter up to " << SIZE_LIMIT << " numbers ended with A:\n";
    int count = -1;
    while (count+1<SIZE_LIMIT)
    {
        count++;
        cin >> arr[count];
        if (arr[count] == 'A')
        {
            arr[count--] = '0';
            break;
        }
    }
    maxCount = count;
    for (int count=SIZE_LIMIT-1; count>maxCount;count--)
    {
        arr[count]='0';
    }
}

// Untested

void reverseOrder(const int maxCount, char arr[])
{
    int limitCount = (maxCount-1)/2;
    char temp;
    for (int count=0;count<=limitCount;count++)
    {
        temp = arr[count];
        arr[count] = arr[maxCount-count];
        arr[maxCount-count] = temp;
    }
}

int c2i(char value)
{
    return value-48;
}

char i2c(int value)
{
    return value+48;
}

int max(int var1, int var2)
{
    if (var1>=var2)
        return var1;
    else
        return var2;
}

void handAddition(char arr1[], char arr2[], int& maxCount1, int maxCount2)
{
    maxCount1 = max(maxCount1,maxCount2);
    int value;
    bool temp = 0;
    for (int count=0;count<=maxCount1;count++)
    {
        value = arr1[count] + arr2[count] + temp - 48*2;
        temp = value/10;
        arr1[count] = value%10+48;
    }
    if (temp)
    {
        if (maxCount1 == SIZE_LIMIT)
        {
            cout << "Error: integer overflow!\n";
        }
        else
        {
            arr1[++maxCount1] = 1+48;
        }
    }
}

void getOutput(char arr[], int maxCount)
{
    for (int count=maxCount; count>=0; count--)
    {
        cout << arr[count];
    }
    cout << endl;
}

int main()
{
    char ans = 'y';
    do
    {
        char arr1[SIZE_LIMIT], arr2[SIZE_LIMIT];
        int maxCount1, maxCount2;
        getInput(arr1, maxCount1);
        reverseOrder(maxCount1, arr1);
        getInput(arr2, maxCount2);
        reverseOrder(maxCount2, arr2);
        handAddition(arr1, arr2, maxCount1, maxCount2);
        getOutput(arr1, maxCount1);
        cout << "Run again? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    
    return 0;
}
