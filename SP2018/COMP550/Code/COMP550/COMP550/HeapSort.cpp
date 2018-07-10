//
//  HeapSort.cpp
//  COMP550
//
//  Created by apple on 2/20/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
    for(int i=0;i<vec.size();i++)
        cout << vec[i] << ' ';
    cout << endl;
}

void maxHeapify(vector<int>& vec,int s,int i)
{
    int l=i;
    if (2*i+1<s && vec[l]<vec[2*i+1])
        l=2*i+1;
    if (2*i+2<s && vec[l]<vec[2*i+2])
        l=2*i+2;
    if (l!=i)
    {
        swap(vec[i],vec[l]);
        maxHeapify(vec,s,l);
    }
}

void heapSort(vector<int>& vec)
{
    for (int i=vec.size()/2-1;i>=0;i--)
    {
        maxHeapify(vec,vec.size(),i);
    }
    for (int i=vec.size()-1;i>0;i--)
    {
        swap(vec[0],vec[i]);
        maxHeapify(vec,i,0);
    }
}

int main()
{
    vector<int> test = {9,7,10,0,5,4,9,9,8,7,20,1,0};
    heapSort(test);
    printVector(test);
}
