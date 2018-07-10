//
//  main.cpp
//  2.5
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    for (int O = 1; O <= 9; O++)
    {
        for (int T = 2; T <= 9; T++)
        {
            if (T == O)
                continue;
            else
            {
            int OO = O*11;
            int TOO = T*100+OO;
            int GOOD = 4*TOO;
            int G = GOOD/1000;
            int D = GOOD%10;
            
            if ((GOOD/10)%100 != OO or D == G or D == T or G == T or G == O)
                continue;
            else
                cout << "T=" << T << ", O=" << O << ", G=" << G << ", D=" << D << ".\n";
            }
        }
    }
    return 0;
}
