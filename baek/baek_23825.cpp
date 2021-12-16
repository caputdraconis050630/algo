#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>N>>M;

    int ans = min(N, M) / 2;
    cout<<ans<<"\n";
}