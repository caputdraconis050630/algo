#include <bits/stdc++.h>
using namespace std;

const int MX = 200000;

bool vist[MX + 1];
int dist[MX + 1];
int from[MX + 1]; // 경로 추적을 위한 배열
queue<int> Q;
int n, k;
int dx[2] = {-1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vist[n] = true;
    Q.push(n);
    dist[n] = 0;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if (cur - 1 >= 0)
        {
            if (vist[cur - 1] == false)
            {
                Q.push(cur - 1);
                vist[cur - 1] = true;
                dist[cur - 1] = dist[cur] + 1;
                from[cur - 1] = cur;
            }
        }

        if (cur + 1 < MX)
        {
            if (vist[cur + 1] == false)
            {
                Q.push(cur + 1);
                dist[cur + 1] = dist[cur] + 1;
                vist[cur + 1] = true;
                from[cur + 1] = cur;
            }
        }

        if (cur * 2 < MX)
        {
            if (vist[cur * 2] == false)
            {
                Q.push(cur * 2);
                dist[cur * 2] = dist[cur] + 1;
                vist[cur * 2] = true;
                from[cur * 2] = cur;
            }
        }
    }

    cout << dist[k] << "\n";

    stack<int> trace;

    for (int i = k; i != n; i = from[i])
    {
        trace.push(i);
    }
    trace.push(n);

    while (!trace.empty())
    {
        cout << trace.top() << " ";
        trace.pop();
    }

    cout << '\n';
    return 0;
}