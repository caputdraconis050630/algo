#include <bits/stdc++.h>
using namespace std;

int weight[50];
int height[50];
int rank_dungchi[50];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 사람의 수
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                if (weight[j] > weight[i] && height[j] > height[i])
                {
                    rank_dungchi[i]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << rank_dungchi[i] + 1 << " ";
    }

    cout << "\n";
}