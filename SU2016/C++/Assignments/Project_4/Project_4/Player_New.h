//
//  Player_New.hpp
//  Project_4
//
//  Created by apple on 8/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Player_New_h
#define Player_New_h


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
    static unsigned int MAX_COUNT_OP_SEARCH;
    static unsigned int MAX_TEST_1;
    static unsigned int MAX_TEST_2;
    static unsigned int LIMIT_LINEAR_GUESS;
    static unsigned int MAX_OP_SEARCH;
    static unsigned int LETTER_COUNT_EXACT;
    static unsigned int LETTER_COUNT_LESS_THAN;
    static char PROCESSING_ORDER_1[5];
    static char PROCESSING_ORDER_2[7];
    static char ADDTIONAL_SEARCH[3];
    
    int wordLength;
    int wordCount;
    int searchProcess;
    std::string generateProbe_length();
    std::string generateProbe_2letter(char c);
    std::string generateProbe_1letter(char c);
    std::string generateProbe_linear();
    //Pop the words here while generating;
    void deleteNodes_lengthNotEqualTo(int length);
    void deleteNodes_letterCountNotEqualTo(char letter, int count, unsigned int caseNum);
    //Pay attention to max count;
    void deleteNodes_opLetterIsNot(char letter);
    void deleteNodes_opTwoLetterDoesNotHave(char letter);

    struct Node
    {
        Node(std::string str)
        {
            std::string val;
            for (int i=0;i<str.size();i++)
            {
                val.push_back(tolower(str[i]));
            }
            value=val;
            lengthNext=lengthPrev=nullptr;
            opLetterNext=opLetterPrev=nullptr;
            opTwoLetterNext[0]=opTwoLetterNext[1]=nullptr;
            opTwoLetterPrev[0]=opTwoLetterPrev[1]=nullptr;
            for (int i=0;i<value.size();i++)
            {
                letterCountArr[value[i]-'a']++;
            }
            for (int i=0;i<26;i++)
            {
                letterCountNextArr[i]=letterCountPrevArr[i]=nullptr;
            }
        }
        std::string value;
        int   letterCountArr[26];
        Node* lengthNext;
        Node* lengthPrev;
        Node* letterCountPrevArr[26];
        Node* letterCountNextArr[26];
        Node* opTwoLetterNext[2];
        Node* opTwoLetterPrev[2];
        Node* opLetterNext;
        Node* opLetterPrev;
        
        static int LETTER_COUNT_INSERT_ROOT_NULLPTR;
        static int LETTER_COUNT_INSERT_ROOT_BIGGER;
        static int LETTER_COUNT_INSERT_TO_NEXT;
        
    };
    
    Node* lengthRootPtrArr[21];
    Node* letterCountRootPtrArr[26];
    Node* hasThisInOpTwoRootPtrArr[26];
    Node* opLetterRootPtrArr[26];
    
    bool isTrivial_LetterCount(char c);
    
    void deleteNode(Node*& ptr);
    void destroyNet_length(Node* ptr);
    void destroyNet_letterCount(Node* ptr);
    void destroyNet_opTwoLetter(Node* ptr);
    void destroyNet_opLetter(Node* ptr);
    
    void insertNode(Node* ptr);
    //Can only be used to insert newly initialized node, i.e. node without connections;
    //Same with functions below;
    int  find_letterCountFirstPtr(char letter, int count, Node*& ptr);
    void buildNet_length(Node* ptr);
    void buildNet_letterCount(Node* ptr);
    void buildNet_opTwoletter(Node* ptr);
    void buildNet_opLetter(Node* ptr);
    
    void initialization();
};

#endif /* Player_New_hpp */
