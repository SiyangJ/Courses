//
//  main.cpp
//  2.1
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>

int main()
{
    double costItem, rateInflation;
    int numYears;
    
    std::cout << "Please enter the current cost of the item: $";
    std::cin >> costItem;
    std::cout << "Please enter the number of years from now that the item will be purchased: ";
    std::cin >> numYears;
    std::cout << "Please enter the percetage rate of inflation: ";
    std::cin >> rateInflation;
    
    rateInflation /= 100;
    
    for (int count = 1; count <= numYears; count++)
        costItem *= (1+rateInflation);
    
    std::cout << "The price of the item in " << numYears << " years is $" << costItem << ".\n";
    
    return 0;
}
