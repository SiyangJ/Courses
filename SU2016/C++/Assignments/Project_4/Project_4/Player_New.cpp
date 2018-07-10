//
//  Player_New.cpp
//  Project_4
//
//  Created by apple on 8/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Player_New.h"

using namespace std;

unsigned int Player::MAX_LENGTH             = 21;
unsigned int Player::MAX_COUNT_1            = 2;
unsigned int Player::MAX_COUNT_2            = 1;
unsigned int Player::MAX_COUNT_OP_SEARCH    = 1;
unsigned int Player::MAX_TEST_1             = 5;
unsigned int Player::MAX_TEST_2             = 7;
unsigned int Player::LIMIT_LINEAR_GUESS     = 3;
unsigned int Player::MAX_OP_SEARCH          = 3;
unsigned int Player::LETTER_COUNT_EXACT     = 2500;
unsigned int Player::LETTER_COUNT_LESS_THAN = 2501;
char Player::PROCESSING_ORDER_1[5]      = {'e','a','r','i','s'};
char Player::PROCESSING_ORDER_2[7]      = {'o','c','u','l','t','n','d'};
char Player::ADDTIONAL_SEARCH[3]        = {'f','b','g'};

int Player::Node::LETTER_COUNT_INSERT_ROOT_NULLPTR  = 1000;
int Player::Node::LETTER_COUNT_INSERT_ROOT_BIGGER   = 1001;
int Player::Node::LETTER_COUNT_INSERT_TO_NEXT       = 1002;

void Player::initialization()
{
    for (int i=0;i<26;i++)
    {
        letterCountRootPtrArr[i]     = nullptr;
        hasThisInOpTwoRootPtrArr[i]  = nullptr;
        opLetterRootPtrArr[i]        = nullptr;
    }
    for (int i=0;i<MAX_LENGTH;i++)
        lengthRootPtrArr[i]          = nullptr;
}

int Player::find_letterCountFirstPtr(char letter, int count, Node*& ptr)
{
    int index=tolower(letter)-'a';
    ptr=letterCountRootPtrArr[index];
    if (ptr==nullptr) return Node::LETTER_COUNT_INSERT_ROOT_NULLPTR;
    if (ptr->letterCountArr[index]==count) return Node::LETTER_COUNT_INSERT_TO_NEXT;
    if (ptr->letterCountArr[index]>count) return Node::LETTER_COUNT_INSERT_ROOT_BIGGER;
    while (ptr->letterCountNextArr[index]!=nullptr &&
           ptr->letterCountNextArr[index]->letterCountArr[index]<count)
    {
        ptr=ptr->letterCountNextArr[index];
    }
    return Node::LETTER_COUNT_INSERT_TO_NEXT;
}

void Player::buildNet_length(Node* ptr)
{
    int index=ptr->value.size()-1;
    if (lengthRootPtrArr[index]==nullptr)
        lengthRootPtrArr[index]=ptr;
    else
    {
        ptr->lengthNext=lengthRootPtrArr[index]->lengthNext;
        ptr->lengthPrev=lengthRootPtrArr[index];
        lengthRootPtrArr[index]->lengthNext=ptr;
    }
}

void Player::buildNet_letterCount(Node* ptr)
{
    Node* dummy;
    for (int i=0;i<26;i++)
    {
        int caseNum=find_letterCountFirstPtr('a'+i,ptr->letterCountArr[i],dummy);
        if (caseNum==Node::LETTER_COUNT_INSERT_ROOT_NULLPTR)
        {
            letterCountRootPtrArr[i]=ptr;
        }
        else if (caseNum==Node::LETTER_COUNT_INSERT_ROOT_BIGGER)
        {
            Node* temp=letterCountRootPtrArr[i];
            letterCountRootPtrArr[i]=ptr;
            ptr->letterCountNextArr[i]=temp;
        }
        else if (caseNum==Node::LETTER_COUNT_INSERT_TO_NEXT)
        {
            ptr->letterCountNextArr[i]=dummy->letterCountNextArr[i];
            ptr->letterCountPrevArr[i]=dummy;
            dummy->letterCountNextArr[i]=ptr;
        }
    }
}

void Player::buildNet_opTwoletter(Node* ptr)
{
    int index=ptr->value[0]-'a';
    if (hasThisInOpTwoRootPtrArr[index]==nullptr)
    {
        hasThisInOpTwoRootPtrArr[index]=ptr;
    }
    else
    {
        ptr->opTwoLetterNext[0]=hasThisInOpTwoRootPtrArr[index]->opTwoLetterNext[0];
        ptr->opTwoLetterPrev[0]=hasThisInOpTwoRootPtrArr[index];
        hasThisInOpTwoRootPtrArr[index]->opTwoLetterNext[0]=ptr;
    }
    if (ptr->value.size()>1 && ptr->value[0]!=ptr->value[1])
    {
        int index=ptr->value[1]-'a';
        if (hasThisInOpTwoRootPtrArr[index]==nullptr)
        {
            hasThisInOpTwoRootPtrArr[index]=ptr;
        }
        else
        {
            ptr->opTwoLetterNext[1]=hasThisInOpTwoRootPtrArr[index]->opTwoLetterNext[1];
            ptr->opTwoLetterPrev[1]=hasThisInOpTwoRootPtrArr[index];
            hasThisInOpTwoRootPtrArr[index]->opTwoLetterNext[1]=ptr;
        }
    }
}

void Player::buildNet_opLetter(Node* ptr)
{
    int index=ptr->value[0]-'a';
    if (opLetterRootPtrArr[index]==nullptr)
    {
        opLetterRootPtrArr[index]=ptr;
    }
    else
    {
        ptr->opLetterNext=opLetterRootPtrArr[index]->opLetterNext;
        ptr->opLetterPrev=opLetterRootPtrArr[index];
        opLetterRootPtrArr[index]->opLetterNext=ptr;
    }
}

void Player::insertNode(Node* ptr)
{
    buildNet_length(ptr);
    buildNet_letterCount(ptr);
    buildNet_opLetter(ptr);
    buildNet_opTwoletter(ptr);
}

void Player::destroyNet_length(Node* ptr)
{
    if (ptr->lengthNext!=nullptr)
    {
        ptr->lengthNext->lengthPrev=ptr->lengthPrev;
    }
    if (ptr->lengthPrev!=nullptr)
    {
        ptr->lengthPrev->lengthNext=ptr->lengthNext;
    }
    else
    {
        lengthRootPtrArr[ptr->value.size()-1]=ptr->lengthNext;
    }
}

void Player::destroyNet_opLetter(Node* ptr)
{
    if (ptr->opLetterNext!=nullptr)
    {
        ptr->opLetterNext->opLetterPrev=ptr->opLetterPrev;
    }
    if (ptr->opLetterPrev!=nullptr)
    {
        ptr->opLetterPrev->opLetterNext=ptr->opLetterNext;
    }
    else
    {
        opLetterRootPtrArr[ptr->value[0]-'a']=ptr->opLetterNext;
    }
}

void Player::destroyNet_letterCount(Node* ptr)
{
    for (int i=0;i<26;i++)
    {
        if (ptr->letterCountNextArr[i]!=nullptr)
        {
            ptr->letterCountNextArr[i]->letterCountPrevArr[i]=ptr->letterCountPrevArr[i];
        }
        if (ptr->letterCountPrevArr[i]!=nullptr)
        {
            ptr->letterCountPrevArr[i]->letterCountNextArr[i]=ptr->letterCountNextArr[i];
        }
        else
        {
            letterCountRootPtrArr[i]=ptr->letterCountNextArr[i];
        }
    }
}

void Player::destroyNet_opTwoLetter(Node* ptr)
{
    if (ptr->opTwoLetterNext[0]!=nullptr)
    {
        ptr->opTwoLetterNext[0]->opTwoLetterPrev[0]=ptr->opTwoLetterPrev[0];
    }
    if (ptr->opTwoLetterPrev[0]!=nullptr)
    {
        ptr->opTwoLetterPrev[0]->opTwoLetterNext[0]=ptr->opTwoLetterNext[0];
    }
    else
    {
        hasThisInOpTwoRootPtrArr[ptr->value[0]-'a']=ptr->opTwoLetterNext[0];
    }
    if (ptr->value.size()>1)
    {
        if (ptr->opTwoLetterNext[1]!=nullptr)
        {
            ptr->opTwoLetterNext[1]->opTwoLetterPrev[1]=ptr->opTwoLetterPrev[1];
        }
        if (ptr->opTwoLetterPrev[1]!=nullptr)
        {
            ptr->opTwoLetterPrev[1]->opTwoLetterNext[1]=ptr->opTwoLetterNext[1];
        }
        else
        {
            hasThisInOpTwoRootPtrArr[ptr->value[0]-'a']=ptr->opTwoLetterNext[1];
        }
    }
}

void Player::deleteNode(Node*& ptr)
{
    destroyNet_length(ptr);
    destroyNet_letterCount(ptr);
    destroyNet_opLetter(ptr);
    destroyNet_opTwoLetter(ptr);
    delete ptr;
}

Player::Player(const std::vector<std::string> &words)
{
    initialization();
    for (int i=0;i<words.size();i++)
    {
        Node* temp=new Node(words[i]);
        insertNode(temp);
    }
    searchProcess=0;
    wordCount=words.size();
    wordLength=-1;
}

Player::~Player()
{
    for (int i=0;i<26;i++)
    {
        while (letterCountRootPtrArr[i]!=nullptr)
            deleteNode(letterCountRootPtrArr[i]);
    }
}

bool Player::isTrivial_LetterCount(char c)
{
    int index=c-'a';
    Node* dummy=letterCountRootPtrArr[index];
    int rootLetterCount=dummy->letterCountArr[index];
    while (dummy!=nullptr)
    {
        if (dummy->letterCountArr[index]!=rootLetterCount)
            break;
        dummy=dummy->letterCountNextArr[index];
    }
    if (dummy==nullptr) return true;
    else return false;
}

string Player::generateProbeWord()
{
    string temp;
    if (wordCount>LIMIT_LINEAR_GUESS)
    {
        if (searchProcess==0)
            temp=generateProbe_length();
        else if (searchProcess<=MAX_TEST_1)
        {
            char c=PROCESSING_ORDER_1[searchProcess-1];
            if (isTrivial_LetterCount(c))
            {
                searchProcess++;
                return generateProbeWord();
            }
            temp=generateProbe_2letter(c);
        }
        else if (searchProcess<=MAX_TEST_1+MAX_TEST_2)
        {
            char c=PROCESSING_ORDER_2[searchProcess-MAX_TEST_1-1];
            if (isTrivial_LetterCount(c))
            {
                searchProcess++;
                return generateProbeWord();
            }
            temp=generateProbe_1letter(c);
        }
        else if (searchProcess<=MAX_TEST_1+MAX_TEST_2+MAX_OP_SEARCH)
        {
            char c=ADDTIONAL_SEARCH[searchProcess-MAX_TEST_1-MAX_TEST_2-1];
            if (isTrivial_LetterCount(c))
            {
                searchProcess++;
                return generateProbeWord();
            }
            temp=generateProbe_1letter(c);
        }
        else temp=generateProbe_linear();
    }
    else
    {
        temp=generateProbe_linear();
    }
    return temp;
}

void Player::learn(string probe, int numBulls, int numCows)
{
    if (wordCount>LIMIT_LINEAR_GUESS)
    {
        if (searchProcess==0)
        {
            wordLength=numCows+numBulls;
            deleteNodes_lengthNotEqualTo(wordLength);
        }
        else if (searchProcess<=MAX_TEST_1)
        {
            deleteNodes_letterCountNotEqualTo
            (PROCESSING_ORDER_1[searchProcess-1], numCows+numBulls,
             numBulls+numCows==MAX_COUNT_1?LETTER_COUNT_LESS_THAN:LETTER_COUNT_EXACT);
            if (numBulls==MAX_COUNT_1)
            {
                deleteNodes_opTwoLetterDoesNotHave(PROCESSING_ORDER_1[searchProcess-1]);
                deleteNodes_opLetterIsNot(PROCESSING_ORDER_1[searchProcess-1]);
            }
            else if (numBulls!=0)
            {
                deleteNodes_opTwoLetterDoesNotHave(PROCESSING_ORDER_1[searchProcess-1]);
            }
        }
        else if (searchProcess<=MAX_TEST_1+MAX_TEST_2)
        {
            char c=PROCESSING_ORDER_2[searchProcess-MAX_TEST_1-1];
            deleteNodes_letterCountNotEqualTo
            (c, numCows+numBulls,
             numCows+numBulls==MAX_COUNT_2?LETTER_COUNT_LESS_THAN:LETTER_COUNT_EXACT);
            if (numBulls==MAX_COUNT_2)
            {
                deleteNodes_opTwoLetterDoesNotHave(c);
                deleteNodes_opLetterIsNot(c);
            }
            else if (numBulls!=0)
            {
                deleteNodes_opTwoLetterDoesNotHave(c);
            }
        }
        else if (searchProcess<=MAX_TEST_1+MAX_TEST_2+MAX_OP_SEARCH)
        {
            char c=ADDTIONAL_SEARCH[searchProcess-MAX_TEST_1-MAX_TEST_2-1];
            deleteNodes_letterCountNotEqualTo
            (c, MAX_OP_SEARCH,
             numBulls+numCows==MAX_COUNT_OP_SEARCH?LETTER_COUNT_LESS_THAN:LETTER_COUNT_EXACT);
            if (numBulls==MAX_COUNT_OP_SEARCH)
            {
                deleteNodes_opTwoLetterDoesNotHave(c);
                deleteNodes_opLetterIsNot(c);
            }
            else if (numBulls!=0)
            {
                deleteNodes_opTwoLetterDoesNotHave(c);
            }
        }
        else return;
        searchProcess++;
    }
}

string Player::generateProbe_length()
{
    string temp;
    for (int i=0;i<26;i++)
    {
        for (int j=0;j<MAX_LENGTH;j++)
        {
            temp.push_back('a'+i);
        }
    }
    return temp;
}

string Player::generateProbe_1letter(char c)
{
    string temp;
    temp.push_back(c);
    return temp;
}

string Player::generateProbe_2letter(char c)
{
    string temp;
    temp.push_back(c);
    temp.push_back(c);
    return temp;
}

string Player::generateProbe_linear()
{
    string temp=lengthRootPtrArr[wordLength-1]->value;
    deleteNode(lengthRootPtrArr[wordLength-1]);
    return temp;
}

void Player::deleteNodes_lengthNotEqualTo(int length)
{
    for (int i=0;i<MAX_LENGTH;i++)
    {
        if (i!=length-1)
        {
            while (lengthRootPtrArr[i]!=nullptr)
                deleteNode(lengthRootPtrArr[i]);
        }
    }
}

void Player::deleteNodes_letterCountNotEqualTo(char letter,int count,unsigned int caseNum)
{
    int index=letter-'a';
    while (letterCountRootPtrArr[index]!=nullptr &&
           letterCountRootPtrArr[index]->letterCountArr[index]<count)
        deleteNode(letterCountRootPtrArr[index]);
    if (caseNum==LETTER_COUNT_EXACT)
    {
        Node* dummy=letterCountRootPtrArr[index];
        while (dummy!=nullptr &&
               dummy->letterCountArr[index]<=count)
            dummy=dummy->letterCountNextArr[index];
        Node* next;
        while (dummy!=nullptr)
        {
            next=dummy->letterCountNextArr[index];
            deleteNode(dummy);
            dummy=next;
        }
    }
}

void Player::deleteNodes_opLetterIsNot(char letter)
{
    for (int i=0;i<26;i++)
    {
        if (i!=letter-'a')
        {
            while (opLetterRootPtrArr[i]!=nullptr)
                deleteNode(opLetterRootPtrArr[i]);
        }
    }
}

void Player::deleteNodes_opTwoLetterDoesNotHave(char letter)
{
    for (int i=0;i<26;i++)
    {
        if (i!=letter-'a')
        {
            while (hasThisInOpTwoRootPtrArr[i]!=nullptr)
                deleteNode(hasThisInOpTwoRootPtrArr[i]);
        }
    }
}