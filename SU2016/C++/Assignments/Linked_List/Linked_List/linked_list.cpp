//
//  linked_list.cpp
//  Linked_List
//
//  Created by apple on 7/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "linked_list.hpp"

LikedList::LikedList()
{
    head=nullptr;
}

void LikedList::Add(ItemType val)
{
    if (head==nullptr)
    {
        head=new Node(val);
        return;
    }
    Node* ptr=head;
    while (ptr->next!=nullptr)
    {
        ptr=ptr->next;
    }
    ptr->next=new Node(val);
}

bool LikedList::Delete(ItemType val)
{
    Node* previous=head;
    if (previous==nullptr)
    {
        return 0;
    }
    if (previous->m_val==val)
    {
        head=previous->next;
        delete previous;
        return 1;
    }
    Node* ptr=previous->next;
    while (ptr!=nullptr)
    {
        if (ptr->m_val==val)
        {
            previous->next=ptr->next;
            delete ptr;
            return 1;
        }
        previous=ptr;
        ptr=ptr->next;
    }
    return 0;
}

void LikedList::Reverse()
{
    Node* previous=head;
    if (previous==nullptr)
    {
        return;
    }
    Node* ptr=previous->next;
    Node* temp;
    previous->next=nullptr;
    while (ptr!=nullptr)
    {
        temp=ptr->next;
        ptr->next=previous;
        previous=ptr;
        ptr=temp;
    }
    head=previous;
    return;
}

void LikedList::PrintList()
{
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        std::cout << ptr->m_val << std::endl;
        ptr=ptr->next;
    }
}

/*Swap data
void LikedList::Swap(ItemType a, ItemType b)
{
    Node* ptr=head;
    Node* pA=nullptr, *pB=nullptr;
    while(pA==nullptr && pB==nullptr)
    {
        if (ptr==nullptr)
            return;
        if (ptr->m_val==a)
        {
            pA=ptr;
        }
        else if (ptr->m_val==b)
        {
            pB=ptr;
        }
        ptr=ptr->next;
    }
    ItemType temp1;
    Node* temp2;
    temp1=pA->m_val;
    pA->m_val=pB->m_val;
    pB->m_val=temp1;
    temp2=pA->next;
    pA->next=pB->next;
    pB->next=temp2;
}
 
 */

// Swap pointer
void LikedList::Swap(ItemType a, ItemType b)
{
    if (head==nullptr)
        return;
    if (a==b)
        return;
    Node* ptr=head, *preptr=nullptr;
    Node* pA=nullptr, *pB=nullptr, *preA=nullptr, *preB=nullptr;
    while(pA==nullptr && pB==nullptr)
    {
        if (ptr==nullptr)
            return;
        if (ptr->m_val==a)
        {
            pA=ptr;
            preA=preptr;
        }
        else if (ptr->m_val==b)
        {
            pB=ptr;
            preB=preptr;
        }
        preptr=ptr;
        ptr=ptr->next;
    }
    Node* temp;
    temp=pA->next;
    pA->next=pB->next;
    pB->next=temp;
    if (preA==nullptr)
    {
        preB->next=pA;
        head=pB;
    }
    else if (preB==nullptr)
    {
        preA->next=pB;
        head=pA;
    }
    else
    {
        preA->next=pB;
        preB->next=pA;
    }
}















