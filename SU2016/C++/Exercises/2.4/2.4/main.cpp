//
//  main.cpp
//  2.4
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    const int min = 3, max = 100;
    
    for (int count = min; count <= max; count++)
    {
        int count2 = 1;
        double limit = sqrt(count);
        bool primeOrNot = true;
        while (++count2 <= limit)
        {
            if (count%count2 == 0)
            {
                primeOrNot = false;
                break;
            }
        }
        if (primeOrNot)
            cout << count << " is a prime number.\n";
    }
    
    return 0;
}
