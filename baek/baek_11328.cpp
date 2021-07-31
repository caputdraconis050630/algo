#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool chk = false;
    int N;
    string str1, str2;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        chk = true;
        int k = 0;
        int arr[26] = {
            0,
        };

        cin >> str1 >> str2;
        while (str1[k] != '\0')
        {
            arr[str1[k] - 'a'] += 1;
            k++;
        }

        k = 0;

        while (str2[k] != '\0')
        {
            arr[str2[k] - 'a']--;
            k++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (arr[j] != 0)
                chk = false;
        }

        if (chk)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}