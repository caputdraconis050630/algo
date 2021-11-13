#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int L, A, B, C, D;

    cin >> L >> A >> B >> C >> D;

    int kor = ceil(double(A) / C);
    int math = ceil(double(B) / D);

    int tmp = max(kor, math);

    cout << L - tmp << "\n";
}