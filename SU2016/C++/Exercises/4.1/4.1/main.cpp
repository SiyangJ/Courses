//
//  main.cpp
//  4.1
//
//  Created by 景思阳 on 6/1/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

void getInput(int& hour, int& minute)
{
    cout <<  "Please enter the current time: ";
    cin >> hour >> minute;
}

void conversion(int& hour, char& AmPm)
{
    if (hour/12)
        AmPm = 'P';
    else
        AmPm = 'A';
    hour = hour%12;
}

void getOutput(int hour, int minute, char AmPm)
{   cout << setfill('0');
    cout << setw(2) << hour << ":" << setw(2) << minute << " " << AmPm << ".M.\n";
}

int main()
{
    int hour, minute;
    char AmPm, ans = 'y';
    do
    {
        getInput(hour,minute);
        if (hour>23 or minute>59)
        {
            cout << "Error: wrong input!\n";
            continue;
        }
        conversion(hour,AmPm);
        getOutput(hour, minute, AmPm);
        cout << "Run again? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    return 0;
}
