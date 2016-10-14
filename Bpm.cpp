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
class Bpm {
	vector<int> E[N];
	bool C[N];
	
	bool match(int u) {
		if(C[u])
			return false;
		C[u] = true;
		for(int i = 0, l = E[u].size(); i < l; ++i) {
			int v = E[u][i];
			if(R[v] == -1 || match(R[v])) {
				L[u] = v;
				R[v] = u;
				return true;
			}
		}
		return false;
	}
	
public:
	int L[N], R[N];
	
	Bpm() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			E[i].clear();
	}
	
	void addedge(int u, int v) {
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	int maxmatch() {
		SET(L, -1);
		SET(R, -1);
		bool d;
		do {
			d = true;
			SET(C, 0);
			for(int u = 0; u < N; ++u) if(L[u] == -1 && match(u))
				d = false;
		} while(!d);
		int r = 0;
		for(int u = 0; u < N; ++u) if(L[u] != -1)
			++r;
		return r/2;
	}
};

int main() {
	
	return 0;
}
