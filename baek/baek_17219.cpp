#include <bits/stdc++.h>
using namespace std;

int M, N;
map<string, string> memo;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    string domain, password;
    for (int i = 0; i < N; i++)
    {
        cin >> domain >> password;

        memo.insert({domain, password});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> domain;

        cout << memo.find(domain)->second << "\n";
    }

    return 0;
}