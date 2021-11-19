#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int ans = 0;
        for (int j = 0; j < 10; j++)
        {
            int tmp;
            cin >> tmp;

            if (tmp % 2)
            {
                ans += tmp;
            }
        }

        printf("#%d %d", i, ans);
    }
    return 0;
}