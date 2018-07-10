//
//  Player_4.cpp
//  Project_4
//
//  Created by apple on 8/12/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Player_4.hpp"
#include <vector>
#include <string>
#include <cmath>

using namespace std;

Player::Player(const std::vector<std::string> &words)
{
    vector<vector<vector<string>>> dummyVec(21);
    m_words=dummyVec;
    for (int i=0;i<21;i++)
    {
        for (int j=0;j<=min(i+1,MAX_E_COUNT);j++)
        {
            vector<string> dummy;
            m_words[i].push_back(dummy);
        }
    }
    int countE;
    for (int i=0;i<words.size();i++)
    {
        countE=0;
        for (int j=0;j<words[i].size();j++)
        {
            if (words[i][j]=='e') countE++;
        }
        countE=min(countE,MAX_E_COUNT);
        m_words[words[i].size()-1][countE].push_back(words[i]);
    }
}

void Player::countWordCountEfficiencyHelper(const vector<string> &words,
                                    const vector<int> &wordsIndex,
                                    const vector<vector<int>> &wordCount,
                                    vector<int>& positionIndexVector,
                                    const int& curLetterIndex,
                                    const int& totalNumLetters,const int& wordLength,
                                    int fixedPositions, vector<int>& curMinPosition, int &curMinIndex,
                                    double& curMin)
{
    if (fixedPositions>totalNumLetters)
        return;
    if (fixedPositions!=positionIndexVector.size())
    {
        cerr << "Error in countWordCountEfficiencyHelper!" << endl;
        return;
    }
    if (fixedPositions==totalNumLetters)
    {
        vector<vector<int>> partitionCount;
        for (int i=0;i<=totalNumLetters;i++)
        {
            vector<int> dummy(i+1,0);
            partitionCount.push_back(dummy);
        }
        int countAtRightPosition;
        double countTotal;
        for (int i=0;i<wordsIndex.size();i++)
        {
            countAtRightPosition=0;
            countTotal=min(totalNumLetters,wordCount[wordsIndex[i]][curLetterIndex]);
            for (int j=0;j<totalNumLetters;j++)
                if (words[wordsIndex[i]][positionIndexVector[j]]==curLetterIndex+'a')
                    countAtRightPosition++;
            countAtRightPosition=min(totalNumLetters,countAtRightPosition);
            partitionCount[countTotal][countAtRightPosition]++;
        }
        countTotal=0;
        for (int i=0;i<totalNumLetters;i++)
            for (int j=0;j<=i;j++)
                countTotal+=partitionCount[i][j]==0?0:(partitionCount[i][j]*log(partitionCount[i][j]));
        if (curMin>countTotal/wordsIndex.size())
        {
            curMinIndex=curLetterIndex;
            curMin=countTotal/wordsIndex.size();
            curMinPosition=positionIndexVector;
        }
        return;
    }
    for (int i=fixedPositions;i<=totalNumLetters;i++)
    {
        for (int j=fixedPositions==0?0:(positionIndexVector[fixedPositions-1]+1);
             j<wordLength;j++)
        {
            positionIndexVector.push_back(j);
            countWordCountEfficiencyHelper
            (words,wordsIndex,wordCount,positionIndexVector,curLetterIndex,totalNumLetters,wordLength,fixedPositions+1,curMinPosition,curMinIndex,curMin);
            positionIndexVector.pop_back();
        }
    }
}

void Player::countWordCountEfficiency(const vector<string> &words)
{
    vector<vector<int>> wordsIndexClassifiedToLength(21);
    vector<vector<int>> wordCount(words.size());
    vector<int> dummy(26,0);
    for (int i=0;i<words.size();i++)
    {
        wordCount[i]=dummy;
    }
    for (int i=0;i<words.size();i++)
    {
        wordsIndexClassifiedToLength[words[i].size()-1].push_back(i);
        for (int j=0;j<words[i].size();j++)
        {
            wordCount[i][words[i][j]-'a']++;
        }
    }
    for (int i=0;i<21;i++)
    {
        
        vector<int>& curWordsIndex=wordsIndexClassifiedToLength[i];
        vector<vector<int>> curWordsIndexClassifiedAgain(min(10,i+2));
        for (int x=0;x<curWordsIndex.size();x++)
        {
            curWordsIndexClassifiedAgain[min(9,wordCount[curWordsIndex[x]]['e'-'a'])].push_back(curWordsIndex[x]);
        }
        for (int countE=0;countE<=i+1&&countE<=9;countE++)
        {
            vector<int>& curWords=curWordsIndexClassifiedAgain[countE];
            double curMin=999;
            vector<int> curMinIndex;
            int curMinLetterIndex=0;
            for (int j=0;j<26;j++)
            {
                for (int k=1;k<=min(i+1,MAX_LETTER_COUNT);k++)
                {
                    vector<int> positionIndexVector;
                    countWordCountEfficiencyHelper
                    (words,curWords,wordCount,positionIndexVector,j,k,i+1,0,
                     curMinIndex,curMinLetterIndex,curMin);
                }
            }
        }
    }
}

string Player::generateProbeWord()
{
    if (m_curWords.empty())
    {
        string temp;
        for (int i=0;i<21;i++) temp.push_back(FIRST_TEST_LETTER);
        for (int i=0;i<26;i++)
            if (i!=FIRST_TEST_LETTER-'a')
                for (int j=0;j<21;j++)
                    temp.push_back('a'+i);
        return temp;
    }
    else if (m_depth==1)
    {
        int countE=m_minLetterIndex;
        char dummy;
        switch (m_curWords[0].size())
        {
            case 2: dummy=(countE==0?'o':'e'); break;
            case 3: dummy=(countE==0?'a':'e'); break;
            case 4:
                switch (countE)
            {
                case 0: dummy='s'; break;
                case 3: dummy='a'; break;
                default: dummy='e'; break;
            }
                break;
            case 5: case 6:
                switch (countE)
            {
                case 0: dummy='s'; break;
                default: dummy='e'; break;
            }
                break;
            case 7 : case 8: case 9: case 10: case 11: case 12: case 13: case 14:
                switch (countE)
            {
                case 0: dummy='i'; break;
                case 5: dummy='a'; break;
                default: dummy='e'; break;
            }
                break;
            case 15:
                switch (countE)
            {
                case 0: dummy='i'; break;
                case 5: dummy='c'; break;
                default: dummy='e'; break;
            }
                break;
            case 16:
                switch (countE)
            {
                case 0: dummy='i'; break;
                default: dummy='e'; break;
            }
                break;
            case 17:
                switch (countE)
                {
                    case 1: case 2: case 3: dummy='e'; break;
                    default: dummy='a'; break;
                }
                break;
            default: dummy='a'; break;
        }
        string temp;
        temp.push_back(dummy);
        
        vector<vector<vector<string>>> dummy()
        
        return temp;
    }
    else
    {
        
    }
}

void Player::learn(string probe, int nInRightPlace, int nInWrongPlace)
{
    if (m_depth++==0)
    {
        m_curWords=m_words[nInRightPlace+nInWrongPlace-1][min(MAX_E_COUNT,nInRightPlace)];
        m_minLetterIndex=nInRightPlace;
    }
    else
    {
    }
    vector<string>& words=m_curWords;
    int length=words[0].size();
    vector<int> curWords;
    for (int i=0;i<words.size();i++) curWords.push_back(i);
    vector<vector<int>> wordCount(words.size());
    vector<int> dummy(26,0);
    for (int i=0;i<words.size();i++)
    {
        wordCount[i]=dummy;
    }
    for (int i=0;i<words.size();i++)
    {
        for (int j=0;j<words[i].size();j++)
        {
            wordCount[i][words[i][j]-'a']++;
        }
    }
    double curMin=999;
    vector<int> curMinIndex;
    int curMinLetterIndex=0;
    for (int j=0;j<26;j++)
    {
        for (int k=1;k<=min(length,MAX_LETTER_COUNT);k++)
        {
            vector<int> positionIndexVector;
            countWordCountEfficiencyHelper
            (words,curWords,wordCount,positionIndexVector,j,k,length,0,
            curMinIndex,curMinLetterIndex,curMin);
        }
    }
    m_minLetterIndex=curMinLetterIndex;
    m_minPositions=curMinIndex;
    if (curMinIndex.empty()) cerr << "Error!!!\n";
}
