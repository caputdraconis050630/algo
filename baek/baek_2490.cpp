#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4];
    int cnt;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        cnt = count(arr, arr + 4, 0);
        if (cnt == 1)
            cout << "A"
                 << "\n";
        else if (cnt == 2)
            cout << "B"
                 << "\n";
        else if (cnt == 3)
            cout << "C"
                 << "\n";
        else if (cnt == 4)
            cout << "D"
                 << "\n";
        else
            cout << "E"
                 << "\n";
    }
}