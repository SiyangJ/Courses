//
//  Add2Nums2.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/19/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef Add2Nums2_hpp
#define Add2Nums2_hpp

#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
    ListNode():val(0),next(NULL){}
    ~ListNode()
    {
        if (next!=NULL && next!=nullptr)
            delete next;
    }
};

class Add2Nums2
{
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        int carry=0;
        ListNode* ret=new ListNode(0);
        ListNode* cur=ret;
        for(;;)
        {
            cur->val=(l1==NULL?0:l1->val)+(l2==NULL?0:l2->val)+carry;
            if (cur->val>=10)
            {
                cur->val%=10;
                carry=1;
            }
            else
            {
                carry=0;
            }
            if (l1!=NULL)
                l1=l1->next;
            if (l2!=NULL)
                l2=l2->next;
            if (l1==NULL&&l2==NULL&&carry==0)
                return ret;
            cur->next=new ListNode(0);
            cur=cur->next;
        }
    }
};

#endif /* Add2Nums2_hpp */
