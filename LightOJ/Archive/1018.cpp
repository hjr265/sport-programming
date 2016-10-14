// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1018
// Brush (IV)
// dp
// 
// 
// AC (2012-02-03 18:16:24)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct Point {
	int x, y;
	
	Point() {}
	
	bool colin(const Point &a, const Point &b) {
		return (x-a.x)*(a.y-b.y) == (a.x-b.x)*(y-a.y);
	}
};

Point P[18];
int E[18][18];

int m[1<<16+2];

int dp(int N, int x) {
	if(x == (1<<N)-1)
		return 0;
	int &r = m[x];
	if(r == -1) {
		r = 1<<20;
		for(int i = 0; i < N; ++i) if((x&(1<<i)) == 0) {
			for(int j = i; j < N; ++j)
				r = min(r, dp(N, x|E[i][j])+1);
			break;
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d %d", &P[i].x, &P[i].y);
		CLR(E);
		for(int i = 0; i < N; ++i) {
			for(int j = i; j < N; ++j) {
				E[i][j] |= 1<<i;
				if(i == j)
					continue;
				E[i][j] |= 1<<j;
				for(int k = j+1; k < N; ++k) if(P[i].colin(P[j], P[k]))
					E[i][j] |= 1<<k;
			}
		}
		SET(m);
		printf("Case %d: %d\n", no++, dp(N, 0));
	}
	return 0;
}
