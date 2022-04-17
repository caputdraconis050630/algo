#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
int nx, ny;
int board[50][50];
int ans = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int back_x[4] = {1, 0, -1, 0};
int back_y[4] = {0, -1, 0, 1};

bool chk(int nx, int ny)
{
	if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		return false;
	if (board[nx][ny] == 0)
		return true;
	return false;
}

int main(void)
{
	cin >> N >> M;
	cin >> r >> c >> d;
	bzero(board, 2500);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	while (true)
	{
		// one repeat -> clear one area
		if (board[r][c] == 0)
		{
			board[r][c] = 2;
			ans += 1;
		}
		
		if (board[r + dx[d]][c + dy[d]] == 0)
		{
			r += dx[d];
			c += dy[d];
			d = (d + 3) % 4;
		}
		else if (board[r + 1][c] && board[r][c + 1] && board[r - 1][c] && board[r][c - 1])
		{
			if (board[r + back_x[d]][c + back_y[d]] != 1)
			{
				r += back_x[d];
				c += back_y[d];
			}
			else if (board[r + back_x[d]][c + back_y[d]] == 1)
			{
				cout << ans <<"\n";
				return (0);
			}
		}
		else if (board[r + dx[d]][c + dy[d]] != 0)
			d = (d + 3) % 4;
	}
}