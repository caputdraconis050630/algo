#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNum(int k, int i);
int main()
{

    int t;
    scanf("%d", &t);

    for (int j = 0; j < t; j++)
    {
        int k, i;
        scanf("%d", &k);
        scanf("%d", &i);
        printf("%d\n", getNum(k, i));
    }
    return 0;
}
int getNum(int k, int i)
{
    int arr[15][15];
    for (int i = 0; i < 15; i++)
    {
        arr[i][1] = 1;
        arr[0][i] = i;
    }
    for (int i = 1; i < 15; i++)
    {
        for (int j = 2; j < 15; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[k][i];
}
