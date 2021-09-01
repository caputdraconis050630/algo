#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, B;
    int height;
    int min_time = 0x7f7f7f7f;
    int time;
    int mine[500][500];
    cin >> N >> M >> B;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            cin >> tmp;
            mine[i][k] = tmp;
        }
    }

    for (int h = 0; h <= 256; h++)
    {
        int build = 0;
        int remove = 0;

        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < M; k++)
            {
                tmp = mine[i][k] - h;

                if (tmp > 0)
                {
                    //  remove
                    remove += tmp;
                }
                else if (tmp < 0)
                {
                    build -= tmp;
                }
            }
        }
        if (B + remove >= build)
        {
            time = 2 * remove + build;
            if (min_time >= time)
            {
                min_time = time;
                height = h;
            }
        }
    }
    cout << min_time << " " << height << "\n";
}