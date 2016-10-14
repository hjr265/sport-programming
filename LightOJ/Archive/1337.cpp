// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1337
// The Crystal Maze
// dfs and similar
// 
// 
// AC (2011-10-31 22:52:59)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

struct Dset {
	int p[505*505], r[505*505];
	
	Dset() {
		for(int i = 0; i < 505*505; ++i)
			p[i] = i;
		CLR(r);
	}
	
	int parent(int a) {
		if(p[a] != a)
			p[a] = parent(p[a]);
		return p[a];
	}
	
	void merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(r[a] > r[b])
			p[b] = a;
		else
			p[a] = b;
		if(r[a] == r[b])
			++r[b];
	}
};

char g[505][505];
int c[505*505];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int M, N, Q;
		scanf("%d %d %d\n", &M, &N, &Q);
		memset(g, 0, sizeof(g));
		for(int i = 1; i <= M; ++i)
			gets(g[i]+1);
		Dset s;
		for(int i = 1; i <= M; ++i) {
			for(int j = 1; j <= N; ++j) if(g[i][j] != '#') {
				const int t[][2] = {
					{0, -1},
					{0, 1},
					{-1, 0},
					{1, 0}
				};
				for(int k = 0; k < 4; ++k) if(g[i-t[k][0]][j-t[k][1]] == '.' || g[i-t[k][0]][j-t[k][1]] == 'C')
					s.merge(i*502+j, (i-t[k][0])*502+(j-t[k][1]));
			}
		}
		memset(c, 0, sizeof(c));
		for(int i = 1; i <= M; ++i) {
			for(int j = 1; j <= N; ++j) if(g[i][j] == 'C')
				++c[s.parent(i*502+j)];
		}
		printf("Case %d:\n", no++);
		while(Q--) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", c[s.parent(x*502+y)]);
		}
	}
	return 0;
}
