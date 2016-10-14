// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1041
// Road Construction
// mst
// 
// 
// AC (2011-08-03 19:27:44)

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct DSetEl {
	int p, r;
};

void MakeDSet(DSetEl S[], int n) {
	for(int i = 0; i < n; ++i) {
		S[i].p = i;
		S[i].r = 0;
	}
}

int DSetFind(DSetEl S[], int a) {
	if(S[a].p != a) {
		S[a].p = DSetFind(S, S[a].p);
	}
	return S[a].p;
}

void DSetUnion(DSetEl S[], int a, int b) {
	int u = DSetFind(S, a), v = DSetFind(S, b);
	if(S[u].r > S[v].r) {
		S[v].p = u;
	} else {
		S[u].p = v;
	}
	if(S[u].r == S[v].r) {
		S[v].r += 1;
	}
}

struct Edge {
	int u, v, c;
};

bool edgecmp(Edge a, Edge b) {
	return a.c < b.c;
}

DSetEl S[105];
map<string, int> V;
vector<Edge> E;

int main() {
	int T, no = 1;
	cin >> T;
	while(T-- > 0) {
		MakeDSet(S, 105);
		V.clear();
		E.clear();
		int m;
		cin >> m;
		int x = 1;
		while(m-- > 0) {
			string u, v;
			int c;
			cin >> u >> v >> c;
			if(V[u] == 0) {
				V[u] = x++;
			}
			if(V[v] == 0) {
				V[v] = x++;
			}
			Edge e;
			e.u = V[u];
			e.v = V[v];
			e.c = c;
			E.push_back(e);
		}
		sort(E.begin(), E.end(), edgecmp);
		long long z = 0;
		for(int i = 0, l = E.size(); i < l; ++i) {
			if(DSetFind(S, E[i].u) != DSetFind(S, E[i].v)) {
				DSetUnion(S, E[i].u, E[i].v);
				z += E[i].c;
			}
		}
		int q = DSetFind(S, 1);
		for(int i = 1; i < x; ++i) {
			if(DSetFind(S, i) != q) {
				z = -1;
				break;
			}
		}
		cout << "Case " << no++ << ": ";
		if(z == -1)
			cout << "Impossible" << endl;
		else
			cout  << z << endl;
	}
	return 0;
}

