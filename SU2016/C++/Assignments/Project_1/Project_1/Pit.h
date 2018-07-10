//
//  Pit.hpp
//  Project_1
//
//  Created by apple on 6/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Pit_h
#define Pit_h

#include "History.h"
#include <string>
#include "globals.h"

class Snake;
class Player;

class Pit
{
public:
    // Constructor/destructor
    Pit(int nRows, int nCols);
    ~Pit();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     snakeCount() const;
    int     numberOfSnakesAt(int r, int c) const;
    void    display(std::string msg) const;
    
    // Mutators
    bool   addSnake(int r, int c);
    bool   addPlayer(int r, int c);
    bool   destroyOneSnake(int r, int c);
    bool   moveSnakes();
    
    History& history();
    
private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Snake*  m_snakes[MAXSNAKES];
    int     m_nSnakes;
    History m_history;
};


#endif /* Pit_h */
