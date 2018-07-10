//
//  linked_list.hpp
//  Linked_List
//
//  Created by apple on 7/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <iostream>

typedef int ItemType;

struct Node
{
    Node(ItemType val) : m_val(val), next(0){}
    ItemType m_val;
    Node *next;
};

class LikedList
{
public:
    LikedList();
    bool Delete(ItemType val);
    void Add(ItemType val);
    Node* Find(ItemType val);
    void Reverse();
    void Swap(ItemType a, ItemType b);
    void PrintList();
private:
    Node* head;
};

#endif /* linked_list_hpp */
