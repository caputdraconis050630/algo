/*
    ascii
    'a' : 97
    'z' : 122
*/

#include <bits/stdc++.h>

using namespace std;

string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

stack<int> stk;

void getStack(string s)
{
    int size = s.length();

    for (int i = 0; i < size; i++)
    {
        if (s.at(i) >= 'a' and s.at(i) <= 'z')
        {
            /*
             need convert
            
            compare first, second char
            */

            for (int j = 0; j < 10; j++)
            {
                if (s.at(i) == arr[j].at(0) and s.at(i + 1) == arr[j].at(1))
                {
                    // find
                    stk.push(j);
                    i += arr[j].length() - 1;

                    j = 10; // break for loop
                }
            }
        }
        else
        {
            stk.push(s.at(i) - '0');
        }
    }
}

int solution(string s)
{
    int answer = 0;

    getStack(s);

    for (int i = 0; i < stk.size(); i++)
    {
        answer += stk.top() * pow(10, i);
        stk.pop();
    }

    return answer;
}