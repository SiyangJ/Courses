//
//  main.cpp
//  LeetCode47
//
//  Created by apple on 10/9/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        m_nums = &nums;
        m_size = m_nums->size();
        vector<vector<int>> res;
        if (m_size<1) return res;
        m_start = 0;
        helper(res);
        
        return res;
    }
    
private:
    unsigned long m_start;
    unsigned long m_size;
    vector<int>* m_nums;
    void helper(vector<vector<int>>& res)
    {
        if(m_start>=m_size) return;
        
    }
    int factorial(int n)
    {
        return n==1?1:(factorial(n-1)*n);
    }
};