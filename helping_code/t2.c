// https://www.acmicpc.net/board/view/78739
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char input[101];
    int input_case;
    int length;
    int cnt = 0;

    scanf("%d", &input_case);

    for (int i = 0; i < input_case; i++)
    {
        scanf("%s", input);
        //printf("%s\n", input);
        length = strlen(input);
        for (int j = 0; j < length; j++)
        {
            for (int t = j + 1; t < length; t++)
            {
                if (input[j] == input[t] && abs(j - t) > 1 && input[t] != input[t - 1])
                {
                    cnt++;
                    //printf("Update flag\n");
                    j = length;
                    break;
                }
            }
        }
        //printf("cnt = %d\n", cnt);
    }

    printf("%d\n", input_case - cnt++);

    return 0;
}