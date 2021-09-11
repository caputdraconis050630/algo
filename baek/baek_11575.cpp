#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T; // 테스트 케이스
    queue<char> ans;

    while (T--)
    {
        string str;
        cin >> a >> b;
        cin >> str;

        for (int i = 0; i < str.length(); i++)
        {
            int tmp = str[i] - 'A';

            int answer = (a * tmp + b) % 26;
            // cout << char(answer + 'A') << "\n";
            ans.push((char)(answer + 'A'));
        }

        while (!ans.empty())
        {
            cout << ans.front();
            ans.pop();
        }
        cout << "\n";
    }
}