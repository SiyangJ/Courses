//
//  test_eval.cpp
//  Homework_2_1
//
//  Created by apple on 7/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

bool balanced(string expr);

int main(){
    string s1[5]={
"This class is CS 32 (Summer 2016)",
"John von Neumann (December 28, 1903 – February 8, 1957) was a great computer scientist.",
"(([[]{}]()))",
"Midterm I is on July 11th.",
        "()[]"},
    s2[4]={
"This class is important for many reasons.\n1) It is required for graduation for many majors.",
":-)",
"(:",
    "([)]"};
    for (int i=0; i<5; i++)
    {
        cout << balanced(s1[i]);
    }
    cout << endl;
    for (int i=0; i<4; i++)
        cout << balanced(s2[i]);
    cout << endl;
}
