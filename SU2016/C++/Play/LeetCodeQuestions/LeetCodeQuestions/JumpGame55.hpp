//
//  JumpGame55.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/27/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef JumpGame55_hpp
#define JumpGame55_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class JumpGame55
{
public:
    bool canJump(vector<int>& nums)
    {
        unsigned long n=nums.size();
        vector<bool> doable(n,true);
        
        return helper(nums,doable,n-1,0);
    }
    
private:
    
    bool helper(vector<int>& nums,vector<bool>& doable, const unsigned long& max, unsigned long cur)
    {
        if (cur>=max) return true;
        if (!doable[cur]) return false;
        for (int i=nums[cur];i>0;i--)
        {
            if (helper(nums,doable,max,cur+i))
                return true;
        }
        doable[cur]=false;
        return false;
    }
};

#endif /* JumpGame55_hpp */
