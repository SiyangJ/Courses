//
//  main.cpp
//  3.5
//
//  Created by 景思阳 on 6/1/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

double hatSize(double weightPounds, double heightInches)
{
    return weightPounds/heightInches*2.9;
}

double jacketSize(double weightPounds, double heightInches, int age)
{
    if (age >= 40)
        return heightInches*weightPounds/288 + (age-30)/10/8;
    else
        return heightInches*weightPounds/288;
}

double waist(double weight, int age)
{
    if (age>=30)
        return weight/5.7+(age-28)/2/10;
    else
        return weight/5.7;
}

int main()
{
    double weight, height;
    int age;
    string ans;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    do
    {
    cout << "Please enter your height in inches, your weight in pounds and your age:\n";
    cin >> height >> weight >> age;
    cout << "Your clothing sizes are estimated as below:\n" << "Hat size: " << hatSize(weight, height) << endl
         << "Jacket size: " << jacketSize(weight, height, age) << endl
         << "Waist in inches: " << waist(weight, age) << endl;
    
    cout << "Another calculation? Enter y for yes.\n";
    cin >> ans;
    }
    
    while (ans == "y" || ans == "Y");
    
    return 0;
}
