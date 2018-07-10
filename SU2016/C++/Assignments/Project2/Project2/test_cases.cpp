//
//  test_cases.cpp
//  Project2
//
//  Created by apple on 7/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifdef TESTNEW
#include "newMultiset.h"
#else
#include "Multiset.h"
#endif

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <type_traits>
#include <cassert>
using namespace std;

static ItemType DUMMY = "123";
static ItemType DEFAULT = "0";
static ItemType ARRAY[6] = {"10","20","30","40","50","60" };
int main(){
// Preparation
    Multiset m, n;     // Default constructor
assert((is_same<decltype(&Multiset::empty),bool (Multiset::*)() const>::value));       // Type and other keywords of empty
assert((is_same<decltype(&Multiset::size),int (Multiset::*)() const>::value));         // Type and other keywords of size
assert((is_same<decltype(&Multiset::uniqueSize),int (Multiset::*)() const>::value));   // Type and other keywords of uniqueSize
assert((is_same<decltype(&Multiset::contains),bool (Multiset::*)(const ItemType&) const>::value));      // Type and other keywords of contains
assert((is_same<decltype(&Multiset::count),int (Multiset::*)(const ItemType&) const>::value));          // Type and other keywords of count
assert((is_same<decltype(&Multiset::get),int (Multiset::*)(int, ItemType&) const>::value));             // Type and other keywords of get
assert((is_same<decltype(&Multiset::getLeastFrequentValue),bool (Multiset::*)(ItemType&) const>::value));            // Type and other keywords of getLeastFrequentValue
assert((is_same<decltype(&Multiset::getSmallestValue),bool (Multiset::*)(ItemType&) const>::value));                 // Type and other keywords of getSmallestValue
assert((is_same<decltype(&Multiset::getSecondSmallestValue),bool (Multiset::*)(ItemType&) const>::value));           // Type and other keywords of getSecondSmallestValue
assert((is_same<decltype(&Multiset::countIf),int (Multiset::*)(char, ItemType) const>::value));                      // Type and other keywords of countIf
assert((is_same<decltype(&Multiset::copyIntoOtherMultiset),void (Multiset::*)(Multiset&) const>::value));            // Type and other keywords of copyIntoOtherMultiset
// When empty
assert(m.empty());                         // empty
assert(m.size() == 0);                     // size
assert(m.uniqueSize() == 0);               // uniqueSize
assert(m.erase(DEFAULT) == 0  &&  m.size() == 0);          // erase
assert(m.eraseAll(DEFAULT) == 0  &&  m.size() == 0);       // eraseAll
assert(!m.contains(DEFAULT));                              // contains
assert(m.count(DEFAULT) == 0);                             // count
ItemType x = DUMMY;
assert(m.get(0, x) == 0 && x==DUMMY);                      // get
assert(!m.getLeastFrequentValue(x) && x==DUMMY);           // getLeastFrequentValue
assert(!m.getSmallestValue(x) && x==DUMMY);                // getSmallestValue
assert(!m.getSecondSmallestValue(x) && x==DUMMY);          // getSecondSmallestValue
assert(!m.replace(DEFAULT, ARRAY[0]) && m.empty());        // replace
assert(m.countIf('@', DEFAULT) == -1);                     // countIf with wrong input
assert(m.countIf('=', DEFAULT) == 0 && m.countIf('<', DEFAULT) == 0 && m.countIf('>', DEFAULT) == 0);                // countIf
m.swap(n);
assert(m.empty() && n.empty());
m.copyIntoOtherMultiset(n);
assert(n.empty());                 // copyIntoOtherMultiset
Multiset o(n);                     // copy constructor
assert(o.empty());
combine(m, n, o);
assert(o.empty());                 // combine
subtract(m, n, o);
assert(o.empty());                 // subtract
assert(m.insert(DUMMY));           // insert

// When not empty
assert(!m.empty());                // empty
assert(m.size() == 1);             // size
assert(m.uniqueSize() == 1);       // uniqueSize when single
assert(m.contains(DUMMY));         // contains
assert(m.count(DUMMY) == 1);       // count
assert(m.erase(DUMMY) && m.empty());                 // erase
m.insert(ARRAY[0]);
assert(m.get(0, x) == 1 && x==ARRAY[0]);             // get
x=DUMMY;
assert(m.get(-1,x)==0 && x==DUMMY);
assert(m.get(2,x)==0 && x==DUMMY);
assert(m.getLeastFrequentValue(x) && x==ARRAY[0]);   // getLeastFrequentValue when single
x=DUMMY;
assert(m.getSmallestValue(x) && x==ARRAY[0]);        // getSmallestValue when single
x=DUMMY;
assert(!m.getSecondSmallestValue(x) && x==DUMMY);    // getSecondSmallestValue when single
assert(!m.replace(ARRAY[1], ARRAY[2]));              // replace when no original
assert(m.size() == 1  &&  m.count(ARRAY[0]) == 1  &&  m.count(ARRAY[2]) == 0);
assert(m.replace(ARRAY[0], ARRAY[1]));               // replace when has original
assert(m.size() == 1  &&  m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[0]) == 0);
assert(m.replace(ARRAY[1], ARRAY[1]));               // replace aliasing
assert(m.size() == 1  &&  m.uniqueSize() == 1  &&  m.count(ARRAY[1]) == 1);
assert(m.countIf('=', ARRAY[1]) == 1 && m.countIf('<', ARRAY[1]) == 0 && m.countIf('>', ARRAY[1]) == 0);                // countIf
assert(m.insert(ARRAY[0]) && m.insert(ARRAY[0]) && m.size()==3 && m.uniqueSize()==2);    // insert when multiple
assert(m.contains(ARRAY[0]) && m.contains(ARRAY[1]) && !m.contains(ARRAY[2]));           // contains when multiple
assert(m.countIf('<', ARRAY[2])==3);                 // countIf when multiple
assert(m.getSecondSmallestValue(x) && x==ARRAY[1]);  // getSecondSmallestValue when multiple
assert(m.getSmallestValue(x) && x == ARRAY[0]);      // getSmallestValue when multiple
m.swap(n);
assert(m.empty() && n.count(ARRAY[0])==2 && n.uniqueSize()==2);       // swap
n.swap(m);
Multiset p(m);                                                        // copy constructor
assert(p.size()==3 && p.uniqueSize()==2);
n=p;
assert(n.get(0,x)==1 && x==ARRAY[1] && n.uniqueSize()==2);            // assign operator
p=p;
assert(p.get(1,x)==2 && x==ARRAY[0] && p.uniqueSize()==2);            // assign operator aliasing
combine(n,p,o);
assert(o.size()==6 && o.uniqueSize()==2);                             // combine
subtract(n,m,o);
assert(o.empty()); // subtract
combine(n,n,o);
assert(o.size()==6 && o.uniqueSize()==2);                             // combine aliasing
subtract(n,n,o);
assert(o.empty());                                                    // subtract aliasing
combine(n,p,n);
assert(n.size()==6 && n.uniqueSize()==2);                             // combine aliasing
p.insert(ARRAY[2]);
p.insert(ARRAY[1]);
p.insert(ARRAY[1]);
subtract(n,p,n);
assert(n.size()==2 && n.uniqueSize()==1 && !n.contains(ARRAY[2]) && !n.contains(ARRAY[1]));    // subtract aliasing
p.insert(ARRAY[0]);
p.erase(ARRAY[2]);
assert(!p.getLeastFrequentValue(x=DUMMY) && x==DUMMY);                                         // getLeastFrequentValue when none
p.insert(ARRAY[2]);
assert(p.eraseAll(ARRAY[1])==3 && p.uniqueSize()==2 && p.get(0,x) && x==ARRAY[0]);             // eraseAll when multiple
p.insert(ARRAY[1]);
assert(!p.eraseAll(ARRAY[3]));
p.copyIntoOtherMultiset(n);                                           // copyIntoOtherMultiset
assert(n.count(ARRAY[0])==5 && n.uniqueSize()==3);
p.copyIntoOtherMultiset(p);                                           // copyIntoOtherMultiset aliasing
assert(p.uniqueSize()==3 && p.size()==10);
p.swap(m);                                                            // swap
assert(m.uniqueSize()==3 && m.size()==10 && !p.contains(ARRAY[2]));
m.swap(m);                                                            // swap aliasing
assert(m.uniqueSize()==3 && m.size()==10);
}