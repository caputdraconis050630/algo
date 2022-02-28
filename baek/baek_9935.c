#include <stdio.h>
#include <string.h>

char arr[1000005], answer[1000005], bomb[40];
int bomb_len,arr_bottom=-1,arr_top,answer_top=-1,flag;
 
void check_1(int location)
{
    int same = 0;
    for (int i = 0; i < bomb_len; i++)
    {
        if (arr[location + i] == bomb[i])
            same++;
    }
    if (same == bomb_len)
    {
        arr_bottom = arr_bottom +bomb_len;
        return;
    }
    return;
}
 
void check_2(int location)
{
    int same = 0;
    for (int i = 0; i < bomb_len; i++)
    {
        if (answer[location - i] == bomb[bomb_len - 1-i])
            same++;
    }
    if (same == bomb_len)
    {
        answer_top = answer_top - bomb_len;
        return;
    }
 
    return;
}
 
int main()
{
    scanf("%s",arr);
    scanf("%s",bomb);
    arr_top = strlen(arr)-1;
    bomb_len = strlen(bomb);
    while(arr_bottom<arr_top)
    {
        if (arr[++arr_bottom] == bomb[0])
        {
            check_1(arr_bottom);
        }
        if (arr_bottom > arr_top) break;
        answer[++answer_top] = arr[arr_bottom];
        
        if (answer[answer_top] == bomb[bomb_len - 1])
        {
            check_2(answer_top);
        }
    }
 
    if (answer_top == -1)
    {
        printf("FRULA");
        return 0;
    }
 
    for(int i=0;i<=answer_top;i++)
        printf("%c",answer[i]);
    return 0;
}
