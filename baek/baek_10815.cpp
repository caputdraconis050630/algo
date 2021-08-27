#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int N, M;
// bool binary_search(int num)
// {
//     int start = 0;
//     int end = N - 1;

//     while (start <= end)
//     {
//         int mid = (start + end) / 2;
//         if (v.at(mid) == num)
//         {
//             return true;
//         }
//         else if (v.at(mid) < num)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return false;
// }

int main()
{
    cin >> N;
    int input;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &input);
        if (binary_search(v.begin(), v.end(), input))
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
}