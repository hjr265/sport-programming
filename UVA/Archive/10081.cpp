// In the name of Allah, Most Gracious, Most Merciful

// UVA/10081
// Tight Words
// dp
// 
// 
// AC (2012-06-12 12:57:36)

#include <cmath>
#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct State {
	double v;
	bool t;
	
	State() {}
	State(double v_) : v(v_) {}
};

int n, k;
State  D[100+5][10+2][2];

State dp(int n, int i, int j) {
	if(n == 0)
		return State(j);
	if(n < 0)
		return State(0);
	State &r = D[n][i][j];
	if(!r.t) {
		r.v = 0;
		for(int l = 0; l <= k; ++l)
			r.v += dp(n-1, l, i == 11 || j && abs(l-i) <= 1).v;
		r.t = true;
	}
	return r;
}

int main() {
	while(scanf("%d %d", &k, &n) == 2) {
		CLR(D);
		printf("%0.5lf\n", dp(n, 11, 1).v/pow(k+1, n)*100);
	}
	return 0;
}
