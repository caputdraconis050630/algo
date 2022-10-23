#include <bits/stdc++.h>
using namespace std;

int r, c; // 1 <= 호수의 row, column <= 1500
char lake[1501][1501];
char route[1501][1501];
char tmp;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pair<int, int> > waters;
vector<pair<int, int> > swans;
int ans = 0;

void init() {
	// 호수에서의 백조 경로를 그리기 위한 배열을 초기화하는 함수
	for (int i = 0; i < r; i++){
		for (int j=0; j<c; j++){
			route[i][j] = '0';
		}
	}
}

bool moveSwan() {
	init();
	pair<int, int> movingSwan = swans[0];
	pair<int, int> dest = swans[1];

	queue<pair<int, int> > swanRoute;
	swanRoute.push(movingSwan);
	while(!swanRoute.empty()) {
		pair<int, int> present = swanRoute.front();
		route[present.first][present.second] = '1'; // 이미 지나온 경로를 저장
		swanRoute.pop();
		for (int i = 0; i < 4; i++) {
			int qx = present.first + dx[i];
			int qy = present.second + dy[i];
			if (qx < 0 || qx >= r || qy < 0 || qy >= c){
				continue;
			} else if(route[qx][qy] == '1') {
				continue;
			}
			else if(lake[qx][qy] == 'X'){
				continue;
			}
			else {
				if (qx == dest.first && qy == dest.second)
					return true;
				swanRoute.push(make_pair(qx, qy));
			}
		}
	}
	return false;
}

void meltIce() {
	vector<pair<int, int> > tmpWaters;
	// 물 근처 얼음 녹이기
	for(int q = 0; q < waters.size(); q++) {
		pair<int, int> w = waters[q];
		int x = w.first;
		int y = w.second;
		for (int i=0;i<4;i++){
			int qx = x + dx[i];
			int qy = y + dy[i];
			if (qx >= 0 && qx < r && qy >= 0 && qy < c && lake[qx][qy] == 'X')
			{
				lake[x + dx[i]][y + dy[i]] = '.';
				tmpWaters.push_back(make_pair(x + dx[i], y + dy[i]));
			}
		}
	}
	// waters 에 다시 채우기
	waters.clear();
	waters = tmpWaters;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++) {
			cin >> tmp;
			if (tmp == '.')
				waters.push_back(make_pair(i, j));
			else if (tmp == 'L')
			{
				swans.push_back(make_pair(i, j));
				waters.push_back(make_pair(i, j));
				lake[i][j] = '.';
			}
			lake[i][j] = tmp;
		}
	}

	while (true) {
		if(moveSwan()) // 백조 움직이기 시도
			break;
		meltIce(); // 얼음 녹임
		ans += 1;
	}
	cout << ans << endl;
}