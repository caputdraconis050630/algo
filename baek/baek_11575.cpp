#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T; // 테스트 케이스

    string str;

    while (T--)
    {
        queue<char> ans;
        cin >> a >> b;
        cin >> str;

        for (int i = 0; i < str.length(); i++)
        {
            int tmp = (int)(str[i]) - 65;
            int answer = (a * tmp + b) % 26;
            ans.push((char)(answer));
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans.front();
            ans.pop();
        }
        cout << "\n";
    }
}