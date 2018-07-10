//
//  MaxProductSubarray152.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/19/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef MaxProductSubarray152_hpp
#define MaxProductSubarray152_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class MaxProductSubarray152
{
public:
    
    int maxProduct(vector<int>& nums)
    {
        int start=-1;
        int ret=INT_MIN;
        int cur;
        while (++start<nums.size())
        {
            if (nums[start]==0)
            {
                if (ret<0)
                    ret=0;
                continue;
            }
            cur=maxProducthelper(nums,start);
            ret=max(ret,cur);
        }
        return ret;
        
    }
private:
    int maxProducthelper(vector<int>& nums,int& start)
    {
        if (start+1==nums.size()||nums[start+1]==0)
            return nums[start];
        int beforeNeg=1;
        int lastPos=-1;
        int cur=1;
        
        do
        {
            cur*=nums[start];
            if (cur>0)
                lastPos=cur;
            else if (beforeNeg>0)
                beforeNeg=cur;
            
        }
        while(++start<nums.size()&&nums[start]!=0);
        start--;
        if (cur>0) return cur;
        return max(cur/beforeNeg,lastPos);
    }
};

#endif /* MaxProductSubarray152_hpp */
