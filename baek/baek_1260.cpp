#include <bits/stdc++.h>
using namespace std;

int N, M, V;

int vist[1005];
stack<int> S;
queue<int> Q;

deque<int> D[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        D[x].push_back(y);
        D[y].push_back(x);
    }

    for (int i = 1; i < N + 1; i++)
    {
        sort(D[i].begin(), D[i].end());
    }

    // DFS
    fill(&vist[0], &vist[1004], -1);
    S.push(V); // starting point

    while (!S.empty())
    {
        int cur = S.top();
        S.pop();
        if (vist[cur] != -1)
            continue;

        cout << cur << " ";
        vist[cur] = 1;

        int qsize = D[cur].size();
        for (int i = qsize - 1; i >= 0; i--)
        {
            if (vist[D[cur].at(i)] != -1)
                continue;
            S.push(D[cur].at(i));
        }
    }

    // next line
    cout << "\n";

    // BFS
    fill(&vist[0], &vist[1004], -1);

    Q.push(V); // starting point

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        if (vist[cur] != -1)
            continue;

        vist[cur] = 1;

        cout << cur << " ";

        int qsize = D[cur].size();
        for (int i = 0; i < qsize; i++)
        {
            if (vist[D[cur].at(i)] != -1)
                continue;
            Q.push(D[cur].at(i));
        }
    }

    return 0;
}