// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1171
// Knights in Chessboard (II)
// graph matchings
// 
// 
// AC (2012-02-28 16:49:00)

#include <cstdio>
#include <cstring>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

bool G[202][202];
int G2[202][202];
vector<int> E[40002];
int L[40002], R[40002];
bool c[40002];

bool bpm(int u) {
	if(c[u])
		return false;
	c[u] = true;
	for(int i = 0, l = E[u].size(); i < l; ++i) {
		int v = E[u][i];
		if(R[v] == -1 || bpm(R[v])) {
			L[u] = v;
			R[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n, K;
		scanf("%d %d %d", &m, &n, &K);
		CLR(G);
		while(K--) {
			int x, y;
			scanf("%d %d", &x, &y);
			G[x-1][y-1] = true;
		}
		int b = 0, w = 0;
		for(int ui = 0; ui < m; ++ui) {
			for(int uj = 0; uj < n; ++uj) if(!G[ui][uj]) {
				if((ui+uj)%2 == 0)
					G2[ui][uj] = ++w;
				else
					G2[ui][uj] = ++b;
			}
		}
		for(int u = 0; u < 40002; ++u)
			E[u].clear();
		for(int ui = 0; ui < m; ++ui) {
			for(int uj = 0; uj < n; ++uj) if((ui+uj)%2 == 0 && !G[ui][uj]) {
				const int x[][2] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};
				for(int l = 0; l < 8; ++l) {
					int vi = ui+x[l][0], vj = uj+x[l][1];
					if(vi >= 0 && vi < m && vj >= 0 && vj < n && !G[vi][vj]) {
						E[G2[ui][uj]].push_back(G2[vi][vj]);
					}
				}
			}
		}
		SET(L);
		SET(R);
		bool d;
		do {
			d = true;
			CLR(c);
			for(int u = 1; u <= w; ++u) if(L[u] == -1 && bpm(u))
				d = false;
		} while(!d);
		int r = 0;
		for(int u = 1; u <= w; ++u) if(L[u] != -1)
			++r;
		printf("Case %d: %d\n", no++, w+b-r);
	}
	return 0;
}
