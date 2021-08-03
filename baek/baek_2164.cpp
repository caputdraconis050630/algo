#include <bits/stdc++.h>
using namespace std;

const int MX = 500001;
int dat[MX];
int head = 0, tail = 0;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    queue<int> que;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        que.push(i);
    }

    if (N == 1)
    {
        cout << "1"
             << "\n";
        return 0;
    }
    while (que.size() != 1)
    {
        que.pop();
        if (que.size() == 1)
        {
            break;
        }
        int tmp = que.front();
        que.pop();
        que.push(tmp);
    }

    cout << que.front() << "\n";
}