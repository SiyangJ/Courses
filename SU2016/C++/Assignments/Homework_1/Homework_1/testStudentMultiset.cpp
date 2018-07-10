//
//  testStudentMultiset.cpp
//  Homework_1
//
//  Created by apple on 6/29/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "StudentMultiset.h"
#include <iostream>

using namespace std;


int main()
{
    StudentMultiset MS;
    MS.add(12345);
    MS.add(12345);
    MS.add(12345);
    MS.add(54321);
    MS.add(54321);
    StudentMultiset MS_2 = MS;
    int size=MS.size();
    MS_2.print();
    exit (0);
}
