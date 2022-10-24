/**
 * BOJ 1052 물병
 * https://www.acmicpc.net/problem/1052
 */

#include <bits/stdc++.h>
using namespace std;

int N, K;
int result = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;


	if (N <= K) {
		// N이 K보다 작거나 같으면, 이미 성공이니 물병을 더 구매할 필요가 없다.
		cout << 0 << "\n";
		return 0;
	}
	while (true)
	{
		int cnt = 0; 
		int tmp = N; // N의 기존값을 저장하기 위한 임시 변수

		while (tmp)
		{
			if (tmp % 2) // 나머지 값이 존재할 때
				cnt++;
			tmp /= 2;
		}
		if (cnt <= K)
			break;
		N++;
		result++;
	}
	cout << result << "\n";
	return 0;
}