//
//  test_for_many.cpp
//  Homework4
//
//  Created by apple on 8/2/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <vector>
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

int mergeSortPlusCounting(int a[], int n)
{
    int count=0;
    if (n<=1)
        return 0;
    int n1=n/2, n2=n-n1;
    count+=mergeSortPlusCounting(a,n1);
    count+=mergeSortPlusCounting(a+n1,n2);
    int* res=new int[n];
    int* sechalf=a+n1;
    int i=0, j=0, k=0;
    while (i<n1 || j<n2)
    {
        if (i==n1) res[k++]=sechalf[j++];
        else if (j==n2) res[k++]=a[i++];
        else if (a[i]<=sechalf[j]) res[k++]=a[i++];
        else
        {
            res[k++]=sechalf[j++];
            count+=(n1-i);
        }
    }
    for (int i=0; i<n; i++)
    {
        a[i]=res[i];
    }
    delete [] res;
    return count;
}
int countInversions(int a[], int n)
{
    int* b=new int[n];
    for (int i=1; i<n; i++)
    {
        b[i]=a[i];
    }
    int res=mergeSortPlusCounting(b,n);
    delete [] b;
    return res;
}

int countInversions2(int a[], int n)
{
    int count = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (a[j]<a[i]) count++;
        }
    }
    return count;
}

int main()
{
    int maxMultiplier=10;
    int base=100;
    for (int m=1;m<maxMultiplier;m++){
    int n=m*base;
    int range=50;
    int a[n];
    for (int i=0;i<n;i++)
        a[i]=rand()%range+1;
    sort_BST(a, n);
    cout << countInversions2(a, n) << endl;
    }
}
