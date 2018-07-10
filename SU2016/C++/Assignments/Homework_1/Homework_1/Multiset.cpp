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
    sizeOfArr=0;
}
// Initialize numbers to all zeros to avoid error;
// Question mark;

bool Multiset::empty() const
{
    if (sizeOfArr==0)
        return 1;
    return 0;
}

int Multiset::size() const
{
    int size=0;
    int count=0;
    while (count<sizeOfArr)
    {
        size += this->itemArr[count].number;
        count++;
    }
    return size;
}

int Multiset::uniqueSize() const
{
    return sizeOfArr;
}

bool Multiset::insert(const ItemType& value)
{
    int count=0;
    while (count<sizeOfArr)
    {
        if (itemArr[count].value==value)
        {
            itemArr[count].number++;
            return 1;
        }
        count++;
    }
    if (sizeOfArr==DEFAULT_MAX_ITEMS) return 0;
    itemArr[sizeOfArr].value=value;
    itemArr[sizeOfArr].number=1;
    sizeOfArr++;
    return 1;
}
// Unordered;

int Multiset::erase(const ItemType& value)
{
    int count=0;
    while (count<sizeOfArr)
    {
        if (this->itemArr[count].value==value)
        {
            this->itemArr[count].number--;
            if (itemArr[count].number==0)
            {
                itemArr[count]=itemArr[sizeOfArr-1];
                sizeOfArr--;
            }
            return 1;
        }
        count++;
    }
    return 0;
}

/* Used for ordered
int Multiset::eraseAll(const ItemType& value)
{
    int count=0;
    while (count<DEFAULT_MAX_ITEMS)
    {
        if (this->itemArr[count].value==value)
        {
            if (count==DEFAULT_MAX_ITEMS-1)
                itemArr[count].number=0;
            else    // Sort again;
            {
                do
                {
                    itemArr[count].value=itemArr[count+1].value;
                    itemArr[count].number=itemArr[count+1].number;
                    count++;
                }
                while (itemArr[count].number!=0);
            }
            return 1;
        }
        count++;
    }
    return 0;
}
 */

int Multiset::eraseAll(const ItemType& value)
{
    int count=0;
    int num;
    while (count<sizeOfArr)
    {
        if (itemArr[count].value==value)
        {
            num=itemArr[count].number; //Correct
            itemArr[count]=itemArr[sizeOfArr-1];
            sizeOfArr--;
            return num;
        }
        count++;
    }
    return 0;
}

bool Multiset::contains(const ItemType& value) const
{
    int count=0;
    while (count<sizeOfArr)
    {
        if (this->itemArr[count].value==value)
            return 1;
        count++;
    }
    return 0;
}


int Multiset::count(const ItemType& value) const
{
    int count=0;
    while (count<sizeOfArr)
    {
        if (this->itemArr[count].value==value)
            return itemArr[count].number;
        count++;
    }
    return 0;
}

int Multiset::get(int i, ItemType& value) const
{
    if (i<0 || i>=sizeOfArr) return 0;
    value = itemArr[i].value;
    return itemArr[i].number;
}

bool Multiset::getLeastFrequentValue(ItemType& value) const
{
    int count=1;
    int count2=0; // Method1
    bool yes=0;
    if (this->empty()) return 0;
    if (this->uniqueSize()==1)
    {
        value=itemArr[0].value;
        return 1;
    } // Correct.
    while (count<sizeOfArr)
    {
        if (this->itemArr[count].number<itemArr[count2].number)
        {
            count2=count;
            yes=1;
        }
        else if (itemArr[count].number==itemArr[count2].number)
            yes=0;
        count++;
    }
    if (yes)
        value = itemArr[count2].value;
    return yes;
}


 bool Multiset::getSmallestValue(ItemType& value) const
{
    int count=1;
    ItemType small=itemArr[0].value; // Method2
    if (this->empty()) return 0;
    while (count<sizeOfArr)
    {
        if (this->itemArr[count].value<small)
        {
            small=itemArr[count].value;
        }
        count++;
    }
    value = small;
    return 1;
}

// Used for unsorted arrays.

/* Used for ordered
bool Multiset::getSmallestValue(ItemType& value) const
{
    if (this->empty()) return 0;
    value = itemArr[0].value;
    return 1;
}
 */



bool Multiset::getSecondSmallestValue(ItemType& value) const
{
    if (this->uniqueSize()<2) return 0;
    int count=2;
    ItemType small=itemArr[1].value;
    ItemType small2=itemArr[0].value;
    ItemType temp;
    if (small2<small)
    {
        temp=small2;
        small2=small;
        small=temp;
    }
    while (count<sizeOfArr)
    {
        if (this->itemArr[count].value<small2)
        {
            if (itemArr[count].value<small)
            {
                small2=small;
                small=itemArr[count].value;
            }
            else
            {
                small2=itemArr[count].value;
            }
        }
        count++;
    }
    value = small2;
    return 1;
}

// Used for unsorted arrays;

/* Used for sorted
bool Multiset::getSecondSmallestValue(ItemType& value) const
{
    if (this->empty() || itemArr[1].number==0) return 0;
    value = itemArr[1].value;
    return 1;
}
 */

bool Multiset::replace(ItemType original, ItemType newvalue)
{
    int count=0;
    int positionOfNew=-1;
    int positionOfOriginal;
    if (original==newvalue) return 1;
    while (count<sizeOfArr)
    {
        if (itemArr[count].value==newvalue)
            positionOfNew=count;
        if (this->itemArr[count].value==original)
        {
            positionOfOriginal=count;
            if (positionOfNew<0)
            {
                while (count<sizeOfArr)
                {
                    if (itemArr[count].value==newvalue)
                        positionOfNew=count;
                    count++;
                }
            }
            if (positionOfNew<0)
            {
                itemArr[positionOfOriginal].value=newvalue;
                return 1;
            }
            else
            {
                itemArr[positionOfNew].number += itemArr[positionOfOriginal].number;
                itemArr[positionOfOriginal]=itemArr[--sizeOfArr];
                return 1;
            }
        }
        count++;
    }
    return 0;
}


int Multiset::countIf(char op, ItemType value) const
{
    int count=0;
    int count2=0;
    switch (op)
    {
        case '<':
        {
            while (count<sizeOfArr)
            {
                if (itemArr[count].value<value)
                    count2+=itemArr[count].number;
                count++;
            }
            return count2;
        }
        case '=':
        {
            while (count<sizeOfArr)
            {
                if (itemArr[count].value==value)
                    count2+=itemArr[count].number;
                count++;
            }
            return count2;
        }
        case '>':
        {
            while (count<sizeOfArr)
            {
                if (itemArr[count].value>value)
                    count2+=itemArr[count].number;
                count++;
            }
            return count2;
        }
        default: {return -1;}
    }
}

void Multiset::swap(Multiset& other)
{
    Item temp;
    for (int i=0; i<this->sizeOfArr || i<other.sizeOfArr; i++)
    {
        temp=this->itemArr[i];
        this->itemArr[i]=other.itemArr[i];
        other.itemArr[i]=temp;
    }
    int temp2;
    temp2=this->sizeOfArr;
    this->sizeOfArr=other.sizeOfArr;
    other.sizeOfArr=temp2;
}

void Multiset::copyIntoOtherMultiset(Multiset &other) const
{
    int j;
    for (int i=0; i<this->sizeOfArr; i++)
    {
        j=0;
        while (j<other.sizeOfArr)
        {
            if (itemArr[i].value==other.itemArr[j].value)
            {
                other.itemArr[j].number+=this->itemArr[i].number;
                break;
            }
            j++;
        }
        if (j==other.sizeOfArr)
        {
            if (other.sizeOfArr==DEFAULT_MAX_ITEMS) continue;
            other.itemArr[other.sizeOfArr].value=this->itemArr[i].value;
            other.itemArr[other.sizeOfArr].number=this->itemArr[i].number;
            other.sizeOfArr++;
        }
    }
}


