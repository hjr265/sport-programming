// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1123
// Trail Maintenance
// mst
// 
// 
// AC (2011-08-27 13:45:34)

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Dset {
	struct El {
		int p, r;
	};
	
	El *e_;
	
	Dset(int n) : e_(new El[n]) {
		memset(e_, 0, sizeof(e_));
		for(int i = 0; i < n; ++i)
			e_[i].p = i;
	}
	
	~Dset() {
		delete[] e_;
	}
	
	int Find(int a) {
		if(e_[a].p != a)
			e_[a].p = Find(e_[a].p);
		return e_[a].p;
	}
	
	void Union(int a, int b) {
		int u = Find(a), v = Find(b);
		if(e_[u].r > e_[v].r)
			e_[v].p = u;
		else
			e_[u].p = v;
		if(e_[u].r == e_[v].r)
			e_[v].r += 1;
	}
};

struct Edge {
	int u, v, w;
	bool operator<(const Edge &b) const {
		return w < b.w;
	}
};

Edge e[2][6005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case %d:\n", no++);
		int N, W;
		scanf("%d %d", &N, &W);
		for(int i = 0, j = 0; W--; ++j, j %= 2) {
			scanf("%d %d %d", &e[j][i].u, &e[j][i].v, &e[j][i].w);
			sort(e[j], e[j] + i + 1);
			Dset s(N + 1);
			int z = 0, x = N - 1;
			int l = i;
			i = 0;
			for(int k = 0; k <= l; ++k) if(s.Find(e[j][k].u) != s.Find(e[j][k].v)) {
				z += e[j][k].w;
				s.Union(e[j][k].u, e[j][k].v);
				--x;
				e[(j + 1) % 2][i].u = e[j][k].u;
				e[(j + 1) % 2][i].v = e[j][k].v;
				e[(j + 1) % 2][i++].w = e[j][k].w;
			}
			if(x == 0)
				printf("%d\n", z);
			else
				printf("-1\n");
		}
	}
	return 0;
}
