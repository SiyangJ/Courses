//
//  main.cpp
//  5.1
//
//  Created by 景思阳 on 6/5/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int NUM_MONTH = 12;
const string MONTH_NAME[12] = {"January","February","March","April","May","June","July","August","September","October","Novermber","December"};
const double RAINFALL_SCALE = 100;

void getAve(double ave[])
{
    for (int count = 0; count < NUM_MONTH; count++)
    {
        cout << "Please enter the average rainfall of " << MONTH_NAME[count] << ":\n";
        cin >> ave[count];
    }
}

void getActual(double actual[])
{
    int numMonth;
    cout << "Which month is it now? (Enter as a number)\n";
    cin >> numMonth;
    if (numMonth > 12 or numMonth < 1)
    {
        cout << "Error: wrong input!\n";
        getActual(actual);
    }
    else
    {
    cout << "Please enter the actual the rainfall of the previous " << NUM_MONTH << " months:\n";
    for (int count = 0; count < NUM_MONTH; count++)
    {
        cin >> actual[(numMonth+count-1)%12];
    }
    }
}

void computeDifference(const double ave[], const double actual[], double difference[])
{
    for (int count = 0; count < NUM_MONTH; count++)
    {
        difference[count] = actual[count]-ave[count];
    }
}

void displayTable(double actual[], double difference[])
{
    cout << setw(10) << " ";
    for (int count = 0; count < NUM_MONTH; count++)
    {
        cout << setw(10) << MONTH_NAME[count];
    }
    cout << endl << setw(10) << "Actual";
    for (int count = 0; count < NUM_MONTH; count++)
    {
        cout << setw(10) << actual[count];
    }
    cout << endl << setw(10) << "Difference";
    for (int count = 0; count < NUM_MONTH; count++)
    {
        cout << setw(10) << difference[count];
    }
    cout << endl;

}

void displayGraph(double dataArr[])
{
    for (int count = 0; count < NUM_MONTH; count++)
    {
        cout << setw(10) << MONTH_NAME[count] << " ";
        for (int count2 = 0; count2 < round(dataArr[count]/RAINFALL_SCALE); count2++)
            cout << "*";
        cout << endl;
    }
}


int main()
{
    double ave[NUM_MONTH], actual[NUM_MONTH], difference[NUM_MONTH];
    int ans1;
    char ans2 = 'y';
    
    getAve(ave);
    getActual(actual);
    computeDifference(ave, actual,difference);
    
    displayTable(actual, difference);
    
    while (ans2 == 'y' or ans2 == 'Y')
    {
        cout << "Which graph? 1 for average rainfall, 2 for actual rainfall:\n";
        cin >> ans1;
        if (ans1 == 1)
            {
                displayGraph(ave);
            }
        else if (ans1 == 2)
            {
                displayGraph(actual);
            }
        else
            {
                cout << "Error: wrong input!\n";
                continue;
            }
        cout << "Display another graph? (y/n)\n";
        cin >> ans2;
    }
    return 0;
}
