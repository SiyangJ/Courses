//
//  Game.hpp
//  Project_1
//
//  Created by apple on 6/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Game_h
#define Game_h

class Pit;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nSnakes);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Pit* m_pit;
};

#endif /* Game_h */
