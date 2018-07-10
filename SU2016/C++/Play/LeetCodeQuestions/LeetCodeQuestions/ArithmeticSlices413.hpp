//
//  ArithmeticSlices413.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/14/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef ArithmeticSlices413_hpp
#define ArithmeticSlices413_hpp

#include <stdio.h>
#include <vector>

// Find the longest sub

// From a point a0
// a1, nothing
// a2, if same
// two pointers
// if a2 not the same
// set p1 to a1




// [1,2,3,4,6,8,10,11,17,17,17,17]




class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& A)
    {
        if (A.size()<3) return 0;
        int ret = 0;
        int p1 = 0;
        int p2 = 1;
        while (p2<A.size())
        {
            if (p2==A.size()-1 || A[p2+1]-A[p2]!=A[p1+1]-A[p1])
            {
                ret += (p2-p1)*(p2-p1-1)/2;
                p1 = p2;
            }
            p2++;
        }
        return ret;
    }
    
};


#endif /* ArithmeticSlices413_hpp */
