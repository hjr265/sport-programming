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

char X[102];
int R[1002];

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
		scanf("%s", X);
		SET(R, 0);
		R[0] = X[0]-'0';
		int Rm = R[0];
		for(int i = 0, j = 1; X[i]; ++j) {
			if(abs(R[j-1]-(X[i]-'0')) > 1)
				R[j] = X[i]-'0' > R[j-1] ? R[j-1]+1 : R[j-1]-1;
			else
				R[j] = X[i++]-'0';
			Rm = max(R[j], Rm);
		}
		
		for(int i = Rm; i >= 1; --i) {
			for(int j = 1; R[j]; ++j)
				printf(i <= R[j] ? "+" : "*");
			printf("\n");
		}
	}
	return 0;
}
