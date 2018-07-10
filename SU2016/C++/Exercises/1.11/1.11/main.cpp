//
//  main.cpp
//  1.11
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int numSeconds;
    cout << "Please enter an integer that represents a length of time in seconds: \n";
    cin >> numSeconds;
    
    cout << numSeconds/60/60 << " hours, " << numSeconds/60%60 << " minutes, " << numSeconds%60%60 << " seconds.\n";
    
    return 0;
}
