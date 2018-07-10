//
//  main.cpp
//  2.6
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double spWeightWater = 62.4;
    double weight;
    cout << "Please enter the weight of the object in pounds:\n";
    cin >> weight;
    double radius;
    cout << "Please enter the radius of the object in feet:\n";
    cin >> radius;
    
    if (4/3*M_PI*pow(radius,3)*spWeightWater >= weight)
        cout << "The object will float in water.\n";
    else
        cout << "The object will sink in water.\n";

    return 0;
}
