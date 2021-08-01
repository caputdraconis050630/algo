#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string init;
    cin >> init; // 초기 문자열 입력

    list<char> L;
    for (auto c : init)
        L.push_back(c);

    auto cursor = L.end();
    int q; // 반복 횟수
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'P')
        {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (cmd == 'L')
        {
            if (cursor != L.begin())
                cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor != L.end())
                cursor++;
        }
        else
        { // cmd == 'B'
            if (cursor != L.begin())
            {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }

    for (auto c : L)
        cout << c;
}