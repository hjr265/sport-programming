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

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

vlong lcm(vlong a, vlong b) {
	return (a/gcd(a, b))*b;
}

int next(int n, int k, int i) {
	int p = i%k,
		s = n/k,
		sf = (n+k-1)/k,
		lp = n-s*k,
		j = i/k;
	return p < lp ? sf*p+sf-j-1 : sf*lp+s*(p-lp)+s-j-1;
	
}

int main() {
	int n, k;
	for(int n = 1; n <= 800; ++n) for(int k = 1; k <= 800; ++k) {
	//while(scanf("%d %d", &n, &k) == 2 && (n != 0 || k != 0)) {
		if(n <= k) {
			printf("1\n");
			continue;
		}
		vlong r = 1;
		for(int i = 0; i < n; ++i) {
			int j = next(n, k, i), d = 1;
			while(j != i)
				j = next(n, k, j), ++d;
			//if(i == 0 || i == n/2-1 || i == n/2 || i == n/2+1 || i == n-1)
			//	cout << d << " ";
			r = lcm(r, d);
		}
		//cout << endl << r0 << " " << r << endl;
		printf("%lld\n", r);
	}
	return 0;
}
