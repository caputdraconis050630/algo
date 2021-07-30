#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    int arr[10] = {
        0,
    };
    cin >> A >> B >> C;
    // result 최대값이 1,000,000 미만이기 때문에 int로 설정
    int result = A * B * C;
    int tmp;
    for (int i = 0; i < 9; i++)
    {
        tmp = result % 10;
        arr[tmp]++;
        result /= 10;
        if (result == 0)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << arr[j] << "\n";
            }
            break;
        }
    }
}