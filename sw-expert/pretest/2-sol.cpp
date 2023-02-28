#include <iostream>
#include <vector>

using namespace std;
int n, x, y, ret;
vector<int> v;
string s;
int result[100004];

/* 프로토타입 */
void recursive(int idx, int size);

int main() {
	int T;
	cin>>T;
	
	for(int t = 0; t < T; t++)
	{
        string s = "";
        int cnt = 0;
        ret = 0;
        cin >> n >> x >> y;
        v.push_back(x);
        v.push_back(y);

        if(n < 10 * x + y){
            cout << "#" << t + 1 << " " << "-1\n";
            continue;
        }

        s = to_string(n);
        int size = s.size();
        int num = 0;

        vector<int> v;
        recursive(0, size);
        cout << ret << "\n";
	}
	return 0;
}

void recursive(int idx, int size){
    s = "";
    if(idx >= size){
        for(int i = 0; i < size; i++){
            s += to_string(result[i]);
        }
        cout << s << "\n";
        int lim = stoi(s);
        if (lim <= n) {
            ret = max(ret, lim);
        }
        return;
    }
    for(int i = 0; i < 2; i++){
        result[idx] = v[i];
        recursive(idx + 1, size);
    }
}