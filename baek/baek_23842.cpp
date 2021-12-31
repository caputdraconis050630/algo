#include <bits/stdc++.h>
using namespace std;

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, sum;
    cin >> N;
    bool flag = false;

    int ft, fo, st, so, rt, ro;
    N -= 4;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int result = i + j;
            if (result >= 100)
            {
                j = 100;
                continue;
            }
            ft = i / 10;
            fo = i % 10;

            st = j / 10;
            so = j % 10;

            rt = result / 10;
            ro = result % 10;

            sum = arr[ft] + arr[fo] + arr[st] + arr[so] + arr[rt] + arr[ro];

            if (sum == N)
            {
                if (i < 10 || j < 10 || result < 10)
                {
                    if (i < 10)
                    {
                        cout << "0";
                    }
                    cout << i << "+";

                    if (j < 10)
                    {
                        cout << "0";
                    }
                    cout << j << "=";

                    if (result < 10)
                    {
                        cout << "0";
                    }
                    cout << result << "\n";
                }
                else
                {
                    cout << i << "+" << j << "=" << result << "\n";
                }

                return 0;
            }
        }
    }

    cout << "impossible\n";
    return 0;
}