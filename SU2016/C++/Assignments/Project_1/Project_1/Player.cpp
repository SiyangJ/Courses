//
//  Player.cpp
//  Project_1
//
//  Created by apple on 6/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "Pit.h"

int decodeDirection(char dir);
bool directionToDeltas(int dir, int& rowDelta, int& colDelta);


///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(Pit* pp, int r, int c)
{
    if (pp == nullptr)
    {
        std::cout << "***** The player must be in some Pit!" << std::endl;
        exit(1);
    }
    if (r < 1  ||  r > pp->rows()  ||  c < 1  ||  c > pp->cols())
    {
        std::cout << "**** Player created with invalid coordinates (" << r
        << "," << c << ")!" << std::endl;
        exit(1);
    }
    m_pit = pp;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    return m_col;
}

int Player::age() const
{
    return m_age;
}

void Player::stand()
{
    m_age++;
}

void Player::move(int dir)
{
    m_age++;
    int maxCanMove = 0;  // maximum distance player can move in direction dir
    switch (dir)
    {
        case UP:     maxCanMove = m_row - 1;             break;
        case DOWN:   maxCanMove = m_pit->rows() - m_row; break;
        case LEFT:   maxCanMove = m_col - 1;             break;
        case RIGHT:  maxCanMove = m_pit->cols() - m_col; break;
    }
    if (maxCanMove == 0)  // against wall
        return;
    int rowDelta;
    int colDelta;
    if ( ! directionToDeltas(dir, rowDelta, colDelta))
        return;
    
    // No adjacent snake in direction of movement
    
    if (m_pit->numberOfSnakesAt(m_row + rowDelta, m_col + colDelta) == 0)
    {
        m_row += rowDelta;
        m_col += colDelta;
        m_pit->history().record(m_row,m_col);
        return;
    }
    
    // Adjacent snake in direction of movement, so jump
    
    if (maxCanMove >= 2)  // need a place to land
    {
        m_pit->destroyOneSnake(m_row + rowDelta, m_col + colDelta);
        m_row += 2 * rowDelta;
        m_col += 2 * colDelta;
        if (m_pit->numberOfSnakesAt(m_row, m_col) > 0)  // landed on a snake!
            setDead();
        else
            m_pit->history().record(m_row,m_col);
    }
}

bool Player::isDead() const
{
    return m_dead;
}

void Player::setDead()
{
    m_dead = true;
}

