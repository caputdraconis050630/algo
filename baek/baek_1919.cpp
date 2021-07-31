#include <bits/stdc++.h>
using namespace std;

int word1_arr[26];
int word2_arr[26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word1, word2;
    cin >> word1 >> word2;
    int cnt = 0;
    int t = 0;
    while (word1[t] != '\0')
    {
        word1_arr[word1[t] - 'a']++;
        t++;
    }
    t = 0;
    while (word2[t] != '\0')
    {
        word2_arr[word2[t] - 'a']++;
        t++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (word1_arr[i] < word2_arr[i])
        {
            cnt += (word2_arr[i] - word1_arr[i]);
        }
        else
        {
            cnt += (word1_arr[i] - word2_arr[i]);
        }
    }

    cout << cnt;
}