#include <bits/stdc++.h>
using namespace std;

int arr[64][64];
 
void bf(int y, int x, int count) {
    int comp_value = arr[y][x];
    bool flag = false;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (arr[y + i][x + j] != comp_value) {
                cout << '(';
                bf(y, x, count / 2);
                bf(y, x + count / 2, count / 2);
                bf(y + count / 2, x, count / 2);
                bf(y + count / 2, x + count / 2, count / 2);
                cout << ')';
                return;
            }
        }
    }
    cout << comp_value;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int k = 0; k < input.length(); k++)
            arr[i][k] = input[k] - '0';
    }
    bf(0, 0, n);
    return 0;
}