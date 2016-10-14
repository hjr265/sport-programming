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

int n;
int L[100005];
vector<int> E[100005];
bool S[100005];

bool dfs(int u) {
	int t = 0;
	for(int i = 0; i < E[u].size(); ++i) if(dfs(E[u][i]))
		++t;
	return S[u] = (t == 0);
}

int main() {
	scanf("%d", &n);
	for(int j = 1; j <= n; ++j) {
		char d[10];
		int i;
		scanf("%s", d);
		switch(d[0]) {
		case 'd':
			L[j] = -1;
			break;
		case 'c':
			scanf("%d", &i);
			L[j] = i;
			E[i].push_back(j);
			break;
		}
	}
	for(int i = 1; i <= n; ++i) if(L[i] == -1)
		dfs(i);
	int r = 0;
	for(int i = 1; i <= n; ++i) if(S[i])
		++r;
	printf("%d\n", r);
	bool f = false;
	for(int i = 1; i <= n; ++i) if(S[i]) {
		if(f)
			printf(" ");
		printf("%d", i);
		f = true;
	}
	printf("\n");
	return 0;
}
