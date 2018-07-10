//
//  main.cpp
//  3.11
//
//  Created by 景思阳 on 6/1/16.
//  Copyright © 2016 景思阳. All rights reserved.
//

#include <iostream>
using namespace std;

int dice()
{
    return rand()%6+1;
}

int humanTurn (int humanTotalScore)
{
    string ans;
    int currentNumber;
    int scoreThisTurn = humanTotalScore;
    while(1)
    {
        cout << "Roll? (y/n)\n";
        cin >> ans;
        if (ans == "n" or ans == "N")
        {
            cout << "Your turn ended.\n" << "Your total score is " << scoreThisTurn << ".\n";
            return scoreThisTurn;
        }
        else if (ans == "y" or ans == "Y")
        {
            currentNumber = dice();
            cout << "You rolled " << currentNumber << "!\n";
            if (currentNumber == 1)
            {
                cout << "Your turn ended.\n" << "Your total score is " << humanTotalScore << ".\n";
                return humanTotalScore;
            }
            scoreThisTurn += currentNumber;
            cout << "You have " << scoreThisTurn << " points now.\n";
        }
        else cout << "Error: wrong input!";
    }
        
}

int computerTurn(int computerTotalScore)
{
    int currentNumber;
    int scoreThisTurn = 0;
    while(computerTotalScore < 100 && scoreThisTurn < 20)
    {
    
        currentNumber = dice();
        cout << "Computer rolled " << currentNumber << ".\n";
        if (currentNumber == 1)
        {
            computerTotalScore -= scoreThisTurn;
            break;
        }
        else
        {
            scoreThisTurn += currentNumber;
            computerTotalScore += currentNumber;
            cout << "Computer's total score is now " << computerTotalScore << ".\n";
        }
    }
    
    cout << "Computer's turn ended.\n" << "Computer's total score is now " << computerTotalScore << ".\n";
    return computerTotalScore;
}

int main() {
    
    int humanTotalScore = 0;
    int computerTotalScore = 0;
    
    while(1)
    {
        humanTotalScore = humanTurn(humanTotalScore);
        if (humanTotalScore >= 100)
        {
            cout << "You win!\n";
            break;
        }
        computerTotalScore = computerTurn(computerTotalScore);
        if (computerTotalScore >= 100)
        {
            cout << "You lose!\n";
            break;
        }
    }
    return 0;
}
