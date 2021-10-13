#include <stdio.h>

int main(void)
{
    char code1;
    char code2;

    printf("두 개의 문자 입력 : ");
    scanf("%c %c", &code1, &code2);

    printf("첫 번째 문자 코드값 : %d\n", code1);
    printf("두 번째 문자 코드값 : %d\n", code2);

    return 0;
}