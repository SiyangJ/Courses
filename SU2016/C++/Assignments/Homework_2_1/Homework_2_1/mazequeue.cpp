//
//  mazequeue.cpp
//  Homework_2_1
//
//  Created by apple on 7/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc): m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    queue<Coord> stk;
    Coord ptr(sr,sc);
    stk.push(ptr);
    maze[sr][sc]='1';
    while (!stk.empty())
    {
        ptr=stk.front();
        stk.pop();
        if (ptr.r()==er && ptr.c()==ec)
            return 1;
        if (maze[ptr.r()-1][ptr.c()]=='.')
        {
            stk.push(Coord(ptr.r()-1, ptr.c()));
            maze[ptr.r()-1][ptr.c()]='1';
        }
        if (maze[ptr.r()][ptr.c()+1]=='.')
        {
            stk.push(Coord(ptr.r(), ptr.c()+1));
            maze[ptr.r()][ptr.c()+1]='1';
        }
        if (maze[ptr.r()+1][ptr.c()]=='.')
        {
            stk.push(Coord(ptr.r()+1, ptr.c()));
            maze[ptr.r()+1][ptr.c()]='1';
        }
        if (maze[ptr.r()][ptr.c()-1]=='.')
        {
            stk.push(Coord(ptr.r(), ptr.c()-1));
            maze[ptr.r()][ptr.c()-1]='1';
        }
    }
    return 0;
}

