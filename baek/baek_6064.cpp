#include "bits/stdc++.h"
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--) {
    	bool flag = false;
    	int m, n, x, y;
		cin>>m>>n>>x>>y;
		x--;
		y--;
        // m * n 까지 하는 이유는 종말의 해가 m과 n의 최소공배수인데
        // 최소공배수는 m * n 보다 크거나 같다.
        // 그래서 그냥 m * n을 해줬다.
		for(int k = x; k < (m * n); k += m) {
			if(k % n == y) {
				flag = true;
				cout<<k + 1<<"\n"; // 처음에 -1을 해줬으므로
				break;
			}
		}
		if(!flag) cout<<"-1\n"; 
	}
	return 0;
}