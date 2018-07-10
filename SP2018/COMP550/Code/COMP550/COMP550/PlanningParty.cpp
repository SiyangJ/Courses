//
//  main.cpp
//  COMP550
//
//  Created by apple on 2/14/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

using namespace std;

class Node
{
public:
    Node*leftChild;
    Node*rightSibling;
    
    string Name;
    float conv;
};

map<Node*,tuple<tuple<float,Node*>,tuple<float,Node*>>> P;

Node* root;

void planParty(Node* root)
{
    try {
        P.at(root);
        return;
    } catch (out_of_range e) {
        if (root->leftChild)
            planParty(root->leftChild);
        if (root->rightSibling)
            planParty(root->rightSibling);
        P[root];
        
        Node* cur=root->leftChild;
        
    }
    
}


int main() {
    
    



    return 0;
}
