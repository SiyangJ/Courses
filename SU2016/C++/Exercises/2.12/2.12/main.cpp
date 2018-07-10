//
//  main.cpp
//  2.12
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
    double num1, num2, num3, num4, num5, num6, num7, num8, num9, totalNum;
    
    string filename = "/Users/jingsiyang1996/Desktop/C++/Exercises/2.12/Country_GDP.txt";
    fstream inputStream;
    inputStream.open(filename);
    
    while (inputStream >> text)
    {
        char firstDigit = text[0];
        cout << text <<endl;
        cout << firstDigit << endl;
        switch (firstDigit)
        {
            case '1':
                num1++;
                break;
            case '2':
                num2++;
                break;
            case '3':
                num3++;
                break;
            case '4':
                num4++;
                break;
            case '5':
                num5++;
                break;
            case '6':
                num6++;
                break;
            case '7':
                num7++;
                break;
            case '8':
                num8++;
                break;
            case '9':
                num9++;
                break;
            
        }
    }
    
    totalNum = num1+num2+num3+num4+num5+num6+num7+num8+num9;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "1: " << num1/totalNum*100 << "%\n"
         << "2: " << num2/totalNum*100 << "%\n"
         << "3: " << num3/totalNum*100 << "%\n"
         << "4: " << num4/totalNum*100 << "%\n"
         << "5: " << num5/totalNum*100 << "%\n"
         << "6: " << num6/totalNum*100 << "%\n"
         << "7: " << num7/totalNum*100 << "%\n"
         << "8: " << num8/totalNum*100 << "%\n"
         << "9: " << num9/totalNum*100 << "%\n";


    return 0;
}
