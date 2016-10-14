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

set<vlong> S;
vector<vlong> V;

int main() {
	for(vlong i = 1; i*i < 1000000005; ++i)
		S.insert(i*i);
	vlong x = 0;
	for(vlong t = 1; x < 1000000005; ++t) {
		x += t;
		if(S.count(x+1))
			V.push_back(x);
	}
	
	int no = 1;
	int a, b;
	while(scanf("%d %d", &a, &b) == 2 && (a != 0 || b != 0)) {
		int r = 0;
		for(int i = 0; i < V.size(); ++i) if(a < V[i]+1 && b > V[i]+1)
			++r;
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
