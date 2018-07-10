//
//  Player_4.hpp
//  Project_4
//
//  Created by apple on 8/12/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

// Feature:
    // 1. length;
        // Can also be used to determine the count of a certain letter
    // 2. letter count;
        // *. function to determine the efficiency of the classifying
            // sum(count*log(count))/sum(count)
            // based on the assumption that the big O of locating the secret word in a given set of n words is roughly log(n), by classifying
    // 2.5 letter count
    //    +whether has letter in certain interval
        // Usually the first letter is more efficient?
        // Trade off here, have to determine the length of the probe

// Algorithm:
    // 1. test length
        // Put e in the first 21 ppositions, since e('e')=9.82, is minimum
    // 2. test letter count
        // 2.1. scan through to see
            // a. the distribution of count on a certain letter
            // b. the distribution of positions of the letter on a certain count
        // 2.2. get the efficiency coefficient for the letter and the count
            // The interval is looped through
            // e = sum(n * log(n)) /
                // curWords_Num
        // 2.3. take the letter and count corresponding to the smallest e
            // and generate the word



#ifndef Player_4_hpp
#define Player_4_hpp

#include <vector>
#include <string>
#include <queue>
#include <iostream>

const int  MAX_E_COUNT       = 9;
const char FIRST_TEST_LETTER = 'e';
const int  MAX_LETTER_COUNT  = 4;

class Player
{
public:
    Player(const std::vector<std::string> &words);
    std::string generateProbeWord();
    void learn(std::string probe, int nInRightPlace, int nInWrongPlace);
    ~Player();
private:
    void countWordCountEfficiency(const std::vector<std::string> &words);
    void countWordCountEfficiencyHelper(const std::vector<std::string> &words,
                                        const std::vector<int> &wordsIndex,
                                        const std::vector<std::vector<int>> &wordCount,
                                        std::vector<int>& positionIndexVector,
                                        const int& curLetterIndex,
                                        const int& totalNumLetters,const int& wordLength,
                                        int fixedPositions,
                                        std::vector<int>& curMinPosition, int &curMinIndex,
                                        double& curMin);
    
    std::vector<std::vector<std::vector<std::string>>> m_words;
    std::vector<std::string> m_curWords;
    std::string m_probeWord;
    std::vector<int> m_minPositions;
    int m_minLetterIndex;
    int m_depth;
};

#endif /* Player_4_hpp */
