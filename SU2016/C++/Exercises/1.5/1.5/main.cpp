//
//  main.cpp
//  1.5
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int maximumCapacity;
    int numPeople;
    
    cout << "Please enter the maximum room capacity followed by the number of people to attend the meeting.\n";
    cin >> maximumCapacity >> numPeople;
    
    if (numPeople > maximumCapacity)
        cout << "The meeting cannot be held due to fire regulations and " << (numPeople - maximumCapacity)
             << " people must be exluded in order to meet the fire regulations.\n";
    else
        cout << "It is legal to hold the meeting and " << (maximumCapacity - numPeople)
             << " additional people may legally attend.\n";
    
    return 0;
}
