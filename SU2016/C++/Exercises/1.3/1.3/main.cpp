//
//  main.cpp
//  1.3
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    const double payIncrease = 7.6/100;
    double previousAnnualSalary;
    
    cout << "Please enter the previous annual salary: $\n";
    cin >> previousAnnualSalary;
    
    cout << "The amount of retroactive pay is $" << (previousAnnualSalary/2*payIncrease) << ".\n"
         << "The new annual salary is $" << (previousAnnualSalary*(1+payIncrease)) << ".\n"
         << "The new monthly salary is $" << (previousAnnualSalary*(1+payIncrease)/12) << ".\n";
    
    return 0;
}
