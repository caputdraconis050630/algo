#include <bits/stdc++.h>
using namespace std;

int alphabet[26];
int main()
{

    string word;
    cin >> word;

    for (auto c : word)
        alphabet[c - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }
}