#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> input;
vector<int> V;

void solution(int cnt)
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

    for (int j = 0; j < N; j++)
    {
        // 이미 있는지 체크
        bool flag = true;
        for (int k = 0; k < V.size(); k++)
        {
            if (V.at(k) == input.at(j))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            V.push_back(input.at(j));
            solution(cnt + 1);
            V.pop_back();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    sort(input.begin(), input.end());

    solution(0);
}