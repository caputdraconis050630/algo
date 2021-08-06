#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); ++i)
    {
        // 대문자인 경우
        if (input.at(i) >= 65 && input.at(i) <= 90)
        {
            alphabet[input.at(i) - 65]++;
        }
        // 소문자인 경우
        else if (input.at(i) >= 97 && input.at(i) <= 122)
        {
            alphabet[input.at(i) - 97]++;
        }
    }

    int max = 0;
    int max_index;
    for (int i = 0; i < 26; i++)
    {
        if (max < alphabet[i])
        {
            max = alphabet[i];
            max_index = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (max == alphabet[i] && max_index != i)
        {
            cout << "?\n";
            return 0;
        }
    }

    cout << char(max_index + 65) << "\n";
}