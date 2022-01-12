#include <string>
#include <vector>
#include <queue>

using namespace std;

bool chk[201];

int solution(int n, vector<vector<int>> computers)
{
    // 변수 선언
    int answer = 0;
    queue<int> Q;

    // 배열 초기화
    fill(chk, chk + 200, false);

    for (int i = 0; i < n; i++)
    {
        if (chk[i] == false)
        {
            Q.push(i);
            answer++;
        }

        while (!Q.empty())
        {
            int cur = Q.front();
            chk[cur] = true;
            Q.pop();

            for (int j = 0; j < n; j++)
            {
                if (chk[j] == false && computers[cur].at(j) == 1)
                {
                    Q.push(j);
                }
            }
        }
    }

    return answer;
}