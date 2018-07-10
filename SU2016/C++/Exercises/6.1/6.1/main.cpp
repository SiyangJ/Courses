//
//  main.cpp
//  6.1
//
//  Created by apple on 6/21/16.
//  Copyright © 2016 UNC. All rights reserved.
//

#include <iostream>

using namespace std;

class ScoreRecord
{
public:
    void input();
    void output();
private:
    double quiz1, quiz2, midterm, final;
    const double QUIZ_PERCENT = 12.5, MIDTERM_PERCENT = 25, FINAL_PERCENT = 50, QUIZ_FULL = 10, MID_FIN_FULL = 100;
    const double MIN_A = 90, MIN_B = 80, MIN_C = 70, MIN_D = 60;
};

void ScoreRecord::input()
{
    cout << "Please enter the quiz scores, midterm score and final score:\n";
    cin >> quiz1 >> quiz2 >> midterm >> final;
}

void ScoreRecord::output()
{
    double finalScore = (quiz1+quiz2)/QUIZ_FULL*QUIZ_PERCENT+midterm/MID_FIN_FULL*MIDTERM_PERCENT+final/MID_FIN_FULL*FINAL_PERCENT;
    char letter;
    if (finalScore>=MIN_A)
        letter = 'A';
    else if (finalScore>=MIN_B)
        letter = 'B';
    else if (finalScore>=MIN_C)
        letter = 'C';
    else if (finalScore>=MIN_D)
        letter = 'D';
    else
        letter = 'F';
    cout << "The final score is " << finalScore << ", " << letter << ".\n";
}

int main()
{
    ScoreRecord record;
    record.input();
    record.output();
    return 0;
}
