//
//  main.cpp
//  LeetCodeQuestions
//
//  Created by apple on 10/9/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <iostream>
#include "PerfectSquares279.hpp"
#include "NLIS673.hpp"


int main()
{
    /*
    int n=100;
    int maxSize = 100;
    for (int i=0;i<n;i++)
    {
        vector<int> test;
        int m=rand()%maxSize;
        
        for (int j=0;j<m;j++)
            test.push_back(rand());
        
        cout<<NLIS673::findNumberOfLIS(test)<<endl;
        
    }
     */
    
    vector<int> test = {1,1,1,2,2,2,3,3,3};
    cout<<NLIS673::findNumberOfLIS(test)<<endl;

    
    
}


