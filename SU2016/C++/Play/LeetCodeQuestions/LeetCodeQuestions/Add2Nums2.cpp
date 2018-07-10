//
//  Add2Nums2.cpp
//  LeetCodeQuestions
//
//  Created by apple on 10/19/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include "Add2Nums2.hpp"
#include <iostream>

using namespace std;

int main()
{
    ListNode* l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);
    
    ListNode* l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);
    
    ListNode* res=Add2Nums2().addTwoNumbers(l1, l2);
    
    delete l1;
    delete l2;
    delete res;
    
}