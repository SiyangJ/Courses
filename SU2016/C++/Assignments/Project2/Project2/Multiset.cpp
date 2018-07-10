//
//  Multiset.cpp
//  Homework_1
//
//  Created by apple on 6/28/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Multiset.h"
#include <iostream>

Multiset::Multiset()
{
    head=nullptr;
    tail=nullptr;
}

Multiset::Multiset(const Multiset& ms2)
{
    if (ms2.head==nullptr)
    {
        head=nullptr;
        tail=nullptr;
    }
    else
    {
        head=new Node;
        head->value=ms2.head->value;
        head->number=ms2.head->number;
        head->prev=nullptr;
        Node* ptr=ms2.head->next;
        if (ptr==nullptr)
        {
            head->next=nullptr;
            tail=head;
            return;
        }
        Node* prev=head;
        while (ptr!=nullptr)
        {
            tail=new Node;
            tail->number=ptr->number;
            tail->value=ptr->value;
            tail->prev=prev;
            prev->next=tail;
            prev=tail;
            ptr=ptr->next;
        }
        tail->next=nullptr;
    }
}

Multiset::~Multiset()
{
    while (tail!=nullptr)
    {
        tail=head->next;
        delete head;
        head=tail;
    }
}

Multiset &Multiset::operator= (const Multiset& ms2)
{
    // Avoid aliasing.
    if (this->head==ms2.head)
        return (*this);
    while (tail!=nullptr)
    {
        tail=head->next;
        delete head;
        head=tail;
    }
    // Above is delete;
    if (ms2.head==nullptr)
    {
        head=nullptr;
        tail=nullptr;
    }
    else
    {
        head=new Node;
        head->value=ms2.head->value;
        head->number=ms2.head->number;
        head->prev=nullptr;
        Node* ptr=ms2.head->next;
        if (ptr==nullptr)
        {
            head->next=nullptr;
            tail=head;
            return (*this);
        }
        Node* prev=head;
        while (ptr!=nullptr)
        {
            tail=new Node;
            tail->number=ptr->number;
            tail->value=ptr->value;
            tail->prev=prev;
            prev->next=tail;
            prev=tail;
            ptr=ptr->next;
        }
        tail->next=nullptr;
    }
    return (*this);
}

bool Multiset::empty() const
{
    if (head==nullptr)
        return 1;
    return 0;
}

int Multiset::size() const
{
    int size=0;
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        size += ptr->number;
        ptr=ptr->next;
    }
    return size;
}

int Multiset::uniqueSize() const
{
    int size=0;
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        size++;
        ptr=ptr->next;
    }
    return size;
}

bool Multiset::insert(const ItemType& value)
{
    if (head==nullptr)
    {
        head=new Node;
        head->value=value;
        head->number=1;
        head->prev=nullptr;
        head->next=nullptr;
        tail=head;
        return 1;
    }
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        if (ptr->value==value)
        {
            ptr->number++;
            return 1;
        }
        ptr=ptr->next;
    }
    tail->next=new Node;
    tail->next->prev=tail;
    tail=tail->next;
    tail->next=nullptr;
    tail->number=1;
    tail->value=value;
    return 1;
}
// Unordered;

int Multiset::erase(const ItemType& value)
{
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        if (ptr->value==value)
        {
            ptr->number--;
            if (ptr->number==0)
            {
                if (ptr->prev==nullptr)
                {
                    head=ptr->next;
                    if (head==nullptr)
                        tail=nullptr;
                    else
                    {
                        head->prev=nullptr;
                    }
                    delete ptr;
                    return 1;
                }
                else
                {
                    ptr->prev->next=ptr->next;
                    if (ptr->next==nullptr)
                    {
                        tail=ptr->prev;
                    }
                    else
                    {
                        ptr->next->prev=ptr->prev;
                    }
                    delete ptr;
                    return 1;
                }
            }
            return 1;
        }
        ptr=ptr->next;
    }
    return 0;
}

int Multiset::eraseAll(const ItemType& value)
{
    int num;
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        if (ptr->value==value)
        {
            num=ptr->number;
                if (ptr->prev==nullptr)
                {
                    head=ptr->next;
                    if (head==nullptr)
                        tail=nullptr;
                    else
                        head->prev=nullptr;
                    delete ptr;
                    return num;
                }
                else
                {
                    ptr->prev->next=ptr->next;
                    if (ptr->next==nullptr)
                    {
                        tail=ptr->prev;
                    }
                    else
                    {
                        ptr->next->prev=ptr->prev;
                    }
                    delete ptr;
                    return num;
                }
            return num;
        }
        ptr=ptr->next;
    }
    return 0;
}

bool Multiset::contains(const ItemType& value) const
{
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        if (ptr->value==value)
            return 1;
        ptr=ptr->next;
    }
    return 0;
}


int Multiset::count(const ItemType& value) const
{
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        if (ptr->value==value)
            return ptr->number;
        ptr=ptr->next;
    }
    return 0;
}

int Multiset::get(int i, ItemType& value) const
{
    if (i<0) return 0;
    int j=0;
    Node* ptr=head;
    while (ptr!=nullptr)
    {
        if (j==i)
        {
            value=ptr->value;
            return ptr->number;
        }
        ptr=ptr->next;
        j++;
    }
    return 0;
}

bool Multiset::getLeastFrequentValue(ItemType& value) const
{
    if (this->empty()) return 0;
    if (head->next==nullptr)
    {
        value=head->value;
        return 1;
    } // Correct.
    Node* ptr=head->next;
    Node* ptr2=head; // Method1
    bool yes=0;
    while (ptr!=nullptr)
    {
        if (ptr->number<ptr2->number)
        {
            ptr2=ptr;
            yes=1;
        }
        else if (ptr->number==ptr2->number)
            yes=0;
        ptr=ptr->next;
    }
    if (yes)
        value = ptr2->value;
    return yes;
}

 bool Multiset::getSmallestValue(ItemType& value) const
{
    if (this->empty()) return 0;
    Node* ptr=head;
    value=head->value; // Method2
    while (ptr!=nullptr)
    {
        if (ptr->value<value)
        {
            value=ptr->value;
        }
        ptr=ptr->next;
    }
    return 1;
}

bool Multiset::getSecondSmallestValue(ItemType& value) const
{
    if (this->empty() || head->next==nullptr) return 0;
    Node* ptr=head->next->next;
    ItemType small=head->next->value;
    value=head->value;
    ItemType temp;
    if (value<small)
    {
        temp=value;
        value=small;
        small=temp;
    }
    while (ptr!=nullptr)
    {
        if (ptr->value<value)
        {
            if (ptr->value<small)
            {
                value=small;
                small=ptr->value;
            }
            else
            {
                value=ptr->value;
            }
        }
        ptr=ptr->next;
    }
    return 1;
}

bool Multiset::replace(ItemType original, ItemType newvalue)
{
    if (original==newvalue) return 1;
    Node* ptr=head;
    Node* positionOfNew=nullptr;
    Node* positionOfOriginal;
    while (ptr!=nullptr)
    {
        if (ptr->value==newvalue)
            positionOfNew=ptr;
        if (ptr->value==original)
        {
            positionOfOriginal=ptr;
            if (positionOfNew==nullptr)
            {
                while (ptr!=nullptr)
                {
                    if (ptr->value==newvalue)
                        positionOfNew=ptr;
                    ptr=ptr->next;
                }
            }
            if (positionOfNew==nullptr)
            {
                positionOfOriginal->value=newvalue;
                return 1;
            }
            else
            {
                positionOfNew->number += positionOfOriginal->number; //Addition
                //Delete
                if (positionOfOriginal->prev==nullptr)
                {
                    head=positionOfOriginal->next;
                    delete positionOfOriginal;
                }
                else
                {
                    positionOfOriginal->prev->next=positionOfOriginal->next;
                    if (positionOfOriginal->next==nullptr)
                    {
                        tail=positionOfOriginal->prev;
                    }
                    else
                    {
                        positionOfOriginal->next->prev=positionOfOriginal->prev;
                    }
                    delete positionOfOriginal;
                }
                //Delete finish
                return 1;
            }
        }
        ptr=ptr->next;
    }
    return 0;
}


int Multiset::countIf(char op, ItemType value) const
{
    Node* ptr=head;
    int count2=0;
    switch (op)
    {
        case '<':
        {
            while (ptr!=nullptr)
            {
                if (ptr->value<value)
                    count2+=ptr->number;
                ptr=ptr->next;
            }
            return count2;
        }
        case '=':
        {
            while (ptr!=nullptr)
            {
                if (ptr->value==value)
                    count2+=ptr->number;
                ptr=ptr->next;
            }
            return count2;
        }
        case '>':
        {
            while (ptr!=nullptr)
            {
                if (ptr->value>value)
                    count2+=ptr->number;
                ptr=ptr->next;
            }
            return count2;
        }
        default: {return -1;}
    }
}

// Swap the head and tail pointers.
void Multiset::swap(Multiset& other)
{
    Node* temp1=this->head;
    Node* temp2=this->tail;
    this->head=other.head;
    this->tail=other.tail;
    other.head=temp1;
    other.tail=temp2;
}

// If this and other the same, counts *2
void Multiset::copyIntoOtherMultiset(Multiset &other) const
{
    Node* ptr;
    Node* ptr2=this->head;
    while (ptr2!=nullptr)
    {
        if (other.head==nullptr)
        {
            other.head=new Node;
            other.head->number=ptr2->number;
            other.head->value=ptr2->value;
            other.head->next=other.head->prev=nullptr;
            other.tail=other.head;
        }
        else {
        ptr=other.head;
        while (ptr!=nullptr)
        {
            if (ptr->value==ptr2->value)
            {
                ptr->number+=ptr2->number;
                break;
            }
            ptr=ptr->next;
        }
        if (ptr==nullptr)
        {
            other.tail->next=new Node;
            other.tail->next->prev=other.tail;
            other.tail=other.tail->next;
            other.tail->next=nullptr;
            other.tail->value=ptr2->value;
            other.tail->number=ptr2->number;
        }
        }
        ptr2=ptr2->next;
    }
}

// Above is member function

void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result)
{
    result=ms2;
    ms1.copyIntoOtherMultiset(result);
}

void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result)
{
    // Define a new to avoid aliasing.
    Multiset temp(ms1);
    int i=0, num;
    ItemType x;
    while ((num=ms2.get(i, x)))
    {
        for (int j=0;j<num;j++)
        {
            temp.erase(x);
        }
        i++;
    }
    result=temp;
}


