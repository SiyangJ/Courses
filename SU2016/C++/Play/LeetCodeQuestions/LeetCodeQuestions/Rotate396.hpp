//
//  Rotate396.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/19/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef Rotate396_hpp
#define Rotate396_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Rotate396
{
public:
    int maxRotateFunction(vector<int>& A)
    {
        unsigned long n = A.size();
        if (n==0)
            return 0;
        int sumEach=0,curSum=0;
        for (int i=0;i<n;i++)
        {
            sumEach+=A[i];
            curSum+=i*A[i];
        }
        int maxSum=curSum;
        for (unsigned long i=n-1;i>=1;i--)
        {
            curSum=curSum+sumEach-n*A[i];
            maxSum=maxSum>curSum?maxSum:curSum;
        }
        return maxSum;
    }
};

#endif /* Rotate396_hpp */
