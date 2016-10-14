// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1287
// Where to Run
// dp, probabilities
// 
// 
// AC (2012-05-26 17:10:16)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct State {
	bool t;
	double v;
	
	State() {}
	
	State(double v_) : v(v_) {}
};

int n;
int G[20][20];
State D[(1<<16)+5][20];

State dp(int x, int u) {
	if(x == (1<<n)-1)
		return State(0);
	State &r = D[x][u];
	if(!r.t) {
		r.v = 0;
		double p = 0, c = 0;
		for(int v = 0; v < n; ++v) if(G[u][v] > 0 && (x&(1<<v)) == 0) {
			State t = dp(x|(1<<v), v);
			if(t.v >= 0)
				p += t.v+G[u][v], ++c;
		}
		if(c == 0)
			r.v = -1;
		else if(c > 0)
			r.v = (p+5)/c;
		r.t = true;
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m;
		scanf("%d %d", &n, &m);
		CLR(G);
		while(m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			G[u][v] = G[v][u] = w;
		}
		CLR(D);
		printf("Case %d: %0.7lf\n", no++, max(dp(1, 0).v, 0.0));
	}
	return 0;
}
