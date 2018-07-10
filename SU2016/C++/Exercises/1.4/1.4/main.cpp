//
//  main.cpp
//  1.4
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    double amountNeed;
    double interestRate;
    double duration;
    
    cout << "Please enter the amounts of loan the consumer needs to receive, followed by the interest rate and the duration o of the loan in months.\n";
    cin >> amountNeed >> interestRate >> duration;
    
    double faceValue = amountNeed/(1-interestRate*duration/12);
    double monthlyPayment = faceValue/duration;
    
    cout << "The face value required in order for the consumer to receive the amount needed is $" << faceValue << ".\n"
         << "The monthly payment is $" << monthlyPayment << ".\n";
    
    return 0;
}
