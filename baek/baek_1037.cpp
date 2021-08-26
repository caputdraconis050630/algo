#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cout<<v.front()*v.back()<<"\n";
    
}