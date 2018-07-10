//
//  main.cpp
//  4.2
//
//  Created by 景思阳 on 6/2/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft)
{
    number = amountLeft/coinValue;
    amountLeft = amountLeft%coinValue;
}

void getInput(int& totalAmount)
{
    cout << "Please enter an amount of change:\n";
    cin >> totalAmount;
    if (totalAmount >= 100 or totalAmount <= 0)
    {
        cout << "Error: wrong input!\n";
        exit(1);
    }
}

void getOutput(int coinValue, int number)
{
    string coinName;
    if (coinValue == 25)
    {
        if (number == 1 or number == 0)
            coinName = "quarter ";
        else
            coinName = "quarters ";
    }
    else if (coinValue == 10)
    {
        if (number == 1 or number == 0)
            coinName = "dime ";
        else
            coinName = "dimes ";
    }
    else
    {
        if (number == 1 or number == 0)
            coinName = "penny\n";
        else
            coinName = "pennies\n";
    }
    
    cout << number << " " << coinName;
}

int main()
{
    const int quarterValue = 25, dimeValue = 10, pennyValue = 1;
    int number, amountLeft;
    string coinName;
    char ans;
    do
    {
        getInput(amountLeft);
        cout << amountLeft << " cents can be given as\n";
        computeCoin(quarterValue, number, amountLeft);
        getOutput(quarterValue, number);
        if (amountLeft >= 0)
        {
            computeCoin(dimeValue, number, amountLeft);
            getOutput(dimeValue, number);
        }
        if (amountLeft >= 0)
        {
            computeCoin(pennyValue, number, amountLeft);
            getOutput(pennyValue, number);
        }
        cout << "Run again? (y/n)";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    return 0;
}
