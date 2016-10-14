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

int IC[102], FC[102];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		SET(IC, 0);
		SET(FC, 0);
		
		int N, M;
		scanf("%d %d", &N, &M);
		while(N--) {
			int C, L;
			scanf("%d %d", &C, &L);
			IC[L] += C;
		}
		while(M--) {
			int C, L;
			scanf("%d %d", &C, &L);
			FC[L] += C;
		}
		
		int R = 0;
		for(int i = 0; i < 102; ++i) if(FC[i] > IC[i])
			R += FC[i]-IC[i];
		
		printf("%d\n", R);
	}
	return 0;
}
