//
//  Nov10.c
//  CTest
//
//  Created by apple on 11/10/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <stdio.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node tree[] = {
    {42, tree+1, tree+2},
    {30, tree+3, tree+4},
    {80, tree+5, tree+6},
    {10, NULL, NULL},
    {35, tree+7, tree+8},
    {50, NULL, tree+9},         /* Bug 1: the first 'tree+5' should be 'NULL' */
    {90, tree+10, tree+11},
    {32, NULL, NULL},
    {40, NULL, NULL},
    {60, NULL, NULL},
    {85, NULL, NULL},
    {95, NULL, NULL}
};

void depthFirst(struct node *tptr) {
    /* A depth-first traversal of a binary tree */
    if (tptr->left != NULL)
        depthFirst(tptr->left);
    printf("%2ld: %d\n", (long int) (tptr-tree), tptr->value);
    if (tptr->right != NULL)
        depthFirst(tptr->right);
}

void addNode(struct node *tptr, struct node *nptr) {
    /* Add a new node to an ordered binary tree */
    if (nptr->value >= tptr->value)
        if (tptr->right == NULL)
            tptr->right = nptr;
        else
            addNode(tptr->right, nptr);
        else
            if (tptr->left == NULL)        /* Bug 2: 'tpt->right' should be 'tptr->left' */
                tptr->left = nptr;
            else
                addNode(tptr->left, nptr);
    
}

void printTree(struct node* root, int level)
{
    if (root==NULL) return;
    for (int i=0;i<level;i++)
        printf("  ");
    printf("%d:\n",root->value);
    printTree(root->left,level+1);
    printTree(root->right,level+1);
}

int main() {
    struct node newNode1 = {45, NULL, NULL};
    printf("Before:\n");
    depthFirst(tree);
    addNode(tree, &newNode1);
    printf("After:\n");
    depthFirst(tree);
    
    printTree(tree,0);
    
    /*
    printf("%d:\n",tree[0].value);
    printf("  %d:\n",tree[1].value);
    printf("    %d:\n",tree[3].value);
    printf("    %d:\n",tree[4].value);
    printf("      %d:\n      %d:\n",tree[7].value,tree[8].value);
    printf("  %d:\n",tree[2].value);
    printf("    %d:\n",tree[5].value);
    printf("      %d:\n      %d:\n",newNode1.value,tree[9].value);
    printf("    %d:\n",tree[6].value);
    printf("      %d:\n      %d:\n",tree[10].value,tree[11].value);
     */
    
}