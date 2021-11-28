// https://www.acmicpc.net/board/view/78744
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    const int time[11] = {NULL, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    const int alp[11][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {'A', 'B', 'C', 0}, {'D', 'E', 'F', 0}, {'G', 'H', 'I', 0}, {'J', 'K', 'L', 0}, {'M', 'N', 'O', 0}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V', 0}, {'W', 'X', 'Y', 'Z'}, {0}};
    char word[16];
    int sum = 0, i, j, k;
    scanf("%s", word);
    for (k = 0; k < strlen(word); k++)
    {
        for (i = 2; i < 10; i++)
        {

            for (j = 0; j < 4; j++)
            {
                if (alp[i][j] == word[k])
                {
                    sum = sum + time[i];
                    i = 10;
                    break;
                }
            }
        }
    }
    printf("%d", sum);
}