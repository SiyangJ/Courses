//
//  PerfectSquares279.cpp
//  LeetCodeQuestions
//
//  Created by apple on 10/13/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef PS279_included
#define PS279_included

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution279 {
public:
    
    static vector<int> cntPerfectSquares;
    
    int numSquares(int n)
    {
        if (cntPerfectSquares.size()==0)
            cntPerfectSquares.push_back(0);
        if (cntPerfectSquares.size()>n)
            return cntPerfectSquares[n];
        
        int ret = INT_MAX;
        
        for (int i=1;i*i<=n;i++)
        {
            ret = min(ret,numSquares(n-i*i)+1);
        }
        
        cntPerfectSquares.push_back(ret);
        return ret;
        
    }
};


#endif
