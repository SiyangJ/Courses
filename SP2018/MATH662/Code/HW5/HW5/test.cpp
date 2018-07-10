//
//  test.cpp
//  HW5
//
//  Created by apple on 3/13/18.
//  Copyright © 2018 UNC. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <new>
#include <stdlib.h>

#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
using namespace std::chrono;

double f()
{
    while(true)
    {}
    return 0;
}

double solveWrapper(double wait,bool LP,int dim)
{
    mutex m;
    condition_variable cv;
    double retValue;
    
    thread t([&m, &cv, &retValue]()
             {
                 retValue = f();
                 cv.notify_one();
             });
    
    t.detach();
    
    {
        std::unique_lock<std::mutex> l(m);
        if(cv.wait_for(l, duration<double>(wait)) == std::cv_status::timeout)
        {
            throw std::runtime_error("Timeout");
            ///////////////////////////////////
            // QUESTION
            // Somehow terminate thread t
        }
    }
    
    return retValue;
}


int main()
{
    /*
    for (int i=1;i<10;i++)
    {
        int n=1000*i;
        printf("n = %d\n",n);
    try {
        vector<double> *v = new vector<double>(n*n*n);
        delete v;
    } catch (bad_alloc &ba) {
        printf("Bad allocation\n");
        break;
    }
    }
     */
    try{
    solveWrapper(5, true, 10);
    }
    catch(exception& e)
    {
        printf("Hahaha\n");
    }
    exit(0);
}
