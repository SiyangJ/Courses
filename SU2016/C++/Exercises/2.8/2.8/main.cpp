//
//  main.cpp
//  2.8
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int celsius = 100;
    int fahrenheit;
    
    do
    {
        celsius--;
        fahrenheit = 9*celsius/5+32;
    }
    while (fahrenheit != celsius);
    
    cout << fahrenheit << " degrees Fahrenheit is equal to " << celsius << " degrees Celsius.\n";
    
    return 0;
}
