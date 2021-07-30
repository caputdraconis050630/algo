#include <iostream>
using namespace std;

int func1(int N)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int func2(int arr[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int k = N - 1; k > i; k--)
        {
            if (arr[i] + arr[k] == 100)
            {
                return 1;
            }
        }
    }
    return 0;
}

int func3(int N)
{
    for (int i = 1; i < N; i++)
    {
        if (i * i == N)
        {
            return 1;
        }
        if (N / i < i)
        {
            return 0;
        }
    }
    return 0;
}

int func4(int N)
{
    int val = 1;
    for (int i = 0; i < N; i++)
    {
        if (val * 2 > N)
        {
            return val;
        }
        else
        {
            val *= 2;
        }
    }
    return 0;
}

int main()
{
    cout << func4(5) << endl;
    cout << func4(97615282) << endl;
    cout << func4(1024) << endl;

    return 0;
}
