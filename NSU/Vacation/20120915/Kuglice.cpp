// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);

enum {
	Nmax = 300000+5
};

template<int n>
class Dsets {
	int p[n], r[n];
	
public:
	Dsets() {
		clear();
	}
	
	void clear() {
		SET(r, 0);
		for(int i = 0; i < n; ++i)
			p[i] = i;
	}
	
	int parent(int i) {
		if(p[i] != i)
			p[i] = parent(p[i]);
		return p[i];
	}
	
	void merge(int i, int j) {
		i = parent(i);
		j = parent(j);
		if(r[i] > r[j])
			p[j] = i;
		else
			p[i] = j;
		if(r[i] == r[j])
			++r[j];
	}
};

struct Query {
	int c, X, r;
};

int N, Q;
int E[Nmax];
int Ez[Nmax];
vector<Query> Qs;

char C[Nmax];
int L[Nmax];

int dfs(int u) {
	if(C[u] == 'g')
		return 1<<28;
	if(!L[u]) {
		C[u] = 'g';
		if(E[u] == 0)
			L[u] = u;
		else
			L[u] = dfs(E[u]);
		C[u] = 'b';
	}
	return L[u];
}

Dsets<Nmax> DS;

int main() {
	scanf("%d", &N);
	for(int u = 1; u <= N; ++u)
		scanf("%d", &E[u]);
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i) {
		Query q;
		scanf("%d %d", &q.c, &q.X);
		Qs.push_back(q);
		
		if(q.c == 2) {
			Ez[q.X] = E[q.X];
			E[q.X] = 0;
		}
	}
	
	for(int u = 1; u <= N; ++u) if(E[u])
		DS.merge(u, E[u]);
	for(int u = 1; u <= N; ++u)
		L[u] = dfs(u);
	
	for(int i = Qs.size()-1; i >= 0; --i) {
		switch(Qs[i].c) {
		case 1:
			Qs[i].r = L[DS.parent(Qs[i].X)];
			break;
		case 2:
			E[Qs[i].X] = Ez[Qs[i].X];
			if(L[DS.parent(E[Qs[i].X])] == Qs[i].X) {
				DS.merge(Qs[i].X, E[Qs[i].X]);
				L[DS.parent(E[Qs[i].X])] = 1<<28;
			} else {
				int Lx = L[DS.parent(E[Qs[i].X])];
				DS.merge(Qs[i].X, E[Qs[i].X]);
				L[DS.parent(Qs[i].X)] = Lx;
			}
			break;
		}
	}
	
	for(int i = 0; i < Qs.size(); ++i) if(Qs[i].c == 1) {
		if(Qs[i].r == 1<<28)
			printf("CIKLUS\n");
		else
			printf("%d\n", Qs[i].r);
	}
	return 0;
}
