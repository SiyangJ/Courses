//
//  History.hpp
//  Project_1
//
//  Created by apple on 6/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef History_h
#define History_h

typedef char* charptr;

class History
{
public:
    History(int nRows, int nCols);
    ~History();
    bool record(int r, int c);
    void display() const;
private:
    int m_nRows;
    int m_nCols;
    charptr* m_history;
    
};

#endif /* History_h */
