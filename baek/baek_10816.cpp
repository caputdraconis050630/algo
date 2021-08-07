#include <bits/stdc++.h>
using namespace std;

const int MX = 20000001;
int arr[MX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin>>N;
    for(int i =0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr[tmp+10000000]++;
    }

    cin>>M;
    for(int i = 0;i<M;i++){
        int tmp;
        cin>>tmp;
        cout<<arr[tmp+10000000]<<" ";
    }

}