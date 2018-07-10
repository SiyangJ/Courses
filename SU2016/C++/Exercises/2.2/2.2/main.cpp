//
//  main.cpp
//  2.2
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    const int initialDebt = 1000;
    double totalDebt = initialDebt;
    double count = 0;
    const double monthlyRate = 1.5/100;
    const int monthlyPay = 50;
    const double minimumDebt = monthlyPay/(1+monthlyRate);
    
    while (totalDebt >= minimumDebt)
    {
        totalDebt = totalDebt - monthlyPay + totalDebt*monthlyRate;
        count++;
    }
    
    cout << "It will take you " << count+1 << " months to pay off the loan and the total amount of interest over the life of the loan is $" << count*monthlyPay+totalDebt-initialDebt << ".\n";
    
    return 0;
}
