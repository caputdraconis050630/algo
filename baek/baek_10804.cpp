#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int a, b, tmp, iterator_cnt;
    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        iterator_cnt = ceil(double(b - a) / 2);
        for (int j = 0; j < iterator_cnt; j++)
        {
            tmp = arr[a];
            arr[a] = arr[b];
            arr[b] = tmp;
            a += 1;
            b -= 1;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
}