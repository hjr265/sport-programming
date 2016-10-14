// In the name of Allah, Most Gracious, Most Merciful

// Codeforces/Codeforces Round #139 (Div. 2)/C
// Barcode
// dp
// http://codeforces.com/contest/225/problem/C
// 
// AC (00:57:33)

#include <cstring>
#include <algorithm>
#include <iostream>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

typedef long long vlong;

int n, m, x, y;
char G[1002][1002];
int P[1002];
vlong M[1002][1002][2];

vlong dp(int i, int cw, int cc) {
	if(i == m) {
		if(cw < x || cw > y)
			return 1LL<<60;		
		return 0;
	}
	if(cw > y)
		return 1LL<<60;
	
	vlong &r = M[i][cw][cc];
	if(r == -1) {
		r = 1LL<<60;
		
		if(cc == 0) {
			r = min(r, dp(i+1, cw+1, 0)+n-P[i]);
			if(cw >= x)
				r = min(r, dp(i+1, 1, 1)+P[i]);
		} else {
			r = min(r, dp(i+1, cw+1, 1)+P[i]);
			if(cw >= x)
				r = min(r, dp(i+1, 1, 0)+n-P[i]);
		}
	}
	return r;
}

int main() {
	cin >> n >> m >> x >> y;
	for(int i = 0; i < n; ++i)
		cin >> G[i];
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) if(G[i][j] == '#')
			++P[j];
	}
	
	SET(M, -1);
	cout << min(dp(0, 0, 0), dp(0, 0, 1)) << endl;
	return 0;
}
