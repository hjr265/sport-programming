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

vector<int> P[2];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n/2; ++i)
		P[0].push_back(i);
	reverse(ALL(P[0]));
	for(int i = n/2+1; i <= n; ++i)
		P[1].push_back(i);
	reverse(ALL(P[1]));
	
	printf("%d\n", (n+1)/2);
	for(int i = 0; i < (n+1)/2; ++i) {
		printf("%d", P[0].size());
		for(int j = 0; j < P[0].size(); ++j)
			printf(" %d", P[0][j]);
		printf("\n");
		swap(P[0][i], P[1][i]);
	}
	return 0;
}
