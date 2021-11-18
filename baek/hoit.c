#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char *s1 = "I am a boy. You are a girl? No, I am a boy. I am a boy and you are a girl.";

    char *sArr[30] = {
        NULL,
    };

    char *boy = "boy";
    char *girl = "girl";

    int i = 0;

    // 원래 문자열 출력
    printf("원래 문자열 : %s\n", s1);

    char *ptr = strtok(s1, " ");

    while (ptr != NULL)
    {
        sArr[i] = ptr;
        i++;

        ptr = strtok(NULL, " ");
    }

    for (int i = 0; i < 30; i++)
    {
        if (sArr[i] != NULL)
        {
            if (strcmp(sArr[i], boy) == 0)
            {
                printf("girl ");
            }
            else if (strcmp(sArr[i], girl) == 0)
            {
                printf("boy ");
            }
            else
            {
                printf("%s ", sArr[i]);
            }
        }
        else
        {
            i = 30; // break
        }
    }

    return 0;
}