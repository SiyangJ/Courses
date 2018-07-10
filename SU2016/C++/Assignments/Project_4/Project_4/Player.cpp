//
//  Player_2.cpp
//  Project_4
//
//  Created by apple on 8/8/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Player.h"
#include <queue>
#include <string>
#include <cctype>
using namespace std;

void Player::constructorHelper(unsigned int i, Player::Node* ptr)
{
    if (i==MAX_TEST_1+MAX_TEST_2)
    {
        return;
    }
    unsigned int MAX_COUNT=(i<MAX_TEST_1?MAX_COUNT_1:MAX_COUNT_2);
    ptr->children.reserve(MAX_COUNT+1);
    for (int j=0;j<=MAX_COUNT;j++)
    {
        ptr->children.push_back(new Node);
        constructorHelper(i+1, ptr->children.back());
    }
}

unsigned int Player::MAX_LENGTH         = 21;
unsigned int Player::MAX_COUNT_1        = 2;
unsigned int Player::MAX_COUNT_2        = 2;
unsigned int Player::MAX_TEST_1         = 5;
unsigned int Player::MAX_TEST_2         = 7;
unsigned int Player::LIMIT_LINEAR_GUESS = 3;
unsigned int Player::MAX_OP_SEARCH      = 3;
char Player::PROCESSING_ORDER_1[5]      = {'e','a','r','i','s'};
char Player::PROCESSING_ORDER_2[7]      = {'o','c','u','l','t','n','d'};
char Player::ADDTIONAL_SEARCH[3]        = {'m','p','g'};

Player::Player(const std::vector<std::string> &words)
{
    m_curVecIndex[0]=m_curVecIndex[1]=m_curVecIndex[2]=-1;
    m_root=new Node;
    m_root->children.reserve(MAX_LENGTH);
    for (int i=0;i<MAX_LENGTH;i++)
    {
        m_root->children.push_back(new Node);
        constructorHelper(0, m_root->children.back());
    }
    // Constructing an "empty" tree;
    Node* curNode;
    unsigned int curCharCount[26];
    for (int i=0;i<words.size();i++)
    {
        m_tableOp[tolower(words[i][0])-'a'][words[i][words[i].size()>1?1:0]-'a'].push_back(words[i]);
        curNode=m_root->children[words[i].size()-1];
        for (int j=0;j<26;j++) curCharCount[j]=0;
        for (int j=0;j<words[i].size();j++)
        {
            if (words[i][j]!='I')
                curCharCount[words[i][j]-'a']++;
            else curCharCount['i'-'a']++;
        }
        for (int j=0;j<MAX_TEST_1;j++)
        {
            curNode->count++;
            curNode=curNode->children[min(curCharCount[PROCESSING_ORDER_1[j]-'a'], MAX_COUNT_1)];
        }
        for (int j=0;j<MAX_TEST_2;j++)
        {
            curNode->count++;
            curNode=curNode->children[min(curCharCount[PROCESSING_ORDER_2[j]-'a'], MAX_COUNT_2)];
        }
        curNode->count++;
        curNode->words.push_back(words[i]);
    }
    // Constructing the tree;
    m_processingOrder.push('1');
    for (int i=0;i<MAX_TEST_1;i++)
        m_processingOrder.push(PROCESSING_ORDER_1[i]);
    for (int i=0;i<MAX_TEST_2;i++)
        m_processingOrder.push(PROCESSING_ORDER_2[i]);
    for (int i=0;i<MAX_OP_SEARCH;i++)
        m_addtionalSearchOrder.push(ADDTIONAL_SEARCH[i]);
    m_curRoot=m_root;
    m_root->count=words.size();
}

void Player::destructorHelper(Node* ptr)
{
    while (!ptr->children.empty())
    {
        destructorHelper(ptr->children.back());
        ptr->children.pop_back();
    }
    delete ptr;
}

Player::~Player()
{
    destructorHelper(m_root);
}

/*void Player::treePrune(Player::Node* ptr, Player::Node* parent)
{
    while (!ptr->children.empty())
    {
        treePrune(ptr->children.back(), ptr);
        ptr->children.pop_back();
    }
    vector<Node*>::iterator it=parent->children.begin();
    
    
}
 */

string Player::generateProbeWord()
{
    string word;
    if (m_curRoot->children.empty())
    {
        if (m_curRoot->count>LIMIT_LINEAR_GUESS){
        if (m_addtionalSearchOrder.empty()&&!m_curVec.empty())
        {
            if (m_curVec.back()!="isSearched")
            {
                for (vector<string>::iterator it=m_curRoot->words.begin();it!=m_curRoot->words.end();it++)
                {
                    int i;
                    for (i=0;i<m_curVec.size();i++)
                    {
                        if ((*it)==m_curVec[i]) break;
                    }
                    if (i==m_curVec.size()) m_curRoot->words.erase(it--);
                }
                m_curVec.push_back("isSearched");
            }
            string temp=m_curRoot->words.back();
            m_curRoot->words.pop_back();
            m_curRoot->count--;
            return temp;
            // if already searched the vec, linear guess
        }
        else if (!m_addtionalSearchOrder.empty())
        {
            char c=m_addtionalSearchOrder.front();
            unsigned int count=0;
            for (int i=0;i<m_curRoot->words.size();i++)
            {
                if (m_curRoot->words[i][0]==c) count++;
            }
            if (count==0 || count==m_curRoot->words.size())
            {
                int numBull=count==0?0:1;
                string str;
                str.push_back(c);
                learn(str, numBull, 0);
                return generateProbeWord();
            }
            string temp;
            temp.push_back(m_addtionalSearchOrder.front());
            return temp;
        }}
            string temp=m_curRoot->words.back();
            m_curRoot->words.pop_back();
            m_curRoot->count--;
            return temp;
            // linear guess
    }
    else if (m_curRoot->count<=LIMIT_LINEAR_GUESS)
    {
        Node* temp=m_curRoot;
        if (temp->children.empty())
        {
            word=temp->words.back();
            temp->words.pop_back();
            return word;
        }
        else
        {
            unsigned int count=0;
            for (int i=0;i<m_curRoot->children.size();i++)
            {
                if (m_curRoot->children[i]->count!=0)
                {
                    count++;
                    temp=m_curRoot->children[i];
                }
            }
            if (count==1)
            {
                m_curRoot=temp;
                m_processingOrder.pop();
                return generateProbeWord();
            }
        }
    }
    if (m_processingOrder.front()=='1')
        {
            for (int i=0;i<26;i++)
            {
                for (int j=0;j<MAX_LENGTH;j++)
                {
                    word.push_back('a'+i);
                }
            }
            return word;
        }
    else
    {
        unsigned int count=0;
        Node* dummy=m_curRoot;
        for (int i=0;i<m_curRoot->children.size();i++)
        {
            if (m_curRoot->children[i]->count!=0)
            {
                count++;
                dummy=m_curRoot->children[i];
                
            }
        }
        if (count==1)
        {
            m_curRoot=dummy;
            m_processingOrder.pop();
            return generateProbeWord();
        }
        unsigned int MAX_COUNT=(m_curRoot->children.size()==MAX_COUNT_2+1?MAX_COUNT_2:MAX_COUNT_1);
        char temp=m_processingOrder.front();
        for (int i=0;i<MAX_COUNT;i++) word.push_back(temp);
        return word;
    }
}

void Player::learn(string probe, int numBull, int numCow)
{
    if (!m_curRoot->children.empty())
    {
        if (m_processingOrder.front()!='1'){
        if (probe.size()>1)
        {
            if (numBull==1)
            {
                if (m_curVecIndex[0]<0&&m_curVecIndex[1]<0)
                {
                    m_curVecIndex[0]=m_curVecIndex[1]=m_processingOrder.front()-'a';
                    m_curVecIndex[2]=2;
                }
                else
                {
                    m_curVecIndex[1]=m_processingOrder.front()-'a';
                    m_curVecIndex[2]=2;
                }
            }
            else if (numBull==probe.size())
            {
                m_curVecIndex[0]=m_curVecIndex[1]=m_processingOrder.front()-'a';
                m_curVecIndex[2]=0;
            }
        }
        else if (numBull==1)
        {
            m_curVecIndex[0]=m_processingOrder.front()-'a';
            if (m_curVecIndex[1]>=0) m_curVecIndex[2]=0;
            else m_curVecIndex[2]=1;
        }
        m_curRoot=m_curRoot->children[numBull+numCow];}
        else m_curRoot=m_curRoot->children[numBull+numCow-1];
        m_processingOrder.pop();
        return;
    }
    else if (!m_addtionalSearchOrder.empty()&&m_curRoot->words.size()>LIMIT_LINEAR_GUESS)
    {
        if (numBull)
        {
            m_curVecIndex[0]=m_addtionalSearchOrder.front()-'a';
            if (m_curVecIndex[1]>=0) m_curVecIndex[2]=0;
            else m_curVecIndex[2]=1;
        }
        else
        {
            for (vector<string>::iterator it=m_curRoot->words.begin();it!=m_curRoot->words.end();it++)
            {
                if ((*it)[0]==m_addtionalSearchOrder.front())
                {m_curRoot->words.erase(it--);m_curRoot->count--;}
            }
        }
        m_addtionalSearchOrder.pop();
        if (m_addtionalSearchOrder.empty())
        {
            if (m_curVecIndex[2]==0)
            {
                m_curVec=m_tableOp[m_curVecIndex[0]][m_curVecIndex[1]];
            }
            else if (m_curVecIndex[2]==1)
            {
                m_curVec.push_back("isSearched");
                for (vector<string>::iterator it=m_curRoot->words.begin();it!=m_curRoot->words.end();it++)
                {
                    if ((*it)[0]!=m_curVecIndex[0]+'a')
                    {
                        m_curRoot->words.erase(it--);
                        m_curRoot->count--;
                    }
                }
            }
            else if (m_curVecIndex[2]==2)
            {
                if (m_curVecIndex[0]>=0&&m_curVecIndex[1]>=0&&m_curVecIndex[0]!=m_curVecIndex[1])
                {
                    m_curVec=m_tableOp[m_curVecIndex[0]][m_curVecIndex[1]];
                    for (int i=0;i<m_tableOp[m_curVecIndex[1]][m_curVecIndex[0]].size();i++)
                        m_curVec.push_back(m_tableOp[m_curVecIndex[1]][m_curVecIndex[0]][i]);
                }
                else
                {
                    m_curVec.push_back("isSearched");
                }
            }
        }
    }
    else if ((!m_curVec.empty())&&m_curVec.back()!="isSearched")
    {
        for (vector<string>::iterator it=m_curRoot->words.begin();it!=m_curRoot->words.end();it++)
        {
            int i;
            for (i=0;i<m_curVec.size();i++)
            {
                if ((*it)==m_curVec[i]) break;
            }
            if (i==m_curVec.size()) {m_curRoot->words.erase(it--);m_curRoot->count--;}
        }
        m_curVec.push_back("isSearched");
        return;
    }
    else
    {
        //////
        return;
    }
}