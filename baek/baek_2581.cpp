#include <bits/stdc++.h>
using namespace std;

bool arr[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min, max;
    int sum = 0;

    int min_num = 10001;
    cin >> min >> max;
    fill_n(arr, 10001, true);
    arr[0] = false;
    arr[1] = false;

    for (int i = 2; i < sqrt(max); i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * 2; j <= max; j += i)
            {
                arr[j] = false;
            }
        }
    }

    for (int i = min; i <= max; i++)
    {
        if (arr[i] == true)
        {
            if (min_num > i)
                min_num = i;
            sum += i;
        }
    }

    if (sum == 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << sum << "\n"
             << min_num << "\n";
    }
}