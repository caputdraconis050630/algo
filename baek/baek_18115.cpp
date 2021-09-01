#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    deque<int> d;

    //  d의 맨 앞(Front)가 위
    cin >> N;

    int arr[N];
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = N; i > 0; i--)
    {
        tmp = arr[i - 1]; // 명령어

        if (tmp == 1)
        {
            // 제일 위의 카드 1 장을 바닥에 내려놓는다
            d.push_front(N - i + 1);
        }
        else if (tmp == 2)
        {
            int v = d.front();
            d.pop_front();
            d.push_front(N - i + 1);
            d.push_front(v);
        }
        else if (tmp == 3)
        {
            d.push_back(N - i + 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << d.at(i) << " ";
    }
}