//
//  main.cpp
//  Oct4Question2
//
//  Created by apple on 10/4/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <iostream>


class TreeNode
{
public:
    TreeNode(int i)
    {
        k=i;
    }
    int k;
    TreeNode *left,*right;
};

class Solution {
    
private:
    int findPosition(int arr[], int start, int end, int key)
    {
        int i;
        for (i = start; i <= end; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* myBuildTree(int inorder[], int instart, int inend,
                                 int postorder[], int poststart, int postend) {
        if (instart > inend) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[postend]);
        int position = findPosition(inorder, instart, inend, postorder[postend]);
        
        root->left = myBuildTree(inorder, instart, position - 1,
                                postorder, poststart, poststart + position - instart - 1);
        root->right = myBuildTree(inorder, position + 1, inend,
                                 postorder, poststart + position - instart, postend - 1);
        return root;
    }
    
public:
    TreeNode buildTree(int inorder[], int postorder[]) {
        if (inorder.size != postorder.size) {
            return nullptr;
        }
        return myBuildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
