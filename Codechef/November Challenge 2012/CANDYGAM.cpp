// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);

enum {
	
};

vlong A[52][52];
vlong S[52][52];
vlong D[52][52][52][52][2];

vlong dp(int i, int j, int k, int l, int p) {
	if(i > k || j > l)
		return 0;
	vlong &r = D[i][j][k][l][p];
	if(r == -1) {
		r = 0;
		if(p == 0) {
			vlong q = min(min(S[i][l]-S[i-1][l]-S[i][j-1]+S[i-1][j-1], S[k][l]-S[k-1][l]-S[k][j-1]+S[k-1][j-1]), min(S[k][j]-S[i-1][j]-S[k][j-1]+S[i-1][j-1], S[k][l]-S[i-1][l]-S[k][l-1]+S[i-1][l-1]));
			if(S[i][l]-S[i-1][l]-S[i][j-1]+S[i-1][j-1] == q)
				r = dp(i+1, j, k, l, !p);
			else if(S[k][l]-S[k-1][l]-S[k][j-1]+S[k-1][j-1] == q)
				r = dp(i, j, k-1, l, !p);
			else if(S[k][j]-S[i-1][j]-S[k][j-1]+S[i-1][j-1] == q)
				r = dp(i, j+1, k, l, !p);
			else if(S[k][l]-S[i-1][l]-S[k][l-1]+S[i-1][l-1] == q)
				r = dp(i, j, k, l-1, !p);
		} else {
			r = max(r, dp(i+1, j, k, l, !p)+S[i][l]-S[i-1][l]-S[i][j-1]+S[i-1][j-1]);
			r = max(r, dp(i, j, k-1, l, !p)+S[k][l]-S[k-1][l]-S[k][j-1]+S[k-1][j-1]);
			r = max(r, dp(i, j+1, k, l, !p)+S[k][j]-S[i-1][j]-S[k][j-1]+S[i-1][j-1]);
			r = max(r, dp(i, j, k, l-1, !p)+S[k][l]-S[i-1][l]-S[k][l-1]+S[i-1][l-1]);
		}
	}
	return r;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		SET(S, 0);
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= M; ++j) {
				cin >> A[i][j];
				S[i][j] = S[i-1][j]+S[i][j-1]-S[i-1][j-1]+A[i][j];
			}
		}
		
		SET(D, -1);
		vlong R = dp(1, 1, N, M, 0);
		if(2*R == S[N][M])
			R *= 2;
		else if(2*R < S[N][M])
			R = S[N][M]-R;
		cout << R << "\n";
	}
	return 0;
}
