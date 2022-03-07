#include <iostream>
using namespace std;

int N;
int board[15];
int ans = 0;

bool chk_ganeung(int index, int now)
{
    // Check Same Column
    for (int i = 0; i < index; i++)
    {
        if (board[i] == now)
            return false;
        if ((index - i) == abs(now - board[i]))
            return false;
    }
    return true;
}

void DFS(int index)
{
    if (index == N)
    {
        ans += 1;
        return ;
    }
    for (int i = 0;i < N; i++)
    {
        if (chk_ganeung(index, i))    
        {
            board[index] = i;
            DFS(index + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        board[0] = i; 
        DFS(1);
    }
    cout << ans << "\n";
    return (0);
}