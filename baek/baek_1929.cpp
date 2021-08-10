#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;
    queue<int> q;

    for (int i = M; i <= N; i++)
    {
        bool flag = true;
        for (int k = 2; k < i; k++)
        {
            if (i % k == 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            q.push(i);
        }
    }

    for (int i = 0; i < q.size(); i++)
    {
        cout << q.front() << "\n";
        q.pop();
    }
}