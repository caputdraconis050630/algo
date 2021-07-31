#include <bits/stdc++.h>
using namespace std;

int arr[12];
/*
    1학년 여자 arr[0] 남자 arr[1]
    2학년 여자 arr[2] 남자 arr[3]
    3학년 여자 arr[4] 남자 arr[5]
    4학년 여자 arr[6] 남자 arr[7]
    5학년 여자 arr[8] 남자 arr[9]
    6학년 여자 arr[10] 남자 arr[11]
*/
int main()
{
    int cnt = 0;
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    int sex, grade;
    for (int i = 0; i < N; i++)
    {
        cin >> sex >> grade;
        arr[(grade - 1) * 2 + sex]++;
    }

    for (int i = 0; i < 12; i++)
    {
        if (arr[i])
        {
            cnt += ceil(double(arr[i]) / K);
        }
    }

    cout << cnt;
}