//
//  ReorderList143.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/16/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef ReorderList143_hpp
#define ReorderList143_hpp

#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class ReorderList143
{
public:
    void reorderList(ListNode* head)
    {
        if (head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return;
        
        ListNode *slow=head->next;
        ListNode *fast=slow->next;
        
        ListNode *next = slow->next;
        slow->next->next=slow;
        
        
        
        
    }
};


#endif /* ReorderList143_hpp */
