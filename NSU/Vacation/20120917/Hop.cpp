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

int N, K;
vlong V[250005];
vlong S[250005];

vlong M[250005];

vlong dp(int i) {
	if(i == 0)
		return 0;
	
	vlong &r = M[i];
	if(r == -1) {
		r = 0;
		
		for(int j = i-K; j < i-1; ++j)
			r = max(r, dp(j)+V[i]+V[i+1]+S[i-1]-S[j+1]);
	}
	return r;
}

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; ++i)
		scanf("%lld", &V[i]);
	
	for(int i = 1; i <= N; ++i)
		S[i] = S[i-1]+max(0LL, V[i]);
	
	SET(M, -1);
	vlong r = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = i+1; j <= N && j < i+K; ++j)
			r = max(r, dp(i)+S[j]-S[i+1]);
	}
	
	printf("%lld\n", r);
	return 0;
}
