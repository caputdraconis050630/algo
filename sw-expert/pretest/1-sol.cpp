#include <iostream>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans;
bool visited[26];
string map[20];
int ch[20][20];

/* 프로토타입 */
int dfs(int x, int y, int r, int c);
void initialize();

int main(){
    int T = 0;
    cin >> T;
    
    int row, col;

    for (int t = 0; t < T; t++) {
        initialize();
        
        cin >> row >> col;
        for (int i = 0; i < row; i++) {
            cin >> map[i];
        }
        
        visited[map[0][0] - 'A'] = true;
        dfs(0, 0, row, col);

        cout << '#' << t+1 << ' ' << ans << "\n";
    }
}


int dfs(int x, int y, int r, int c){
    int tmp_ans = 0;
    for (int k = 0; k < 26; k++)
        if(visited[k])
            tmp_ans ++;
    ans = max(tmp_ans, ans);
    
    int nx, ny;
    for (int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 > nx || nx >= r || 0 > ny || ny >= c)
            continue;
        
        if (visited[map[nx][ny] - 'A'] == false){
            visited[map[nx][ny] - 'A'] = true;
            dfs(nx, ny, r, c);
            visited[map[nx][ny] - 'A'] = false;
        }   
    }
}


void initialize() {
    ans = 0;
    for (int i=0; i<26; i++) {
        visited[i] = false;
    }
    return;
}