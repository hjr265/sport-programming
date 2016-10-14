// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1059
// Air Ports
// mst
// 
// 
// AC (2011-12-04 18:10:54)

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct DSetEl {
	int p, r;
};

void MakeDSet(DSetEl S[], int n) {
	memset(S, 0, sizeof(DSetEl)*n);
	for(int i = 0; i < n; ++i) {
		S[i].p = i;
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
	int u, v, w;
};

bool edgecmp(Edge a, Edge b) {
	return a.w < b.w;
}

DSetEl V[10005];
Edge E[100005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T-- > 0) {
		int N, M, A;
		scanf("%d %d %d", &N, &M, &A);
		MakeDSet(V, N+1);
		for(int i = 0; i < M; ++i) {
			scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
			if(E[i].w >= A)
				--i, --M;
		}
		sort(E, E+M, edgecmp);
		long long Y = 0;
		int Z = N;
		for(int i = 0; i < M && E[i].w < A; ++i) {
			if(DSetFind(V, E[i].u) != DSetFind(V, E[i].v)) {
				DSetUnion(V, E[i].u, E[i].v);
				Y += E[i].w;
				Z -= 1;
			}
		}
		Y += Z*A;
		printf("Case %d: %lld %d\n", no++, Y, Z);
	}
	return 0;
}
