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
const vlong MOD = 1000000007LL;

enum {
	
};

int depth(int N, int x[], int i) {
	if(i == N-1)
		return 0;
	if(i == -2)
		return 1<<28;
	int t = x[i];
	x[i] = -1;
	return depth(N, x, t-1)+1;
}

// 2, 12, 104, 1180, 16560

vlong modpow(vlong b, vlong p, vlong m) {
	vlong r = 1;
	for(; p; p /= 2) {
		b %= m;
		if(p%2)
			r = (r*b)%m;
		b *= b;
	}
	return r;
}

int main() {
	/*for(int N = 10; N <= 10; ++N) {
		int NN = 1;
		for(int i = 0; i < N; ++i)
			NN *= N;
	
		int Z[N+2];
		SET(Z, 0);
		for(int i = 0; i < NN; ++i) {
			int x[N];
			for(int j = N-1, t = i; j >= 0; --j, t /= N)
				x[j] = (t%N)+1;
		
			int t = depth(N, x, 0);
			if(t <= N)
				++Z[0];
		}
		
		printf("%d: %d\n", N, Z[0]);
	
		
		vlong n;
		//scanf("%lld", &n);
		n = N;
		printf("%lld: ", n);
	
		vlong z = 0;
		for(vlong i = 1, x = 1, y = n-2; i < n; ++i, --y) {
			z = (((modpow(n, n-i, MOD)*x)%MOD)+z)%MOD;
			//printf("%lld=%lld*%lld ", ((modpow(n, n-i, MOD)*x)%MOD), ((modpow(n, n-i, MOD))%MOD), x);
			if(i < n-1)
				x = (x*y)%MOD;
		}
		printf("%lld\n", z);
	}
	return 0;*/
	
	/*
	for(vlong n = 2; n <= 10; ++n) {
		vlong z = 0;
		for(vlong i = 1, x = 1, y = n-2; i < n; ++i, --y) {
			z = ((((modpow(n, n-i, MOD)%MOD)*x)%MOD)+z)%MOD;
			x = (x*y)%MOD;
		}
		printf("%lld\n", z%MOD);
	}
	return 0;*/
	
	vlong n;
	cin >> n;
	
	vlong z = 0;
	for(vlong i = 1, x = 1, y = n-2; i < n; ++i, --y) {
		z = ((((modpow(n, n-i, MOD)%MOD)*x)%MOD)+z)%MOD;
		x = (x*y)%MOD;
	}
	cout << (z%MOD) << endl;
	return 0;
}
