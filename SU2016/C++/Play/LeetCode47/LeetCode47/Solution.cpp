//
//  Solution.cpp
//  LeetCode47
//
//  Created by apple on 10/9/17.
//  Copyright © 2017 UNC. All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    Solution()
    {};
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;
        helper(res,nums,0,nums.size()-1);
        return res;
    }
    
    
    
private:
    void helper(vector<vector<int>>& res,vector<int>& nums,int i,int n)
    {
        if (i==n)
            res.push_back(nums);
        else
        {
            for (int j=i;j<=n;j++)
            {
                if (j!=i && nums[i]==nums[j])
                    continue;
                swap(nums[i],nums[j]);
                helper(res,nums,i+1,n);
                swap(nums[i],nums[j]);
            }
        }
    }
    
};

int main() {
    Solution solution;
    vector<int> test = {2,2,1,1};
    vector<vector<int>> res = solution.permuteUnique(test);
    
    for (int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout << res[i][j] << ',';
        cout<<endl;
    }
    
}