//
//  Player_2.hpp
//  Project_4
//
//  Created by apple on 8/8/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Player_2_hpp
#define Player_2_hpp

#include <vector>
#include <string>
#include <queue>
#include <iostream>

class Player
{
public:
    Player(const std::vector<std::string> &words);
    std::string generateProbeWord();
    void learn(std::string probe, int nInRightPlace, int nInWrongPlace);
    ~Player();
private:
    // Prevent people from copying Player objects.
    Player(const Player&);
    Player& operator=(const Player&);
    // Define your own data structure here
    static unsigned int MAX_LENGTH;
    static unsigned int MAX_COUNT_1;
    static unsigned int MAX_COUNT_2;
    static unsigned int MAX_TEST_1;
    static unsigned int MAX_TEST_2;
    static unsigned int LIMIT_LINEAR_GUESS;
    static unsigned int MAX_OP_SEARCH;
    static char PROCESSING_ORDER_1[5];
    static char PROCESSING_ORDER_2[7];
    static char ADDTIONAL_SEARCH[3];
    // Pop the front at learn!!!
    struct Node
    {
        Node():count(0){}
        unsigned int count;
        std::vector<std::string> words;
        std::vector<Node*> children;
    };    
    void constructorHelper(unsigned int i, Node* ptr);
    void destructorHelper(Node* ptr);
    //void treePrune(Node* ptr, Node* parent);
    
    
    Node* m_root;
    Node* m_curRoot;
    std::queue<char> m_processingOrder;
    std::queue<char> m_addtionalSearchOrder;
    std::vector<std::string> m_tableOp[26][26];
    int m_curVecIndex[3];
    //The third position: 0 precise, 1 the first is correct, 2 only know has it/them;
    std::vector<std::string> m_curVec;
};


#endif /* Player_2_hpp */
