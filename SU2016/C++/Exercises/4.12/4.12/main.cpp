//
//  main.cpp
//  4.12
//
//  Created by 景思阳 on 6/2/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    
    int count, countA, countB, countC;
    const int limit = 10000, probA = 3, probB = 2, probC = 1;
    //C>B>A
    bool result, a, b, c;
    char ans;
    do
    {
        a = 1; b = 1; c = 1;
        countA = 0;
        countB = 0;
        
        for (count=1; count<=limit; count++)
        {
            do
            {//Aaron's turn
            result = rand()%probA;
            if (c)
                c = result;
            else
                b = result;
            if (!(b or c))
            {
                countA++;
                break;
            }
            //Bob's turn
            result = rand()%probB;
            if (c)
                c = result;
            else
                a = result;
            if (!(a or c))
            {
                countB++;
                break;
            }
            //Charlie's turn
            result = rand()%probC;
            if (b)
                b = result;
            else
                a = result;
            if (!(b or c))
            {
                break;
            }
            }
            while (1);
        }
        
        countC = limit-countA-countB;
        
        cout << "Aaron won " << countA << "/" << limit << " duels or " << countA/static_cast<double>(limit)*100 << "%.\n"
             << "Bob won " << countB << "/" << limit << " duels or " << countB/static_cast<double>(limit)*100 << "%.\n"
             << "Charlie won " << countC << "/" << limit << " duels or " << countC/static_cast<double>(limit)*100 << "%.\n";
        
        cout << "Run again? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    
    return 0;
}
