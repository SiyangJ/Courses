//
//  main.cpp
//  4.11
//
//  Created by 景思阳 on 6/2/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int prizeDoor;
    int chooseDoor;
    int limit = 10000;
    int winCount;
    char ans;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    do
    {// stay
    winCount = 0;
    for (int count = 1; count <= limit; count++)
    {
        prizeDoor = rand()%3;
        chooseDoor = rand()%3;
        if (chooseDoor == prizeDoor)
            winCount++;
    }
    cout << "Win rate for stay: " << winCount/static_cast<double>(limit)*100 << "%\n";
    winCount = 0;
    // switch
    for (int count = 1; count <= limit; count++)
    {
        prizeDoor = rand()%3;
        chooseDoor = rand()%3;
        if (chooseDoor != prizeDoor)
            winCount++;
    }
    cout << "Win rate for switch: " << winCount/static_cast<double>(limit)*100 << "%\n";
    cout << "Run again? (y/n)\n";
    cin >> ans;
    }
    while(ans == 'y' or ans == 'Y');

    return 0;
}
