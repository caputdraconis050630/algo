#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;
int result = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    cin >> S;

    for (int i = 0; i < M; i++)
    {
        int k = 0;
        if (S[i] == 'O') // 시작이 I이기 때문에
            continue;
        // s[i] == 'I'일 때
        else
        {
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                k++;
                if (k == N)
                {
                    k--; // 중복 카운트를 막기 위해 -1 해준다.
                    result++;
                }
                i += 2; // O를 건너 뛴다.
            }
            k = 0;
        }
    }
    cout << result;

    return 0;
}