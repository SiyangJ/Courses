//
//  Partition698.cpp
//  LeetCodeQuestions
//
//  Created by apple on 10/17/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include "Partition698.hpp"
int main()
{
    vector<int> nums={2,11,1,10,4,10,1,4,2};
    int k=3;
    cout<<Partition698().canPartitionKSubsets(nums,k)<<endl;
}

