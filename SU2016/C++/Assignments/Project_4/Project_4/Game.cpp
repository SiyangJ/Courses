//
//  Game.cpp
//  Project_4
//
//  Created by apple on 8/5/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Game.h"
#include <vector>
#include <string>
#include <cctype>
using namespace std;

Game::Game(const vector<string> &words):m_words(words){}
void Game::probe(const std::string &probeWord, int &nInRightPlace, int &nInWrongPlace)
{
    nInRightPlace=nInWrongPlace=0;
    unsigned long size=max(probeWord.size(), m_secretWord.size());
    bool isSearched[size];
    for (int i=0; i<size;i++)
    {
        isSearched[i]=false;
    }
    unsigned int count=0;
    while (count<m_secretWord.size() && count<probeWord.size())
    {
        if (m_secretWord[count]==probeWord[count])
        {
            nInRightPlace++;
            isSearched[count]=true;
        }
        count++;
    }
    for (int i=0; i<probeWord.size(); i++)
    {
        for (int j=0; j<m_secretWord.size(); j++)
        {
            if (probeWord[i]==tolower(m_secretWord[j])&&isSearched[i]==false&&isSearched[j]==false)
            {
                nInWrongPlace++;
                isSearched[j]=true;
                break;
            }
        }
    }
}

Game::~Game()
{}

bool Game::setSecretWord(const string &sw)
{
    for (int i=0; i<m_words.size(); i++)
    {
        if (sw==m_words[i])
        {
            m_secretWord=sw;
            return true;
        }
    }
    return false;
}