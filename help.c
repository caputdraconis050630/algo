#include <stdio.h>

#define num 9

int main()
{
    int data[num] = {8, 6, 3, 7, 2, 5, 4, 1, 0};
    int temp1 = 0;
    int temp2 = 0;

    // Data Print
    printf("데이터 : ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    // Bubble Sort
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp1 = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp1;

                for (int t = 0; t < num; t++)
                    printf("%d ", data[t]);
                printf("\n");
            }
        }
    }
    printf("\n");
    // Bubble Sort result
    printf("\n버블 정렬을 사용하여 오름차순한 결과 : ");
    for (int i = 0; i < num; i++)
        printf("%d ", data[i]);
    printf("\n\n");
    // Selection Sort
    int Max;
    for (int i = 0; i < num - 1; i++)
    {
        Max = i;
        for (int j = i + 1; j < num; j++)
        {
            if (data[j] > data[Max])
            {
                Max = j;
            }
        }
        temp2 = data[Max];
        data[Max] = data[i];
        data[i] = temp2;

        if (Max != i)
        {
            for (int t = 0; t < num; t++)
                printf("%d ", data[t]);
            printf("\n");
        }
    }
    printf("\n\n");
    // Selection Sort
    printf("\n선택 정렬을 사용하여 오름차순한 결과 : ");
    for (int i = 0; i < num; i++)
        printf("%d ", data[i]);
    printf("\n\n");
    return 0;
}