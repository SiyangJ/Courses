//
//  SmallestRange632.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/27/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef SmallestRange632_hpp
#define SmallestRange632_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class SmallestRange632
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        vector<int> ret = {INT_MIN,INT_MAX};
        unsigned long num_lists = nums.size();
        vector<unsigned long> sizes;
        for(vector<int> l:nums)
            sizes.push_back(l.size());
        
        
        
        
        
        
        
        return ret;
    }
};

#endif /* SmallestRange632_hpp */
