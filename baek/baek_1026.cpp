#include <bits/stdc++.h>
using namespace std;

int B[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int sum = 0;
    cin >> N;
    int tmp;
    vector<int> A;
    int index;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        B[tmp]++;
    }

    // 내림차순 정렬
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (B[j] > 0)
            {
                index = j;
                break;
            }
        }
        sum += A[i] * index;
        B[index] -= 1;
    }

    cout << sum << "\n";
}