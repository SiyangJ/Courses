//
//  main.cpp
//  5.12
//
//  Created by 景思阳 on 6/6/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>

using namespace std;

const int PARAMETER_1 = 80, PARAMETER_2 = 22;

void getInitial(bool world[][PARAMETER_2])
{
    int count = 1;
    int limit = PARAMETER_1*PARAMETER_2;
    int pointer1, pointer2;
    while(1)
    {
        if (count++>limit)
        {
            cout << "You have filled the whole world with LIFEs!\n";
            break;
        }
        else
        {
            cout << "Please enter the position of a new LIFE, enter 99 99 to stop:\n";
            cin >> pointer1 >> pointer2;
            if (pointer1 == 99 && pointer2 == 99)
                break;
            if (pointer1>=PARAMETER_1 or pointer2>=PARAMETER_2)
            {
                cout << "This position is outside the world!\n";
                count--;
            }
            else if (world[pointer1][pointer2])
            {
                cout << "A LIFE already occupies this position!\n";
                count--;
            }
            else
            {
                world[pointer1][pointer2] = 1;
            }
        }
    }
}

bool examine0(int var1, int var2, bool world[][PARAMETER_2])
{
    int count = 0;
    int current1;
    int current2;
    for (int i=-1; i<=1; i++)
    {
        current1 = var1+i;
        if (current1>=0 && current1<PARAMETER_1)
        {
        for (int j=-1; j<=1; j++)
        {
            current2 = var2+j;
            if (!(i==0 && j==0))
            {
            if (current2>=0 && current2<PARAMETER_2)
            {
                count += world[current1][current2];
            }
            }
        }
        }
    }
    if (count>=3)
        return 1;
    else
        return 0;
    
}

bool examine1(int var1, int var2, bool world[][PARAMETER_2])
{
    int count = 0;
    int current1;
    int current2;
    for (int i=-1; i<=1; i++)
    {
        current1 = var1+i;
        if (current1>=0 && current1<PARAMETER_1)
        {
            for (int j=-1; j<=1; j++)
            {
                current2 = var2+j;
                if (!(i==0 && j==0))
                {
                    if (current2>=0 && current2<PARAMETER_2)
                    {
                        count += world[current1][current2];
                    }
                }
            }
        }
    }
    if (count>1 && count<4)
        return 1;
    else
        return 0;
}

void generation(bool world[][PARAMETER_2])
{
    bool world2[PARAMETER_1][PARAMETER_2] = {0};
    for (int count1=0; count1<PARAMETER_1; count1++)
    {
        for (int count2=0; count2<PARAMETER_2; count2++)
        {
            if(world[count1][count2])
                world2[count1][count2] = examine1(count1, count2, world);
            else
                world2[count1][count2] = examine0(count1, count2, world);
        }
    }
    for (int count1=0; count1<PARAMETER_1; count1++)
    {
        for (int count2=0; count2<PARAMETER_2; count2++)
        {
            world[count1][count2] = world2[count1][count2];
        }
    }
}

void display(bool world[][PARAMETER_2])
{
    for (int count1=0; count1<PARAMETER_2; count1++)
    {
        for (int count2=0; count2<PARAMETER_1; count2++)
        {
            if (world[count2][count1])
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    bool world[PARAMETER_1][PARAMETER_2] = {0};
    char ans = 'y';
    int count = 1;
    getInitial(world);
    display(world);
    cout << "This is how our story begins!\n";
    do
    {
        generation(world);
        cout << "Welcome to generation " << ++count << "!\n";
        display(world);
        cout << "Wanna see the next generation? (y/n)\n";
        cin >> ans;
    }
    while (ans == 'y' or ans == 'Y');
    return 0;
}
