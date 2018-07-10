//
//  main.cpp
//  1.7
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    double weightPounds;
    double numMET;
    double numMinutes;
    
    cout << "Please enter the subject's weight in pounds, the number of METS for the activity and the number of minutes spent on that activity.\n";
    cin >> weightPounds >> numMET >> numMinutes;
    
    cout << "The total number of calories burned is " << (0.0175*numMET*weightPounds/2.2*numMinutes) << ".\n";
    
    return 0;
}
