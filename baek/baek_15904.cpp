#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[1001];
    bool flag = false;
    int idx = 0;
    int count = 0;

    cin.getline(str, 1000, '\n');

    while (str[idx] != '\0')
    {
        if (str[idx] == 'U' && count == 0)
        {
            count++;
        }
        else if (str[idx] == 'C' && count == 1)
        {
            count++;
        }
        else if (str[idx] == 'P' && count == 2)
        {
            count++;
        }
        else if (str[idx] == 'C' && count == 3)
        {
            count++;
            flag = true;
        }
        idx++;
    }

    if (flag)
    {
        cout << "I love UCPC" << endl;
    }
    else
    {
        cout << "I hate UCPC" << endl;
    }

    return 0;
}