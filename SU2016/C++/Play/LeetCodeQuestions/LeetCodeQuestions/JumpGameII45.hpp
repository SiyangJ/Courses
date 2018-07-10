//
//  JumpGameII45.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/27/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef JumpGameII45_hpp
#define JumpGameII45_hpp


#include <stdio.h>
#include <vector>

using namespace std;

class JumpGameII45
{
public:
    int jump(vector<int>& nums)
    {
        unsigned long n=nums.size();
        if (n==1) return 0;
        vector<int> step(n,0);
        for (int i=n-2;i>=0;i--)
        {
            for (int j=nums[i];j>0;j--)
            {
                if (i+j>=n-1)
                {
                    step[i]=1;
                    break;
                }
                if (step[i+j])
                {
                    if (step[i+j]==1)
                    {
                        step[i]=2;
                        break;
                    }
                    if (step[i]==0)
                        step[i]=step[i+j]+1;
                    else
                        step[i]=min(step[i],step[i+j]+1);
                }
            }
        }
        return step[0];
    }
};

#endif /* JumpGameII45_hpp */
