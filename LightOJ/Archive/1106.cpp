// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1106
// Gone Fishing
// dp
// 
// 
// AC (2012-05-28 02:20:25)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

struct State {
	bool t;
	int f, p, s;
	
	State() {}
	
	State(int f_, int p_, int s_) : f(f_), p(p_), s(s_) {}
};

int n, h;
int f[30], d[30], t[30];
State M[30][200];

State dp(int i, int j) {
	if(i == n || j >= h)
		return State(0, 0, 0);
	State &r = M[i][j];
	if(!r.t) {
		int x = f[i];
		r = State(dp(i+1, j+t[i]).f, t[i], 0);
		for(int k = j+1; k <= h; ++k) {
			State n = dp(i+1, k+t[i]);
			if(n.f+x > r.f || n.f+x == r.f && k-j > r.s)
				r = State(n.f+x, k-j+t[i], k-j);
			if(f[i] >= d[i]*(k-j))
				x += f[i]-d[i]*(k-j);
		}
		r.t = true;
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &h);
		h *= 60/5;
		for(int i = 0; i < n; ++i)
			scanf("%d", &f[i]);
		for(int i = 0; i < n; ++i)
			scanf("%d", &d[i]);
		for(int i = 0; i < n-1; ++i)
			scanf("%d", &t[i]);
		t[n-1] = 0;
		printf("Case %d:\n", no++);
		CLR(M);
		State r = dp(0, 0);
		State u = r;
		int i = 0, j = 0;
		while(i < n) {
			printf("%d", u.s*5);
			j += u.p;
			u = dp(i+1, j);
			++i;
			if(i != n)
				printf(", ");
		}
		printf("\nNumber of fish expected: %d\n", r.f);
	}
	return 0;
}
