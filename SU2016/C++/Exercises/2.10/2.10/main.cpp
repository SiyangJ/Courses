//
//  main.cpp
//  2.10
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string text;
    const string filename = "/Users/jingsiyang1996/Desktop/C++/Exercises/2.10/2.10/test_file.txt";
    fstream inputStream;
    
    inputStream.open(filename);
    
    while (inputStream >> text)
    {
        if (text == "hate")
            text = "love";
        cout << text << " ";
    }
    cout << endl;
    
    return 0;
}
