//
//  Player.h
//  Project_4
//
//  Created by apple on 8/5/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include <queue>

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
    const unsigned int TABLE_SIZE   = 86969;   //Prime
    const unsigned int HASH_CONST_1 = 54059;   //Prime
    const unsigned int HASH_CONST_2 = 76963;   //Prime
    const unsigned int HASH_INITIAL = 37;      //Prime
    //Got from somw guy on Stack Overflow long ago.
    const unsigned int MAX_COUNT    = 2;
    const unsigned int MAX_TEST     = 8;
    const char  PROCESSING_ORDER[8] = {'e','a','i','s','t','n','o','r'};
    struct Node
    {
        Node(const std::string& str):word(str),next(nullptr){}
        std::string word;
        Node* next;
    };
    unsigned int strHash(std::string str);
    void insert2Table(std::string str);
    bool deleteFromTable(std::string str);
    std::vector<Node*> m_table;
    std::queue<char> m_processingOrder;
};

#endif /* Player_h */
