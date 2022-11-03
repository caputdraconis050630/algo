#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int A,B;

bool visited[MAX];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    //테케
    while(T--){
        cin >> A >> B;
        
        //초기화
        for(int i = 0; i<10000; i++)
            visited[i] = false;
            
            
        queue<pair<int, string>> q;
        
        q.push({A, ""});
        visited[A] = true;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            int curNum = cur.first;
            
            //해당 상태라면
            if(curNum == B){
                cout << cur.second << '\n';
                break;
            }
            
            //4가지 경우 다 탐색해봄 (방문했다면 이미 최단경로 존재하므로 탐색 x)
            int next;
            //D
            next = (curNum * 2)%MAX;
            if(!visited[next]){
                q.push({next, cur.second + "D"});
                visited[next] = true;
            }
            //S
            next = (curNum - 1) < 0 ? 9999 : curNum - 1;
            if(!visited[next]){
                q.push({next, cur.second + "S"});
                visited[next] = true;
            }
            //L
            next = (curNum%1000)*10 + (curNum/1000);
            if(!visited[next]){
                q.push({next, cur.second + "L"});
                visited[next] = true;
            }
            //R
            next = (curNum/10) + (1000*(curNum%10));
            if(!visited[next]){
                q.push({next, cur.second + "R"});
                visited[next] = true;
            }
        }
        
    }
    return 0;
}