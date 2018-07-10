//
//  main.cpp
//  3.9
//
//  Created by 景思阳 on 6/1/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int dice()
{
    return rand()%6+rand()%6+2;
}

int main()
{
    srand(16);
    const int limit = 100000000;
    int numWin = 0;
    int numNow;
    int thePoint;
    for (int count = 1; count<=limit; count++)
    {
        numNow = dice();
        //cout << numNow << endl;
        if (numNow == 7 or numNow == 11)
            numWin++;
        else if (numNow == 2 or numNow == 3 or numNow == 12);
        else
        {
            thePoint = numNow;
            while(true)
            {
                numNow = dice();
                if (numNow == thePoint)
                {
                    numWin++;
                    break;
                }
                else if (numNow == 7)
                    break;
            }
            
        }
            
    }
    cout << "Probability of winning: " << numWin/static_cast<double>(limit) << endl;
    return 0;
}
