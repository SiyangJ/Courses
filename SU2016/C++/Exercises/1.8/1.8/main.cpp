//
//  main.cpp
//  1.8
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    double n;
    cout << "Please enter a number: ";
    cin >> n;
    double guess = n/2;
    
    double r;
    const int maxCount = 5;
    
    for (int count = 1; count <= maxCount; count++)
    {
        r = n/guess;
        guess = (guess+r)/2;
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "The square root of the input number is approximately " << guess << ".\n";
    
    return 0;
}
