#include <bits/stdc++.h>
using namespace std;

int N, M;
string S, tar;
int len;

void set_tar()
{
    tar = "I";
    for (int i = 0; i < N; i++)
    {
        tar += "OI";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int cnt = 0;
    bool flag;

    cin >> N >> M;
    cin >> S;

    set_tar(); // Get Pn String
               /* test set_tar func
    cout << tar << "\n";
    */

    len = 2 * N + 1;

    for (int i = 0; i < M; i++)
    {
        flag = true;
        if (i + len - 1 >= M)
            break;
        for (int j = i; j < i + len; j++)
        {
            if (S[j] != tar[j - i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cnt++;
        }
    }

    // output the result
    cout << cnt << "\n";
}