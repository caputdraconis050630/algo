#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int min = 100;
    ;
    int arr[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
            if (min > arr[i])
                min = arr[i];
        }
    }

    if (sum == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << sum << "\n"
             << min;
    }
}

// 홀수인지를 검사할 때 2로 나눈 나머지가 0인지 보는 것보다 비트 연산자 &을 사용
// sum % 1로 바꿀 수 있음