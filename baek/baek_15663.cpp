#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print();
void recur(int);

int N, M;
int in[10], out[10];
bool visited[10];

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> in[i];
    sort(in, in + N);

    recur(0);

    return 0;
}

void recur(int t)
{
    if (t == M)
    {
        // M 개의 숫자로 이루어진 수열 완성
        print();
        return;
    }
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && tmp != in[i])
        {
            out[t] = i;
            tmp = in[i];
            visited[i] = true;
            recur(t + 1);
            visited[i] = false;
        }
    }
}

void print()
{
    for (int i = 0; i < M; i++)
    {
        cout << in[out[i]] << " ";
    }
    cout << "\n";
}