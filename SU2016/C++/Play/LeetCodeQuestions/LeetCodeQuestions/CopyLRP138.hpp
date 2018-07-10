//
//  CopyLRP138.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/16/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef CopyLRP138_hpp
#define CopyLRP138_hpp

#include <stdio.h>
struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

class CopyLRP138
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        
        if (head==NULL)
            return NULL;
        RandomListNode* cur=head;
        RandomListNode* ret=new RandomListNode(0);
        RandomListNode* cop=ret;
        while (cur!=NULL)
        {
            cop->label=cur->label;
            
        }
    }
};


#endif /* CopyLRP138_hpp */
