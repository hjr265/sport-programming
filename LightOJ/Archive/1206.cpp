// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1206
// Scheduling Taxi Cabs
// graph matchings
// 
// 
// AC (2012-05-10 17:22:29)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct Node {
	int t, a, b, c, d;
	
	Node(int t_, int a_, int b_, int c_, int d_) : t(t_), a(a_), b(b_), c(c_), d(d_) {}
};

vector<Node> V;
vector<int> E[502];

int L[502];
int R[502];
bool c[502];

bool bpm(int u) {
	if(c[u])
		return false;
	c[u] = true;
	for(int i = 0; i < E[u].size(); ++i) {
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
		int M;
		scanf("%d", &M);
		V.clear();
		while(M--) {
			int hh, mm, a, b, c, d;
			scanf("%d:%d %d %d %d %d", &hh, &mm, &a, &b, &c, &d);
			V.push_back(Node(hh*60+mm, a, b, c, d));
		}
		for(int i = 0; i < 502; ++i)
			E[i].clear();
		for(int i = 0; i < V.size(); ++i) {
			for(int j = i+1; j < V.size(); ++j) if(V[i].t+abs(V[i].a-V[i].c)+abs(V[i].b-V[i].d)+abs(V[i].c-V[j].a)+abs(V[i].d-V[j].b) < V[j].t)
				E[i].push_back(j);
		}
		SET(L);
		SET(R);
		bool d;
		do {
			d = true;
			CLR(c);
			for(int u = 0; u < V.size(); ++u) if(L[u] == -1 && bpm(u))
				d = false;
		} while(!d);
		int r = 0;
		for(int u = 0; u < V.size(); ++u) if(L[u] != -1)
			++r;
		printf("Case %d: %d\n", no++, V.size()-r);
	}
	return 0;
}
