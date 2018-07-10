//
//  NLIS673.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/14/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef NLIS673_hpp
#define NLIS673_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class NLIS673 {
public:
    
    struct triple
    {
    public:
        triple(int i,int j,int k)
        {
            first=i;second=j;third=k;
        }
        triple(){}
        int first,second,third;
    };
    
    static int findNumberOfLIS(vector<int>& nums)
    {
        if (nums.size()==0) return 0;
        vector<triple> subs;
        //[0]=last number;[1]=length;[2]number
        for (int i:nums)
        {
            triple toPush(i,1,1);
            for (int j=0;j<subs.size();j++)
            {
                if (subs[j].first<i)
                {
                    if (subs[j].second>=toPush.second)
                    {
                        toPush.second=subs[j].second+1;
                        toPush.third=subs[j].third;
                    }
                    else if (subs[j].second==toPush.second-1)
                    {
                        toPush.third+=subs[j].third;
                    }
                }
            }
            subs.push_back(toPush);
        }
        
        sort(subs.begin(),subs.end(),[](triple& a,triple& b)->bool{return a.second>b.second;});
        
        int ret=subs[0].third;
        for (int i=1;i<subs.size();i++)
        {
            if (subs[i].second!=subs[i-1].second)
                break;
            else ret+=subs[i].third;
        }
        return ret;
    }
    
private:
    static bool cmp(int* fir,int* sec)
    {
        return fir[1]<=sec[1];
    }
};


#endif /* NLIS673_hpp */
