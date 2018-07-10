//
//  JumpGame55.cpp
//  LeetCodeQuestions
//
//  Created by apple on 10/27/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include "JumpGame55.hpp"
#include <iostream>

int main()
{
    vector<int> test1;
    int max=25000;
    for (;max>=0;max--)
        test1.push_back(max);
    cout << JumpGame55().canJump(test1) << endl;
}