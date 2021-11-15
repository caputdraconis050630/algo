#include <bits/stdc++.h>

#define X first
#define Y second



using namespace std;

int N, M;
int virus_map[10][10];
vector<pair<int, int> > V;
queue<pair<int, int> > Q;

int ans = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void spreadVirus()
{
    int copyMap[10][10];

    // 기둥 세개를 채운 맵을 복사
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            copyMap[i][j] = virus_map[i][j];
        }
    }

    for (int i = 0; i < V.size(); i++)
    {
        Q.push(V.at(i));
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 or ny < 0 or nx >= N or ny >= M)
                continue;
            if(copyMap[nx][ny] != 0) continue;

            copyMap[nx][ny] = 2;
            Q.push(make_pair(nx, ny));
        }
    }
    int cntSafeZone=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(copyMap[i][j] == 0){
                cntSafeZone++;
            }
        }
    }

    ans = max(ans, cntSafeZone);
}

void setPillar(int x, int cnt)
{
    if (cnt == 3)
    {
        // 기둥 3개를 다 세웠을 때
        spreadVirus();
        return;
    }

    for (int i = x; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (virus_map[i][j] == 0)
            {
                virus_map[i][j] = 1; // 기둥 세우기
                setPillar(i, cnt + 1);

                // 원상복구
                virus_map[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> virus_map[i][j];

            if (virus_map[i][j] == 2)
            {
                V.push_back(make_pair(i, j));
            }
        }
    }

    setPillar(0, 0);

    cout<<ans<<"\n";
}