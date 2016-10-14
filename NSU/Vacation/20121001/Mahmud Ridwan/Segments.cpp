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

int F[1000005];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> P;
	while(m--) {
		int x;
		scanf("%d", &x);
		P.push_back(x);
	}
	vector<int> Sa, Sb;
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		Sa.push_back(a);
		Sb.push_back(b);
	}
	
	sort(ALL(Sa));
	sort(ALL(Sb));
	
	for(int i = 0; i < P.size(); ++i)
		printf("%d\n", (upper_bound(ALL(Sa), P[i])-Sa.begin())-(lower_bound(ALL(Sb), P[i])-Sb.begin()));
	return 0;
}
