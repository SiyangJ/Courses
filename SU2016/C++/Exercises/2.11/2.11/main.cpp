//
//  main.cpp
//  2.11
//
//  Created by 景思阳 on 6/1/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string text;
    int feet;
    int inch;
    fstream inputStream;
    string filename = "/Users/jingsiyang1996/Desktop/C++/Exercises/2.11/list.txt";
    inputStream.open(filename);
    
    while (inputStream >> text)
    {
        cout << text << " ";
        inputStream >> text;
        cout << text << "'s ideal body weight is ";
        inputStream >> feet;
        inputStream >> inch;
        if (feet<5)
            feet = 110;
        else
            feet = 110+((feet-5)*12+inch)*5;
        cout << feet << " pounds.\n";
    }
    
    return 0;
}
