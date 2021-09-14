#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int tc; // 테스트 케이스
int l;  // 체스판의 한 변의 길이

int pre_x, pre_y;   // 현재의 칸
int dest_x, dest_y; // 이동하려고 하는 칸
int dist[305][305];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    queue<pair<int, int> > Q;

    while (tc--)
    {
        fill(&dist[0][0], &dist[304][305], -1); // 방문하지 않은 곳은 -1
        // queue 초기화
        while (!Q.empty())
        {
            Q.pop();
        }

        cin >> l;
        cin >> pre_x >> pre_y;
        cin >> dest_x >> dest_y;

        dist[pre_x][pre_y] = 0;
        Q.push(make_pair(pre_x, pre_y));

        // BFS 시작
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                {
                    continue; // 범위 초과 필터링
                }

                if (dist[nx][ny] != -1)
                    continue; // 이미 방문했을 시 넘김

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push(make_pair(nx, ny));

            }


            if(dist[dest_x][dest_y] != -1){
                cout<<dist[dest_x][dest_y]<<"\n";
                break;
            }
        }
    }
    return 0; // 정상적으로 프로그램 종료
}