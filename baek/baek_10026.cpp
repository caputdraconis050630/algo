// 적록색약 : red-green color weakness

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[105];
bool check[105][105];
int l;
int original_cnt = 0; // 일반인 카운트
int rgw_cnt = 0;	  // 적록색약 카운트

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int> > Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		cin >> board[i];
	}

	fill(&check[0][0], &check[104][105], false);

	// 일반인 BFS
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (check[i][j] == false)
			{
				original_cnt++;
				Q.push(make_pair(i, j));
				check[i][j] = true;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= l || ny < 0 || ny >= l)
						{
							continue;
						}

						if (board[nx][ny] != board[cur.X][cur.Y])
							continue;

						if(check[nx][ny] == true){
							continue;
						}

						Q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
		}
	}

	fill(&check[0][0], &check[104][105], false);

	// 적록색약 BFS
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (check[i][j] == false)
			{
				rgw_cnt++;
				Q.push(make_pair(i, j));
				check[i][j] = true;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= l || ny < 0 || ny >= l)
						{
							continue;
						}

						if(board[cur.X][cur.Y] == 'R'){
							if(board[nx][ny] == 'B'){
								continue;
							}
						}
						else if(board[cur.X][cur.Y] == 'G'){
							if(board[nx][ny] == 'B'){
								continue;
							}
						}
						else{
							if(board[nx][ny] != 'B'){
								continue;
							}
						}

						if(check[nx][ny] == true){
							continue;
						}

						Q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
		}
	}


	cout << original_cnt << " " << rgw_cnt << "\n";
	return 0;
}
