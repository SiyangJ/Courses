//
//  main.cpp
//  Homework_2_1
//
//  Created by apple on 7/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//
#include <iostream>
using namespace std;

bool pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X.......@X",
        "XX@X@@.XXX",
        "X..X.X...X",
        "X..X...@.X",
        "X....XXX.X",
        "X@X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}