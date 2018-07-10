//
//  IntegerReplacement397.hpp
//  LeetCodeQuestions
//
//  Created by apple on 10/29/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#ifndef IntegerReplacement397_hpp
#define IntegerReplacement397_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LCA236
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p, TreeNode* q)
    {
        TreeNode* LCA=NULL;
        contains(root,p,q,LCA);
        return LCA;
    }
private:
    
    bool contains(TreeNode* root, TreeNode*& p, TreeNode*& q,TreeNode*& LCA)
    {
        if (LCA || !root)
            return false;
        if (root==p || root==q)
        {
            if (contains(root->left,p,q,LCA) || contains(root->right,p,q,LCA))
            {
                LCA=root;
                return false;
            }
            return true;
        }
        if (contains(root->left,p,q,LCA) && contains(root->right,p,q,LCA))
        {
            LCA=root;
            return false;
        }
        return false;
    }
};

#endif /* IntegerReplacement397_hpp */
