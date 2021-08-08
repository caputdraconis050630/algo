#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> q;

    // 벡터 초기화
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    int count = 1;
    cout << "<";
    while (!q.empty())
    {
        if (count % K == 0)
        {
            int ans = q.front();
            q.pop();
            if (q.empty())
            {
                cout << ans << ">";
            }
            else
            {
                cout << ans << ", ";
            }
        }
        else
        {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        count++;
    }
}