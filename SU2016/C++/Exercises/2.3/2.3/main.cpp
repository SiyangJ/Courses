//
//  main.cpp
//  2.3
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    const int couponsForBars = 7;
    int numCoupons;
    cout << "How much money do you have? $";
    cin >> numCoupons;
    int numTotalBars = numCoupons;
    
    while (numCoupons >= couponsForBars)
    {
        numTotalBars += numCoupons/couponsForBars;
        numCoupons = (numCoupons/couponsForBars + numCoupons%couponsForBars);
        
    }
    
    cout << "You can have " << numTotalBars << " chocolate bars and " << numCoupons << " leftover coupons";
    
    return 0;
}
