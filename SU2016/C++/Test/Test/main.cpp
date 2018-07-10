//
//  main.cpp
//  Test
//
//  Created by 景思阳 on 16/5/26.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

int _n = 0;

int sqr(int n, int bits) {
    _n++;
    int half;
    if (bits == 1)
        return n & 1;
    half = n >> 1;
    if (n & 1)
        return ((sqr(half,bits-1) + half)<<2) + 1;
    else
        return sqr(half,bits-1)<<2;
}

int fib(int n)
{
    _n++;
    if (n<2)
        return n;
    else return fib(n-1)+fib(n-2);
}

int main()
{
    cout<<fib(8)<<endl<<_n<<endl;
}