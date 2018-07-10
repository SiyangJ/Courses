//
//  test_2.cpp
//  Project2
//
//  Created by apple on 7/8/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cassert>
#include "Multiset.h"

using namespace std;

int main()
{
    Multiset ms1,ms2;
    ms1.insert("123");
    ms1.insert("123");
    ms1.insert("456");
    ms1.insert("789");
    ms2=ms1;
    ms1.insert("333");
    ms2.insert("123");
    ms2.insert("000");
    ms1.copyIntoOtherMultiset(ms1);
    Multiset ms3(ms2);
}