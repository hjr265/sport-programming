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

char S1[50005], S2[100005];
int P[100005];

void calcprefix() {
	P[1] = 0;
	for(int q = 2, k = 0; S2[q]; ++q) {
		while(k > 0 && S2[k+1] != S2[q])
			k = P[k];
		if(S2[k+1] == S2[q])
			++k;
		P[q] = k;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s %s", S1, S2+1);
		S2[0] = '_';
		strcat(S2, "$");
		strcat(S2, S1);
		calcprefix();
		int r = 0, u = strlen(S2)-1;
		while(u != 0)
			++r, u = P[u];
		printf("%d\n", r);
	}
	return 0;
}
