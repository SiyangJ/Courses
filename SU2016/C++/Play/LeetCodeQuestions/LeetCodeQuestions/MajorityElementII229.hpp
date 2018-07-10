//
//  MajorityElementII229.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/26/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef MajorityElementII229_hpp
#define MajorityElementII229_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class MajorityElementII229 {
public:
    
    // Linear time and constant space
    vector<int> majorityElement(vector<int> &a) {
        int y = 0, z = 1, cy = 0, cz = 0;
        for (auto x: a) {
            if (x == y) cy++;
            else if (x == z) cz++;
            else if (! cy) y = x, cy = 1;
            else if (! cz) z = x, cz = 1;
            else cy--, cz--;
        }
        cy = cz = 0;
        for (auto x: a)
            if (x == y) cy++;
            else if (x == z) cz++;
        vector<int> r;
        if (cy > a.size()/3) r.push_back(y);
        if (cz > a.size()/3) r.push_back(z);
        return r;
    }
};

#endif /* MajorityElementII229_hpp */
