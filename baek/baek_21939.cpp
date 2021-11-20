#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<pair<int, int>> hard; // 난이도 | 문제번호
    map<int, int> Map;             // 문제 번호 | 난이도

    int N, M, P, L;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> P >> L; // 문제 번호 | 난이도

        hard.insert({L, P});
        Map[P] = L;
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        string cmd;
        int arg1, arg2;
        cin >> cmd;
        if (cmd == "recommend")
        {
            cin >> arg1; // 1 or -1

            if (arg1 == 1)
            {
                // 가장 어렵고 문제 번호가 가장 큰거
                auto it = prev(hard.end());

                cout << it->second << "\n";
            }
            else
            {
                auto it = hard.begin();

                cout << it->second << "\n";
            }
        }
        else if (cmd == "add")
        {
            cin >> arg1 >> arg2; // 문제 번호 | 난이도

            hard.insert({arg2, arg1});
            Map[arg1] = arg2;
        }
        else
        {
            cin >> arg1;

            int lev = Map[arg1];

            auto it = hard.find({lev, arg1});

            hard.erase(it);
        }
    }
}