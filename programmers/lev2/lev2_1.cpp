#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'z')
        {
            s[i] = tolower(s[i]);
        }

        if (i - 1 >= 0 && s[i - 1] == ' ')
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = toupper(s[i]);
            }
        }
    }

    if (s[0] >= 'A' && s[0] <= 'z')
        s[0] = toupper(s[0]);

    return s;
}

int main()
{
    cout << solution("3people unFollowed me");
    cout << solution("for the last week");
}