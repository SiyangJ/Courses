//
//  main.cpp
//  2.7
//
//  Created by 景思阳 on 16/5/31.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int numExercises,
        score,
        totalScorePossible = 0,
        totalScoreReceived = 0;
    cout << "How many exercises to input? ";
    cin >> numExercises;
    
    for (int count = 1; count <= numExercises; count++)
    {
        cout << "Score received for exercise " << count << ": ";
        cin >> score;
        totalScoreReceived += score;
        cout << "Total points possible for exercise " << count << ": ";
        cin >> score;
        totalScorePossible += score;
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Your total is " << totalScoreReceived << " out of " << totalScorePossible << ", or "
         << static_cast<double>(totalScoreReceived)/totalScorePossible*100 << "%.\n";
    
    return 0;
}
