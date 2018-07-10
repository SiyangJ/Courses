//
//  main.cpp
//  Recursion
//
//  Created by apple on 7/22/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int Fibonacci(unsigned int x)
{
    if (x==1||x==2)
        return 1;
    return Fibonacci(x-1)+Fibonacci(x-2);
}

bool isPalindrome(string& str, int start, int end)
{
    if (start>=end)
        return true;
    return isPalindrome(str, start+1, end-1)&&(str[start]==str[end]);
}

int main()
{
    string a="1221";
    cout << isPalindrome(a,0,3) << endl;
}
