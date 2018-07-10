//
//  Player.c
//  Project_4
//
//  Created by apple on 8/5/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Player__.h"
#include <vector>
#include <string>

using namespace std;

unsigned int Player::strHash(string str)
{
    unsigned int h = HASH_INITIAL;
    for (int i=0;i<str.size();i++)
        h = (h*HASH_CONST_1) ^ (str[i]*HASH_CONST_2);
    return h % TABLE_SIZE;
}

void Player::insert2Table(string str)
{
    unsigned int hash=strHash(str);
    if (m_table[hash]==nullptr)
        m_table[hash]=new Node(str);
    else
    {
        Node* dummy=m_table[hash];
        while (dummy->next!=nullptr)
            dummy=dummy->next;
        dummy->next=new Node(str);
    }
}

bool Player::deleteFromTable(string str)
{
    unsigned int hash=strHash(str);
    if (m_table[hash]==nullptr)
        return false;
    else if (m_table[hash]->word==str)
    {
        Node* temp=m_table[hash];
        m_table[hash]=m_table[hash]->next;
        delete temp;
        return true;
    }
    else
    {
        Node* dummy=m_table[hash];
        while (dummy->next!=nullptr && dummy->next->word!=str)
            dummy=dummy->next;
        if (dummy->next==nullptr)
            return false;
        else
        {
            Node* temp=dummy->next;
            dummy->next=dummy->next->next;
            delete temp;
            return true;
        }
    }
}

Player::Player(const std::vector<std::string> &words)
{
    for (unsigned int i=0; i<MAX_TEST;i++)
        m_processingOrder.push(PROCESSING_ORDER[i]);
    m_table.reserve(TABLE_SIZE);
    for (unsigned int i=0;i<TABLE_SIZE;i++)
        m_table[i]=nullptr;
    for (unsigned int i=0;i<words.size();i++)
        insert2Table(words[i]);
}

Player::~Player()
{
    for (int i=0;i<TABLE_SIZE;i++)
    {
            Node* dummy=m_table[i];
            Node* temp;
            while (dummy!=nullptr)
            {
                temp=dummy;
                dummy=dummy->next;
                delete temp;
            }
    }
}

