// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1403
// Air Raid
// graph matchings
// 
// 
// AC (2012-02-27 20:51:02)

#include <cstdio>
#include <cstring>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> E[2005];
int L[2005], R[2005], c[2005];

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
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < 2005; ++i)
			E[i].clear();
		while(m--) {
			int u, v;
			scanf("%d %d", &u, &v);
			E[u].push_back(v+1002);
		}
		SET(L);
		SET(R);
		bool d;
		do {
			d = true;
			CLR(c);
			for(int u = 1; u <= n; ++u) if(L[u] == -1 && bpm(u))
				d = false;
		} while(!d);
		int r = 0;
		for(int u = 1; u <= n; ++u) if(L[u] != -1)
			++r;
		printf("Case %d: %d\n", no++, n-r);
	}
	return 0;
}
