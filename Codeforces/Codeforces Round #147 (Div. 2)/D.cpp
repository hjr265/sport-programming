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

template<int N>
class Dsets {
	int p[N], r[N];
	
public:
	Dsets() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
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

vector<int> E[100005];
vector<pair<int, int> > ZV;
vector<int> ZEC[100005];
vector<pair<int, int> > ZE;
Dsets<100005> DS;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n-1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	ZV.push_back(pair<int, int>(-1, -1));
	for(int u = 1, k = 1; u <= n; ++u) {
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i];
			if(u > v)
				continue;
			ZEC[u].push_back(ZV.size());
			ZEC[v].push_back(ZV.size());
			ZV.push_back(pair<int, int>(u, v));
		}
	}
	
	for(int u = 1; u <= n; ++u) {
		for(int i = 1; i < ZEC[u].size(); ++i) {
			int xu = ZEC[u][0], xv = ZEC[u][i];
			if(DS.parent(xu) != DS.parent(xv)) {
				DS.merge(xu, xv);
				ZE.push_back(pair<int, int>(xu, xv));
			}
		}
	}
	
	printf("%d\n", ZV.size()-1);
	for(int i = 1; i < ZV.size(); ++i)
		printf("2 %d %d\n", ZV[i].first, ZV[i].second);
	for(int i = 0; i < ZE.size(); ++i)
		printf("%d %d\n", ZE[i].first, ZE[i].second);
	return 0;
}
