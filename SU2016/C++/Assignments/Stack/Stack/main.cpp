//
//  main.cpp
//  Stack
//
//  Created by apple on 7/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <stack>

std::string reverse_str(std::string s)
{
    std::string result="";
    std::stack<char> temp;
    
    unsigned long size=s.size();
    
    int i;
    for (i=0; i<size; i++)
    {
        temp.push(s[i]);
    }
    
    for (i=0; i<size; i++)
    {
        result += temp.top();
        temp.pop();
    }
    
    return result;
}

bool matchedPair(char c1, char c2)
{
    if (c1=='{' && c2=='}')
        return 1;
    if (c1=='[' && c2==']')
        return 1;
    if (c1=='(' && c2==')')
        return 1;
    return 0;
}

bool balanced_paren(std::string s)
{
    std::stack<char> temp;
    unsigned long size=s.size();
    for(int i=0; i<size; i++)
    {
        if (s[i]=='(' or s[i]=='{' || s[i]=='[')
            temp.push(s[i]);
        else if (s[i]==')' or s[i]=='}' || s[i]==']')
        {
            if (temp.empty())
                return 0;
            if (!matchedPair(s[i], temp.top()))
                return false;
            temp.pop();
        }
    }
    if (temp.empty())
        return 1;
    else return 0;
}

int main()
{
    std::cout << reverse_str("Hello world") << std::endl;
    std::cout << reverse_str("aabaaaa") << std::endl;
    return 0;
}
