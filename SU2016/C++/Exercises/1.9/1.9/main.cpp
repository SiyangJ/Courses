//
//  main.cpp
//  1.9
//
//  Created by 景思阳 on 16/5/30.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int numCoupons;
    const int couponForCandy = 10;
    const int couponForGumball = 3;
    cout << "Please enter the number of coupons: ";
    cin >> numCoupons;
    
    cout << "You can get " << (numCoupons/couponForCandy) << " candy bars and " << ((numCoupons%couponForCandy)/couponForGumball) << " gumballs.\n";
    
    return 0;
}
