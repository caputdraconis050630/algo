#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[101] = "12345678 홍길동 178.5 70.3";

    char *sArr[5];

    char *ptr = strtok(s1, " ");

    int i = 0;

    while (ptr != NULL)
    {
        sArr[i] = ptr;

        i++;
        ptr = strtok(NULL, " ");
    }

    printf("ID: %d\n\n", atoi(sArr[0]));
    printf("NAME: %s\n\n", sArr[1]);
    printf("HEIGHT: %f\n\n", atof(sArr[2]));
    printf("WEIGHT: %f\n\n", atof(sArr[3]));
}
