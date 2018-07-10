//
//  testnewMultiset.cpp
//  Homework_1
//
//  Created by apple on 6/29/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "newMultiset.h"
#include <cassert>
#include <iostream>

using namespace std;


int main()
{
    Multiset a(1000);   // a can hold at most 1000 distinct items
    Multiset b(5);      // b can hold at most 5 distinct items
    Multiset c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
    ItemType v[6] = {1,2,3,4,5,6};
        // No failures inserting 5 distinct items twice each into b
        for (int k = 0; k < 5; k++)
        {
            assert(b.insert(v[k]));
            assert(b.insert(v[k]));
        }
        assert(b.size() == 10  &&  b.uniqueSize() == 5  &&  b.count(v[0]) == 2);
        // Failure if we try to insert a sixth distinct item into b
        assert(!b.insert(v[5]));

        // When two Multisets' contents are swapped, their capacities are swapped
        // as well:
        a.swap(b);
        assert(!a.insert(v[5])  &&  b.insert(v[5]));
    cout << "Passed." << endl;
    exit (0);
}