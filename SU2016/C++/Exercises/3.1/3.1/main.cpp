//
//  main.cpp
//  3.1
//
//  Created by 景思阳 on 6/1/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

const double literForGallon = 0.264179;

double milesPerGallon(double numMiles, double numLiters)
{
    return numMiles/numLiters/literForGallon;
}

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    double numMiles = 0;
    double numLiters = 0;
    double currentMile;
    double currentLiter;
    string ans;
    do
    {
        cout << "Please enter the number of miles traveled followed by the liters of gasonline consumed: ";
        cin >> currentMile >> currentLiter;
        numMiles += currentMile; numLiters +=currentLiter;
        cout << "The number of miles per gallon the car delivered is " << milesPerGallon(numMiles,numLiters) << ".\n";
        cout << "Another travel? Enter y for yes. ";
        cin >> ans;
    }
    while (ans == "Y" or ans == "y");
    return 0;
}
