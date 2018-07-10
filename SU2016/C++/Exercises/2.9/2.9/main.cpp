//
//  main.cpp
//  2.9
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
#include <cmath>

int main()
{
    double n;
    double guess = n/2;
    double r = n/guess;
    const double precision = 0.01;
    std::cout << "Please enter a number: ";
    std::cin >> n;
    
    while (fabs((1-r/guess)/2) > precision)
        guess = (guess + r)/2,
        r = n/guess;
    
    guess = (guess+r)/2;
    
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    
    std::cout << guess << std::endl;
    
    return 0;
}
