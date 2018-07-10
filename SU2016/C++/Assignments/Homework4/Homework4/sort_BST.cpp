//
//  mergeSort_repetition.cpp
//  Homework4
//
//  Created by apple on 8/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <typename ItemType>
struct Node
{
    Node(){}
    Node(ItemType init):value(init),count(1),left(nullptr),right(nullptr){}
    ItemType value;
    int count;
    Node* left;
    Node* right;
};

template <typename ItemType>
class BST
{
public:
    BST():m_root(nullptr),m_size(0){}
    void insert(const ItemType& value)
    {
        if (m_root==nullptr)
        {
            m_root=new Node<ItemType>(value);
            m_size=1;
            return;
        }
        Node<ItemType>* dummy=m_root;
        if (find(value, dummy))
            dummy->count++;
        else
        {
            Node<ItemType>* newNode=new Node<ItemType>(value);
            Node<ItemType>* temp;
            if (value<dummy->value)
            {
                temp=dummy->left;
                dummy->left=newNode;
                newNode->left=temp;
            }
            else
            {
                temp=dummy->right;
                dummy->right=newNode;
                newNode->right=temp;
            }
        }
        m_size++;
    }
    void print()
    {
        printHelper(m_root);
        cout << endl;
    }
    vector<ItemType> toSortedVector()
    {
        vector<ItemType> vec;
        vec.reserve(m_size);
        toVectorHelper(m_root, vec);
        return vec;
    }
    
private:
    bool find(const ItemType& value, Node<ItemType>*& dummy)
    {
        if (dummy==nullptr)
            return false;
        if (dummy->value==value)
            return true;
        Node<ItemType>* finder;
        if (dummy->value>value)
            finder=dummy->left;
        else
            finder=dummy->right;
        if (find(value, finder))
        {
            dummy=finder;
            return true;
        }
        else
        {
            if (finder!=nullptr)
                dummy=finder;
            return false;
        }
    }
    void printHelper(Node<ItemType>* dummy)
    {
        if (dummy==nullptr)
            return;
        printHelper(dummy->left);
        for (int i=0;i<dummy->count;i++)
            cout << dummy->value << " ";
        printHelper(dummy->right);
    }
    void toVectorHelper(Node<ItemType>* dummy, vector<ItemType>& vec)
    {
        if (dummy==nullptr)
            return;
        toVectorHelper(dummy->left, vec);
        for (int i=0;i<dummy->count;i++)
            vec.push_back(dummy->value);
        toVectorHelper(dummy->right, vec);
    }
    
    int m_size;
    Node<ItemType>* m_root;
};

void sort_BST(int a[], int n)
{
    BST<int> tree;
    for(int i=0;i<n;i++)
        tree.insert(a[i]);
    vector<int> vec=tree.toSortedVector();
    for (int i=0;i<n;i++)
        a[i]=vec[i];
}

void sort_Map(int a[], int n)
{
    map<int, unsigned int> sortMap;
    map<int, unsigned int>::iterator it;
    for (int i=0;i<n;i++)
    {
        it=sortMap.find(a[i]);
        if (it==sortMap.end()) sortMap[a[i]]=1;
        else it->second++;
    }
    int count=0;
    for (it=sortMap.begin();it!=sortMap.end();it++)
    {
        for (int i=0;i<it->second;i++)
        {
            a[count]=it->first;
            count++;
        }
    }
}

int main()
{
    int n=10;
    int range=500;
    int a[10];
    for (int i=0;i<n;i++)
        a[i]=rand()%range+1;
    sort_Map(a, n);
    for (int i=0;i<n;i++)
        cout << a[i] << endl;
}

