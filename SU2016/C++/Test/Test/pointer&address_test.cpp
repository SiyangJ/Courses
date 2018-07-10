//
//  pointer&address_test.cpp
//  Test
//
//  Created by apple on 7/10/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    cout << (a==b) << endl;
}

