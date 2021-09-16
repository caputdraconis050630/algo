#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000;
int F, S, G, U, D;
/*
    F : 건물의 크기(총 층수)
    S : 강호가 현재 있는 층수
    G : 가려고 하는 층수
    
    U : 위로 U층을 가는 버튼
    D : 아래로 D층을 가는 버튼
*/

int dist[MX + 5];
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;


    fill(dist, dist + MX + 4, -1); // 방문하지 않은 층은 -1

    dist[S] = 0;
    Q.push(S);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if (cur + U <= F)
        {
            if (dist[cur + U] == -1)
            {
                Q.push(cur + U);
                dist[cur + U] = dist[cur] + 1;
            }
        }

        if (cur - D >= 1)
        {
            if (dist[cur - D] == -1)
            {
                Q.push(cur - D);
                dist[cur - D] = dist[cur] + 1;
            }
        }

        // 탈출 조건
        if (dist[G] != -1)
        {
            cout << dist[G] << "\n";
            return 0;
        }
    }

    cout << "use the stairs\n";
    return 0;
}