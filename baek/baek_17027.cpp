#include <bits/stdc++.h>
using namespace std;

int N;
int a, b, g;

void swap_score(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int score[4] = {0, 0, 0, 0};

	cin >> N;
	while (N--)
	{
		cin >> a >> b >> g;
		swap_score(&score[a], &score[b]);
		score[g] += 1;
	}
	cout << max(score[1], max(score[2], score[3])) << "\n";
}