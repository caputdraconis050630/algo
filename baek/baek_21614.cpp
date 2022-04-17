#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int dig;
	int direction, temp_dir;
	string dir[3] = {"", "left ", "right "};
	cin>>dig;
	while (dig != 99999)
	{
		// print direction
		direction = (dig / 10000) + (dig / 1000);
		if (direction % 2 == 1)
			temp_dir = 1;
		else if (direction != 0 && direction % 2 == 0)
			temp_dir = 2;
		else if (direction == 0)
			temp_dir = temp_dir; // keep previous direction
		cout << dir[temp_dir];

		// the number of steps
		cout << dig % 1000 <<"\n";
		cin >> dig;
	}
}