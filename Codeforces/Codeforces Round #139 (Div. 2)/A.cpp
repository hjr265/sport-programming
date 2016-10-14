// In the name of Allah, Most Gracious, Most Merciful

// Codeforces/Codeforces Round #139 (Div. 2)/A
// Dice Tower
// implementation
// http://codeforces.com/contest/225/problem/A
// 
// AC (01:43:55)

#include <algorithm>
#include <iostream>

#define SLC(c, n) c, c+(n)

using namespace std;

int n;
int x;
int D[102][6];
	
int main() {
	cin >> n;
	cin >> D[0][4];
	for(int i = 0; i < n; ++i)
		cin >> D[i][0] >> D[i][1];
	
	for(int i = 0; i < n; ++i) {
		D[i][2] = 7-D[i][0];
		D[i][3] = 7-D[i][1];
		if(i > 0) {
			int v[6] = {1, 2, 3, 4, 5, 6};
			for(int j = 0; j < 6; ++j) if(D[i][j])
				v[D[i][j]-1] = 1<<28;
			v[D[i-1][5]-1] = 1<<28;
			sort(SLC(v, 6));
			D[i][4] = v[0];
		}
		D[i][5] = 7-D[i][4];
	}
	
	bool k = true;
	for(int i = 0; i < n-1; ++i) if(D[i][4] != D[i+1][4] || D[i][5] != D[i+1][5]) {
		k = false;
		break;
	}
	
	cout << (k ? "YES" : "NO") << endl;
	return 0;
}
