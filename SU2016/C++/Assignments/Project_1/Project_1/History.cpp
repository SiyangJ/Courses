//
//  History.cpp
//  Project_1
//
//  Created by apple on 6/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "History.h"
#include <iostream>

using namespace std;

void clearScreen();

History::History(int nRows, int nCols)
{
    m_nRows = nRows;
    m_nCols = nCols;
    m_history = new charptr[nRows];
    for (int i=0; i<nRows; i++)
    {
        m_history[i] = new char[nCols];
        for (int j=0; j<nCols; j++)
            m_history[i][j] = '.';
    }
}

History::~History()
{
    for (int i=0; i<m_nRows; i++)
    {
        delete [] m_history[i];
    }
    delete [] m_history;
}

bool History::record(int r, int c)
{
    if (r>m_nRows || r<1 || c>m_nCols || c<1)
        return 0;
    else
    {
        if (m_history[r-1][c-1]=='.')
        {
            m_history[r-1][c-1]='A';
        }
        else if (! (m_history[r-1][c-1]=='Z'))
        {
            m_history[r-1][c-1]++;
        }
    }
        return 1;
}

void History::display() const
{
    clearScreen();
    for (int r = 0; r < m_nRows; r++)
    {
        for (int c = 0; c < m_nCols; c++)
            cout << m_history[r][c];
        cout << endl;
    }
    cout << endl;
}