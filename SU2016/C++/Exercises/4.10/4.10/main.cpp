//
//  main.cpp
//  4.10
//
//  Created by 景思阳 on 6/2/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

const double meterInAFoot = 0.3048, poundInAKilogram = 2.2046, cmInM = 100, inInF = 12, gInkg = 1000, osInLb = 16;
const string m = "meters", cm = "centimeters", foot = "feet", inch = "inches",
             kg = "kilograms", g = "grams", lb = "pounds", os = "ounces";

void askType(int& type)
{
    cout << "Please enter the type of conversion: (1 for length, 2 for weight)\n";
    cin >> type;
    if (type != 1 && type != 2)
    {
        cout << "Error: wrong input!\n";
        askType(type);
    }
}

void getName1(int type, string& name1, string& name2, string& name3, string& name4)
{
    switch(type)
    {
case 1:
    {
        name1 = m;
        name2 = cm;
        name3 = foot;
        name4 = inch;
        break;
    }
case 2:
    {
        name1 = lb;
        name2 = os;
        name3 = kg;
        name4 = g;
        break;
    }
    }
}

void askDirection(int& type, string name1, string name3)
{
    cout << "Please enter the direction of conversion:\n"
    << "1 for " << name1 << " to " << name3 << ", 2 for " << name3 << " to " << name1 << endl;
    cin >> type;
    if (type != 1 && type != 2)
    {
        cout << "Error: wrong input!\n";
        askDirection(type, name1, name3);
    }
}

void getInput(string name1, string name2, double& var1, int& var2)
{
    cout << "Please enter the number of " << name1 << " followed by the number of " << name2 << ":\n";
    cin >> var1 >> var2;
    cout << noshowpoint << var1 << " " << name1 << " " << var2 << " " << name2 << " is equal to ";
}

void smallToBig(double& var1, int var2, double convConst)
{
    var1 += var2/convConst;
}

void bigToSmall(double& var1, int& var2, double convConst)
{
    var2 = round((modf(var1,&var1))*convConst);
}

void leftToRight(double& var1, double convConst)
{
    var1 /= convConst;
}

void rightToLeft(double& var1, double convConst)
{
    var1 *= convConst;
}

void getOutput(string name3, string name4, double var1, int var2)
{
    cout << noshowpoint << var1 << " " << name3 << " " << var2 << " " << name4 << endl;
}


int main()
{
    int type, var2;
    double var1, convConst1, convConst2, convConst3;
    string name1, name2, name3, name4;
    char ans;
    do
    {
        askType(type);
        getName1(type, name1, name2, name3, name4);
        if (type == 1)
        {
            convConst1 = cmInM;
            convConst2 = meterInAFoot;
            convConst3 = inInF;
        }
        else
        {
            convConst1 = osInLb;
            convConst2 = poundInAKilogram;
            convConst3 = gInkg;
        }
        askDirection(type, name1, name3);
        if (type == 1)
        {
            getInput(name1, name2, var1, var2);
            smallToBig(var1, var2, convConst1);
            leftToRight(var1, convConst2);
            bigToSmall(var1, var2, convConst3);
            getOutput(name3, name4, var1, var2);
        }
        else
        {
            getInput(name3, name4, var1, var2);
            smallToBig(var1, var2, convConst3);
            rightToLeft(var1, convConst2);
            bigToSmall(var1, var2, convConst1);
            getOutput(name1, name2, var1, var2);
        }
        
        cout << "Run again? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    
    return 0;
}
