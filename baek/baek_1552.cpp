/**
 * BOJ 1552 도미노
 * https://www.acmicpc.net/problem/1552
 * N개를 먼저 고르고, 그 안에 사이클을 이루는 그룹의 개수를 구해야함.
 */
#include <bits/stdc++.h>
using namespace std;

int N; // 1 <= N <= 6 자연수
int score[6][6]; // 도미노 뒤에 적혀있는 점수
int cnt = 0;
char r_used[6];
char c_used[6];
int maxAns = INT_MIN;
int minAns = INT_MAX;
deque<int> picked;
deque<int> cycle;
set<string> used;

void init() { 
	// 사용된 행, 열을 저장하는 used 배열을 초기화하는 함수입니다.
	for (int i = 0; i<N; i++){
		r_used[i] = '0';
		c_used[i] = '0';
	}
}

bool checkIsCycle() {
	if (cycle.front() / 10 != cycle.back() % 10)
		return false;
	for (int i=0; i<cycle.size() - 1; i++) {
		if (cycle[i] % 10 != cycle[i + 1] / 10)
			return false;
	}
	return true;
}

string numToString(int num) {
	string result = "00";
	if (num >= 10)
		result[0] = num / 10;
	result[1] = num % 10;
	return result;
}

string make_string() {
	string result = "";
	int arr[cycle.size()];
	for (int i=0; i<cycle.size(); i++) {
		arr[i] = cycle[i];
	}
	sort(arr, arr + cycle.size());
	for (int i=0; i<cycle.size(); i++) {
		result += numToString(arr[i]);
		result += " ";
	}
	return result;
}

void makeCycle() {
	// 지금 현재 cycle에 들어가있는 마지막 값에 맞는 값을 넣어본다.
	if (checkIsCycle()) {
		if (used.find(make_string()) == used.end()) {
			cnt += 1;
			used.insert(make_string());
		}
	}
	if (cycle.size() == N)
		return;
	int key = cycle.back() % 10;
	for (int i=0; i<N; i++) {
		deque<int>::iterator itp = find(picked.begin(), picked.end(), key * 10 + i);
		deque<int>::iterator itc = find(cycle.begin(), cycle.end(), key * 10 + i);
		if (itp == picked.end() || itc != cycle.end())
			continue;
		cycle.push_back(key * 10 + i);
		makeCycle();
		cycle.pop_back();
	}
}

int getGroupCnt() {
	used.clear();
	cnt = 0;
	for(int i=0; i<N; i++) {
		cycle.clear();
		cycle.push_back(picked[i]);
		makeCycle();
	}
	return cnt;
}

void checkScore() {
	int groupCnt  = getGroupCnt(); // 현재 선택한 도미노 들중에서 그룹의 개수 구하기
	int scoreNow = 1;
	for(int i=0; i<picked.size(); i++){
		int present = picked[i];
		scoreNow *= score[present/10][present%10];
	}
	// 그룹의 개수가 짝수가 되면 -1 곱하기
	if (groupCnt % 2 == 0)
		scoreNow *= -1;
	// 최대, 최소 점수 저장
	maxAns < scoreNow ? maxAns = scoreNow : maxAns = maxAns;
	minAns > scoreNow ? minAns = scoreNow : minAns = minAns;
}

void pick() {
	// 도미노를 N개 고르는 함수입니다.
	if (picked.size() == N)
	{
		checkScore();
		return;
	}
	// 새로운 도미노 set에 넣기(여기서 더이상 넣는게 가능한지 아닌지 구분하여, 재귀 끊어야함)
	for(int i=0; i<N; i++) {
		for (int j=0; j<N; j++){
			int key = i * 10 + j;
			// 예외처리
			if (r_used[i] != '0' || c_used[j] != '0')
				continue;
			deque<int>::iterator it = find(picked.begin(), picked.end(), key);
			if (it != picked.end())
				continue;
			r_used[i] = '1';
			c_used[j] = '1';
			picked.push_back(key);
			pick();
			r_used[i] = '0';
			c_used[j] = '0';
			picked.pop_back();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();

	// Input
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++){
			if (tmp[j] >= '0' && tmp[j] <= '9')
				score[i][j] = tmp[j] - '0';
			else
				score[i][j] = -1 * (tmp[j] - 'A' + 1);
		}
	}

	// CALCULATE
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++) {
			int key = i * 10 + j;
			r_used[i] = '1';
			c_used[j] = '1';
			picked.clear();
			picked.push_back(key);
			pick();

			r_used[i] = '0';
			c_used[j] = '0';
		}	
	}

	// OUTPUT
	cout << minAns << "\n" << maxAns << "\n";
	return 0;
}