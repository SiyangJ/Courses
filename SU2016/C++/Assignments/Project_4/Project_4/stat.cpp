//
//  stat.cpp
//  Project_4
//
//  Created by apple on 8/5/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

const char* filename = "/Users/wq/Desktop/SU2016/C++/Assignments/Project_4/wordlist.txt";

const unsigned int MAX_COUNT=21;
const int MAX_LETTER_COUNT=3;

void countLengthEfficiency(const vector<string> &words)
{
    int size=words.size();
    unsigned int wordCount[26][MAX_COUNT+1];
    for (int i=0;i<26;i++)
    {
        for (int j=0;j<MAX_COUNT+1;j++)
        {
            wordCount[i][j]=0;
        }
    }
    unsigned int curWordCount[26];
    string curStr;
    int curSize;
    char curLetter;
    int curNum;
    for (int i=0; i<size; i++)
    {
        for (int k=0;k<26;k++)
            curWordCount[k]=0;
        curStr  = words[i];
        curSize = curStr.size();
        for (int j=0;j<curSize;j++)
        {
            curLetter=curStr[j];
            curNum=curLetter-'a';
            curWordCount[curNum]++;
        }
        for (int k=0;k<26;k++)
        {
            if (curWordCount[k]<MAX_COUNT)
                wordCount[k][curWordCount[k]]++;
            else
                wordCount[k][MAX_COUNT]++;
        }
    }
    double e;
    for (int i=0;i<26;i++)
    {
        e=0;
        curLetter='a'+i;
        cout << setw(3) << curLetter;
        for (int j=0;j<MAX_COUNT+1;j++)
        {
            e += wordCount[i][j] *
            (wordCount[i][j]==0?0:log(static_cast<double>(wordCount[i][j])));
            cout << setw(6) << wordCount[i][j];
        }
        cout << endl;
        cout << showpoint << setprecision(3)<< e/words.size() << endl;
    }
}

void countWordCountEfficiencyHelper(const vector<string> &words,
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

void countWordCountEfficiency(const vector<string> &words)
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
            time_t t1;
            time(&t1);
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
            string temp;
            temp.push_back('a'+curMinLetterIndex);
            cout << setw(2) << i+1 << setw(2) << countE << " e's "
                << setw(6) << showpoint << setprecision(4) << curMin << endl
                << setw(2) << temp << " ";
            for (int i=0;i<curMinIndex.size();i++)
                cout << curMinIndex[i] << " ";
            cout << endl;
            time_t t2;
            time(&t2);
            cout << t2-t1 << endl;
        }
    }
}

int main()
{
    ifstream wordlistfile(filename);
    if (!wordlistfile)
    {
        cerr << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    vector<string> words;
    
    string w;
    while (wordlistfile >> w)
    {
        if (w=="I") w="i";
        words.push_back(w);
    }
    countWordCountEfficiency(words);
}