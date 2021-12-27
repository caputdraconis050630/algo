#include <bits/stdc++.h>
using namespace std;

int N;
int board[101][101];
vector<int> arr[101];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            arr[i].push_back(j);
        }
    }
}

/*
0 - > 1
1 - > 2
2 - > 0



*/