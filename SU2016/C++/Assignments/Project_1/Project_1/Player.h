//
//  Player.hpp
//  Project_1
//
//  Created by apple on 6/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Player_h
#define Player_h

class Pit;

class Player
{
public:
    // Constructor
    Player(Pit *pp, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    void   stand();
    void   move(int dir);
    void   setDead();
    
private:
    Pit*  m_pit;
    int   m_row;
    int   m_col;
    int   m_age;
    bool  m_dead;
};

#endif /* Player_h */
