//
//  main.cpp
//  Infix2Postfix
//
//  Created by apple on 7/1/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <cmath>
using namespace std;

bool IsDigit(const char& a)
{
    if (a=='1' or a=='2' or a=='3' or a=='4' or a=='5' or a=='6' or a=='7' or a=='8' or a=='9' or a=='0')
        return 1;
    return 0;
}

int Precedence(const char& a)
{
    if (a=='^')
        return 4;
    if (a=='/')
        return 3;
    if (a=='*')
        return 2;
    else return 1;
}

bool IsOperator(const char& thing)
{
    if (thing=='+' || thing=='-' || thing=='*' || thing=='/' || thing=='^')
        return 1;
    else return 0;
}

string ToPostFix(const string& infix)
{
    string postfix="";
    stack<char> m_stack;
    int preOfCurr;
    unsigned long size=infix.size();
    for (int i=0; i<size; i++)
    {
        if (IsDigit(infix[i]))
            postfix+=infix[i];
        else if (IsOperator(infix[i]))
        {
            preOfCurr=Precedence(infix[i]);
            if (m_stack.empty())
                m_stack.push(infix[i]);
            else
            {
                while (!m_stack.empty() && preOfCurr<Precedence(m_stack.top()) && m_stack.top()!='(')
                {
                    postfix+=m_stack.top();
                    m_stack.pop();
                }
                m_stack.push(infix[i]);
            }
        }
        else if (infix[i]=='(')
            m_stack.push(infix[i]);
        else if (infix[i]==')')
        {
            while (!m_stack.empty()&&m_stack.top()!='(')
            {
                postfix+=m_stack.top();
                m_stack.pop();
            }
            if (m_stack.empty())
                return "Error";
            m_stack.pop();
        }
        else return "Error";
    }
    while (!m_stack.empty())
    {
        if (m_stack.top()=='(')
            return "Error";
        postfix+=m_stack.top();
        m_stack.pop();
    }
    return postfix;
}


double CalcPostfix(const string& postfix)
{
    stack<double> m_stack;
    double temp;
    unsigned long size=postfix.size();
    if (size==0)
    {
        cout << "Error: empty expression!\n";
        return 0;
    }
    for (int i=0; i<size; i++)
    {
        if (IsDigit(postfix[i]))
            m_stack.push((postfix[i]-48));
        else if (IsOperator(postfix[i]))
        {
            if (m_stack.empty())
            {
                cout << "Error: wrong expression!\n";
                return 0;
            }
            temp=m_stack.top();
            m_stack.pop();
            if (m_stack.empty())
            {
                cout << "Error: wrong expression!\n";
                return 0;
            }
            switch (postfix[i])
            {
                case '+':
                {
                    temp+=m_stack.top();
                    break;
                }
                case '-':
                {
                    temp-=m_stack.top();
                    break;
                }
                case '*':
                {
                    temp*=m_stack.top();
                    break;
                }
                case '/':
                {
                    temp=static_cast<double>(m_stack.top())/temp;
                    break;
                }
                case '^':
                {
                    temp=pow(m_stack.top(),temp);
                    break;
                }
                default:
                    break;
            }
            m_stack.pop();
            m_stack.push(temp);
        }
        else
        {
            cout << "Error: unexpected character!\n";
        }
    }
    m_stack.pop();
    if (!m_stack.empty())
    {
        cout << "Error: wrong expression!\n";
        return 0;
    }
    else return temp;
}

int main()
{
    cout << CalcPostfix(ToPostFix("(3+5)/2^2+3*2^2^(2*2/2^2)")) << endl;
    return 0;
}
