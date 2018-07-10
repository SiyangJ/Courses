//
//  Pattern132_456.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/24/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef Pattern132_456_hpp
#define Pattern132_456_hpp

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;


class Pattern132
{
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){
                s3 = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};



// [1 2 3 4 9 8 7 6]

#endif /* Pattern132_456_hpp */