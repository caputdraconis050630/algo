#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[52][52];
bool vis[52][52];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;

    int M, N, K; // M이 가로, N이 세로, K는 배추의 개수
    pair<int, int> tmp;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    queue<pair<int, int> > Q;
    vector<int> ans;
    while(T--){
        cin>>M>>N>>K;

        // 초기화
        fill(&board[0][0], &board[51][52], 0);
        fill(&vis[0][0], &vis[51][52], false);

        for(int i=0;i<K;i++){
            cin>>tmp.X>>tmp.Y;
            board[tmp.Y][tmp.X] = 1;
        }
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] == false || vis[i][j] == true) continue;
                Q.push(make_pair(i, j));

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for(int dir=0;dir<4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx<0 || nx>=N || ny < 0 || ny>=M) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == true) continue;

                        vis[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
                cnt++;
            }
        }
        ans.push_back(cnt);

        
    }

    for(int i =0;i<ans.size(); i++){
        cout<<ans.at(i)<<"\n";
    }
    
}