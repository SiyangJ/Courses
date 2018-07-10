//
//  eval.cpp
//  Homework_2_1
//
//  Created by apple on 7/9/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <string>
#include <stack>

using namespace std;

bool balanced(std::string expr)
{
    stack<char> stk;
    for (int i=0; i<expr.size(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
            stk.push(expr[i]);
        if (expr[i]==')')
        {
            if (stk.empty()||stk.top()!='(')
                return 0;
            stk.pop();
        }
        else if (expr[i]==']')
        {
            if (stk.empty()||stk.top()!='[')
                return 0;
            stk.pop();
        }
        else if (expr[i]=='}')
        {
            if (stk.empty()||stk.top()!='{')
                return 0;
            stk.pop();
        }
    }
    if (stk.empty())
        return 1;
    return 0;
}
