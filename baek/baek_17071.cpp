#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MX = 500000;

int little_time[MX + 1]; // 동생이 이동하는데 걸린 시간
int big_time[MX + 1];    // 수빈이가 이동하는데 걸린 시간
bool vist[MX + 1];       // 수빈이의 방문 기록

queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    big_time[n] = 0;
    vist[n] = true;

    // 동생의 이동
    int cnt = 0;
    int now = k;
    while (now <= MX)
    {
        little_time[now] = cnt;
        cnt++;
        now += cnt;
    }

    // 수민이의 BFS
    Q.push(n);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if (cur - 1 >= 0)
        {
            if (vist[cur - 1] == false)
            {
                vist[cur - 1] = true;
                big_time[cur - 1] = big_time[cur] + 1;
                Q.push(cur - 1);
            }
        }

        if (cur + 1 <= MX)
        {
            if (vist[cur + 1] == false)
            {
                vist[cur + 1] = true;
                big_time[cur + 1] = big_time[cur] + 1;
                Q.push(cur + 1);
            }
        }

        if (cur * 2 <= MX)
        {
            if (vist[cur * 2] == false)
            {
                vist[cur * 2] = true;
                big_time[cur * 2] = big_time[cur] + 1;
                Q.push(cur * 2);
            }
        }

        if (vist[k] == true && little_time[k] >= big_time[k])
        {
        }

        // 불가능한 경우
        cout << "-1\n";
    }
}