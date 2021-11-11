#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    unordered_set<string> S;
    cin >> N;

    string name, status;
    while (N--)
    {
        cin >> name >> status;

        if (status == "enter")
        {
            S.insert(name);
        }
        else
        {
            S.erase(name);
        }
    }

    vector<string> ans(S.begin(), S.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto c : ans)
    {
        cout << c << "\n";
    }
}