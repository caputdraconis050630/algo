#include <bits/stdc++.h>
using namespace std;

bool comp(const string a, const string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> dict;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        dict.push_back(input);
    }

    // 중복값 제거
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());

    sort(dict.begin(), dict.end(), comp);

    for (auto c : dict)
    {
        cout << c << "\n";
    }
}