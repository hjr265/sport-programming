// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1321
// Sending Packets
// shortest paths, probabilities
// 
// 
// AC (2012-01-29 22:33:03)

#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long vlong;

struct Edge {
	int v;
	double w;
	
	Edge(int v_, double w_) : v(v_), w(w_) {}
};

vlong N, M, S, K;
vector<Edge> E[102];
double D[102];

double dijkstra() {
	for(int u = 0; u < 102; ++u)
		D[u] = 0;
	set<pair<double, int> > q;
	D[0] = 1;
	q.insert(pair<double, int>(0, 0));
	while(!q.empty()) {
		int u = q.begin()->second;
		if(u == N-1)
			return D[u];
		q.erase(q.begin());
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i].v;
			double w = E[u][i].w;
			if(D[u]*w > D[v]) {
				D[v] = D[u]*w;
				q.insert(pair<double, int>(1-D[u]*w, v));
			}
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld %lld %lld", &N, &M, &S, &K);
		for(int u = 0; u < 102; ++u)
			E[u].clear();
		while(M--) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			E[u].push_back(Edge(v, (double)p/100));
			E[v].push_back(Edge(u, (double)p/100));
		}
		printf("Case %d: %0.4lf\n", no++, (double)(2*K*S)/dijkstra());
	}
	return 0;
}
