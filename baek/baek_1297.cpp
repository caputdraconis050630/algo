#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int D, H, W;

    cin >> D >> H >> W;

    double k = D / sqrt(H * H + W * W);

    cout << int(H * k) << " " << int(W * k) << "\n";
}