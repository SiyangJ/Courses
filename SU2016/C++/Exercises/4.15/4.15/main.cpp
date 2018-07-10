//
//  main.cpp
//  4.15
//
//  Created by 景思阳 on 6/2/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool convertToLowestTerms(int& numerator, int& denominator)
{
    if (denominator != 0)
    {
    int limit = round(abs(numerator)/2), count = 2;
    
    do
    {
        if (numerator%count == 0 && denominator%count == 0)
        {
            numerator /= count; denominator /= count;
        }
        else count++;
    }
    while(count<=limit);
    return 1;
    }
    else
        return 0;
}

int main()
{
    int numerator, denominator;
    bool condition;
    char ans;
    do
    {
        cout << "Please enter the numerator followed by the denominator:\n";
        cin >> numerator >> denominator;
        condition = convertToLowestTerms(numerator, denominator);
        if (condition)
            cout << "The fraction converted to lowest terms is " << numerator << "/" << denominator << ".\n";
        else
            cout << "Error: wrong input!\n";
        cout << "Run again? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    return 0;
}
