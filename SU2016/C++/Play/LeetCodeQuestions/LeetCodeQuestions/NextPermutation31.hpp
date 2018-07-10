//
//  NextPermutation31.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/26/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef NextPermutation31_hpp
#define NextPermutation31_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class NextPermutation31 {
public:
    void nextPermutation(vector<int>& nums) {
        unsigned long n=nums.size();
        if (n==0 || n==1)
            return;
        for (unsigned long i=n-1;i>0;i--)
        {
            if (nums[i]>nums[i-1])
            {
                unsigned long j=i;
                for (;j<n;j++)
                {
                    if (nums[j]<=nums[i-1])
                    {
                        swap(nums[j-1],nums[i-1]);
                        break;
                    }
                }
                if (j==n)
                {
                    swap(nums[j-1],nums[i-1]);
                }
                unsigned long mid=(n-1-i)/2;
                for (unsigned long k=0;k<=mid;k++)
                {
                    swap(nums[i+k],nums[n-1-k]);
                }
                return;
            }
        }
        for (unsigned long i=0;i<n/2;i++)
        {
            swap(nums[i],nums[n-1-i]);
        }
    }
};

#endif /* NextPermutation31_hpp */
