// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1099
// Not the Best
// shortest paths
// 
// 
// AC (2012-03-01 11:59:34)

#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

enum {
	Nmax = 5000+2
};

struct Edge {
    int v, w;

    Edge(int v_, int w_) : v(v_), w(w_) {}
};

int N;
vector<Edge> E[Nmax];
int F[Nmax];
int D[Nmax];

int dijkstra() {
	CLR(F);
	SET(D);
	set<pair<int, int> > q;
	D[1] = 0;
	q.insert(pair<int, int>(0, 1));
	while(!q.empty()) {
		int u = q.begin()->second, c = q.begin()->first;
		q.erase(q.begin());
		if(F[u] >= 2)
            continue;
        if(F[u] == 1 && u == N)
            return c;
		++F[u];
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i].v, w = E[u][i].w;
            q.insert(pair<int, int>(c+w, v));
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
	    int R;
	    scanf("%d %d", &N, &R);
	    for(int i = 0; i < Nmax; ++i)
            E[i].clear();
	    while(R--) {
	        int u, v, w;
	        scanf("%d %d %d", &u, &v, &w);
            E[u].push_back(Edge(v, w));
            E[v].push_back(Edge(u, w));
	    }
	    printf("Case %d: %d\n", no++, dijkstra());
	}
	return 0;
}
