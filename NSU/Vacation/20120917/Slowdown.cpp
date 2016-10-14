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
	
};

template<class T, int n>
class Fwtree {
	T v[n+5];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(v, 0);
	}
	
	void add(int i, T x) {
		++i;
		while(i < n+5)
			v[i] += x, i += i & -i;
	}
	
	T sum(int i) {
		++i;
		T r = 0;
		while(i > 0)
			r += v[i], i -= i & -i;
		return r;
	}
};

Fwtree<int, 100005> FT;
vector<int> E[100005];
int P[100005],
	C[100005],
	R[100005];
bool M[100005];

void dfs(int u) {
	if(M[u])
		return;
	M[u] = true;
	
	FT.add(C[u], 1);
	
	for(int i = 0; i < E[u].size(); ++i)
		dfs(E[u][i]);
	
	R[C[u]] = FT.sum(C[u])-1;
	
	FT.add(C[u], -1);
}

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i) {
		int A, B;
		scanf("%d %d", &A, &B);
		E[A].push_back(B);
		E[B].push_back(A);
	}
	for(int i = 1; i <= N; ++i) {
		scanf("%d", &P[i]);
		C[P[i]] = i;
	}
	
	SET(M, 0);
	dfs(1);
	
	for(int i = 1; i <= N; ++i)
		printf("%d\n", R[i]);
	return 0;
}
