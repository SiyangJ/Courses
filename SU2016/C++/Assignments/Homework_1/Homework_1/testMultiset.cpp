//
//  main.cpp
//  Homework_1
//
//  Created by apple on 6/28/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

/*
#include "Multiset.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    ItemType value;
    Multiset sms;
    assert(sms.insert("cumin"));
    assert(sms.insert("turmeric"));
    assert(sms.insert("cumin"));
    assert(sms.insert("coriander"));
    assert(sms.insert("cumin"));
    assert(sms.insert("turmeric"));
    assert(sms.size() == 6  &&  sms.uniqueSize() == 3);
    
    assert(sms.getSmallestValue(value) && value == "coriander");
    assert(sms.getSecondSmallestValue(value) && value == "cumin");
    assert(sms.getLeastFrequentValue(value) && value == "coriander");
    
    assert(sms.countIf('>',"cumin") == 2);
    assert(sms.countIf('=',"cumin") == 3);
    assert(sms.countIf('<',"cumin") == 1);
    
    assert(sms.count("turmeric") == 2);
    assert(sms.count("cumin") == 3);
    assert(sms.count("coriander") == 1);
    assert(sms.count("cardamom") == 0);
    
    assert(sms.replace("cumin","turmeric") && sms.count("turmeric") == 5);
    assert(!sms.contains("cumin"));
    assert(sms.uniqueSize()==2);
}

 
 
int main()
{
    test();
    cout << "Passed all tests" << endl;
}
 
 */



#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Multiset ms;
    assert(ms.empty());
    unsigned long x = 999;
    assert(ms.get(0, x) == 0  &&  x == 999);  // x unchanged by get failure
    assert( ! ms.contains(42));
    
    ms.insert(42);
    ms.insert(42);
    
    assert( ! ms.getSecondSmallestValue(x)  &&  x == 999 );
    assert(ms.size() == 2  &&  ms.uniqueSize() == 1);
    assert(ms.get(1, x) == 0  &&  x == 999);  // x unchanged by get failure
    assert(ms.get(0, x) == 2  &&  x == 42);
    
    assert(ms.getSmallestValue(x) && x == 42 );
    assert(ms.countIf('=',42) == 2);
    assert(ms.countIf('>',42) == 0);
    assert(ms.countIf('<',42) == 0);
    
    Multiset ms2;
    
    assert(ms2.uniqueSize()==0);
    
    //ms2.insert(42);
    //ms2.insert(41);
    ms.copyIntoOtherMultiset(ms2);
    
    assert(ms2.size()==2 && ms2.uniqueSize()==1);
    //assert(ms2.getSecondSmallestValue(x) && x==42);
    
    ms.swap(ms2);
    
    assert(ms2.size()==2 && ms.size()==2);
    assert(ms.get(0, x) && x==42);
    
    cout << "Passed all tests" << endl;
}
 
 /*

#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    ItemType value;
    Multiset ulms;
    assert(ulms.insert(20));
    assert(ulms.insert(10));
    assert(ulms.insert(20));
    assert(ulms.insert(30));
    assert(ulms.insert(20));
    assert(ulms.insert(10));
    assert(ulms.size() == 6  &&  ulms.uniqueSize() == 3);
    
    assert(ulms.getSmallestValue(value) && value == 10);
    assert(ulms.getSecondSmallestValue(value) && value == 20);
    assert(ulms.getLeastFrequentValue(value) && value == 30);
    
    assert(ulms.countIf('>',20) == 1);
    assert(ulms.countIf('=',20) == 3);
    assert(ulms.countIf('<',20) == 2);
    
    assert(ulms.count(10) == 2);
    assert(ulms.count(20) == 3);
    assert(ulms.count(30) == 1);
    assert(ulms.count(40) == 0);
    
    assert(ulms.replace(20,10) && ulms.count(10) == 5);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}
 
 */

