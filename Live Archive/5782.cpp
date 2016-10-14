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

int b, c;
int S[502][2502];

int compete(int c1, int c2) {
	int v1 = 0, v2 = 0;
	for(int i = 0; i < b; ++i) {
		if(S[i][c1] < S[i][c2])
			++v1;
		else
			++v2;
	}
	return v1 > v2 ? c1 : c2;
}

int main() {
	int no = 1;
	while(scanf("%d %d", &b, &c) == 2 && (b != 0 || c != 0)) {
		for(int i = 0; i < b; ++i) {
			for(int j = 0; j < c; ++j) {
				int x;
				scanf("%d", &x);
				S[i][x] = j;
			}
		}
		
		int w = 0;
		for(int c2 = 1; c2 < c; ++c2)
			w = compete(w, c2);
		bool k = true;
		for(int c2 = 1; c2 < c; ++c2) if(compete(w, c2) != w)
			k = false;
			
		printf("Case %d: ", no++);
		if(!k)
			printf("No Condorcet winner\n");
		else
			printf("%d\n", w);
	}
	return 0;
}
