//
//  main.cpp
//  Linked_List
//
//  Created by apple on 7/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include "linked_list.hpp"

using namespace std;

int main()
{
    LikedList ll1;
    ll1.Add(1);
    ll1.Add(2);
    ll1.Add(3);
    cin.get();
    ll1.PrintList();
    ll1.Reverse();
    ll1.PrintList();
    cin.get();
    return 0;
}
