//
//  main.cpp
//  1.2
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    const double fractionSweetener = 0.001;
    double amountKillMouse;
    double weightMouse;
    double weightDieter;
    
    cout << "Please enter the amount of artificial sweetener needed to kill a mouse in ounces:\n";
    cin >> amountKillMouse;
    cout << "Please enter the weight of a mouse in pounds:\n";
    cin >> weightMouse;
    cout << "Please enter the weight in pounds at which the dieter will stop dieting:\n";
    cin >> weightDieter;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "The dieter can drink " << (amountKillMouse/weightMouse*weightDieter/fractionSweetener) << " ounces of diet soda without dying.\n";
    
    return 0;
}
