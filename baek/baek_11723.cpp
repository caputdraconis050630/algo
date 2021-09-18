#include <bits/stdc++.h>
using namespace std;

int M;
bool arr[21];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;
    string cmd;
    while (M--)
    {
        cin >> cmd;
        if (cmd == "add")
        {
            int target;
            cin >> target;
            arr[target] = true;
        }
        else if (cmd == "remove")
        {
            int target;
            cin >> target;
            arr[target] = false;
        }
        else if (cmd == "check")
        {
            int target;
            cin >> target;
            if (arr[target])
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (cmd == "toggle")
        {
            int target;
            cin >> target;
            if (arr[target])
            {
                arr[target] = false;
            }
            else
            {
                arr[target] = true;
            }
        }
        else if (cmd == "all")
        {
            fill(arr, arr + 21, true);
        }
        else
        {
            // cmd == "empty"
            fill(arr, arr + 21, false);
        }
    }
}