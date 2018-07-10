//
//  Partition698.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/17/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef Partition698_hpp
#define Partition698_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


class Partition698
{
public:
    bool canPartitionKSubsets(vector<int>& nums,int k)
    {
        int n=nums.size();
        if (n<k)return false;
        if (n==0||n==1) return true;
        int sum=0;
        for (int i:nums)
            sum+=i;
        if (sum%k!=0) return false;
        int target = sum/k;
        sort(nums.begin(),nums.end());
        if (nums[n-1]>target)
            return false;
        int start=n;
        while (nums[--start]==target);
        k-=(n-start-1);
        vector<bool> visited(nums.size(),false);
        visited[start]=true;
        return canPartition(nums, visited, target,nums[start],k,start);
    }
    
    
    
private:
    bool canPartition(vector<int>& nums,vector<bool>& visited,const int& target,
                      int curNum,int k,int start)
    {
        if (curNum==target)
        {
            curNum=0;
            k--;
            while(--start>=0&&visited[start]);
            if (start<0)
                return k==0;
            curNum=nums[start];
            visited[start]=true;
            
        }
        for (int i=0;i<start;i++)
        {
            if (visited[i])
                continue;
            curNum+=nums[i];
            if (curNum>target) break;
            visited[i]=true;
            if (canPartition(nums,visited,target,curNum,k,start))
                return true;
            curNum-=nums[i];
            visited[i]=false;
        }
        visited[start]=false;
        return false;
    }
};

// First compute the sum, S;
// Then skip all numbers equal to S;
// Match up all S-1 and 1's;
// Match up all S-2 and

// We can sort the array

// Pairing
    // Can't pair








#endif /* Partition698_hpp */
