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

int M, N;
int A[20004];

int S0[1003], S1[1003];

int main() {
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	
	int R = 0;
	for(int K = 1; 2*K <= N; ++K) {
		++S0[A[K-1]], --S1[A[K-1]], ++S1[A[2*K-2]], ++S1[A[2*K-1]];
		
		int F = 0;
		for(int i = M; i >= 1; --i) {
			F = F+S1[i+1]-S0[i];
			
			if(F < 0)
				break;
		}
		
		if(F >= 0)
			R = max(R, K);
	}
	
	printf("%d\n", R);
	return 0;
}
