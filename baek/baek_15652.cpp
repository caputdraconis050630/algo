#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> V;

void solution(int start, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << V.at(i) << " ";
        }
        cout << "\n";

        cnt--;
        return;
    }
    for(int j=start;j<=N;j++){
        V.push_back(j);
        solution(j, cnt+1);
        V.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    solution(1, 0);
}