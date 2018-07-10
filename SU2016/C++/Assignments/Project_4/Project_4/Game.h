//
//  Game.h
//  Project_4
//
//  Created by apple on 8/5/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <vector>
#include <string>

class Game
{
public:
    Game(const std::vector<std::string> &words);
    bool setSecretWord(const std::string &sw);
    int secretWordLength() const
    {return m_secretWord.size();}
    void probe(const std::string &probeWord, int &nInRightPlace, int &nInWrongPlace);
    ~Game();
private:
    // Prevent people from copying Game objects.
    Game(const Game&);
    Game& operator=(const Game&);
    // Define your own data structure here
    // ...
    std::vector<std::string> m_words;
    std::string m_secretWord;
};

#endif /* Game_h */
