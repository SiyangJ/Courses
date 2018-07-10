//
//  StudentMultiset.cpp
//  Homework_1
//
//  Created by apple on 6/29/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "StudentMultiset.h"
#include <iostream>

StudentMultiset::StudentMultiset()
{
}

bool StudentMultiset::add(unsigned long id)
{
    return m_ms.insert(id);
}

int StudentMultiset::size() const
{
    return m_ms.size();
}

void StudentMultiset::print() const
{
    int limit=this->size();
    int num;
    unsigned long id;
    for (int count=0; count<limit; count++)
    {
        num=m_ms.get(count, id);
        for (int count2=0; count2<num; count2++)
            std::cout << id << std::endl;
    }
}