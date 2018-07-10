//
//  main.cpp
//  1.6
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    const double ratePay = 16.78;
    const double regularHours = 40;
    const double overtimeRate = 1.5*ratePay;
    const double socialTaxRate = 0.06,
                 federalTaxRate = 0.14,
                 stateTaxRate = 0.05,
                 unionDueRate = 0.1;
    const double healthInsurance = 35;
    
    double hours;
    int numDependents;
    double totalPay;
    
    cout << "Please enter the number of hours worked in a week:\n";
    cin >> hours;
    cout << "Please enter the number of dependents:\n";
    cin >> numDependents;
    
    if (hours > regularHours)
        totalPay = ratePay*regularHours+overtimeRate*(hours-regularHours);
    else
        totalPay = ratePay*hours;
    
    double socialTax = totalPay*socialTaxRate;
    double federalTax = totalPay*federalTaxRate;
    double stateTax = totalPay*stateTaxRate;
    double unionDue = totalPay*unionDueRate;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "The worker's gross pay is $" << totalPay << ".\n"
         << "$" << socialTax << " is withheld for Social Security tax.\n"
         << "$" << federalTax << " is withheld for federal income tax.\n"
         << "$" << stateTax << " is withheld for federal income tax.\n"
         << "$" << unionDue << " is withheld for union dues.\n";
    
    totalPay = totalPay - socialTax - federalTax - stateTax - unionDue;
    
    if (numDependents >= 3)
        totalPay -= healthInsurance,
        cout << "$" << healthInsurance << " is withheld to cover the extra cost of health insurance beyond what the employer pays.\n";
    
    cout << "The worker's net take-home pay for the week is $" << totalPay << ".\n";
    
    return 0;
}
