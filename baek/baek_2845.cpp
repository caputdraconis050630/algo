#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int L, P;
    cin>>L>>P;

    int k = L*P;

    for(int i=0;i<5;i++){
        int tmp;
        cin>>tmp;
        cout<<tmp-k<<" ";
    }
}