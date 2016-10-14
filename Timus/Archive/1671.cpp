// In the name of Allah, Most Gracious, Most Merciful

// Timus/1671
// Anansi's Cobweb
// data structures
// 
// 
// AC ( 22:07:12 15 Oct 2012)

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
	
};

class Dsets {
	int p[100002], r[100002];
	
public:
	Dsets() {
		for(int i = 0; i < 100002; ++i)
			p[i] = i;
		SET(r, 0);
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

struct Edge {
	int u, v;
	bool d;
};

Edge E[100002];
Dsets S;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= M; ++i)
		scanf("%d %d", &E[i].u, &E[i].v);
	int Q;
	scanf("%d", &Q);
	stack<int> X;
	while(Q--) {
		int x;
		scanf("%d", &x);
		X.push(x);
		E[x].d = true;
	}
	
	for(int i = 1; i <= M; ++i) if(!E[i].d) {
		if(S.parent(E[i].u) != S.parent(E[i].v))
			--N;
		S.merge(E[i].u, E[i].v);
	}
	
	vector<int> R;
	while(!X.empty()) {
		R.push_back(N);
		int i = X.top();
		X.pop();
		if(S.parent(E[i].u) != S.parent(E[i].v))
			--N;
		S.merge(E[i].u, E[i].v);
	}
	
	for(int i = R.size()-1; i >= 0; --i) {
		if(i != R.size()-1)
			printf(" ");
		printf("%d", R[i]);
	}
	printf("\n");
	return 0;
}
