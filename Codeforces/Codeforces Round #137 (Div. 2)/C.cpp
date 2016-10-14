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

int N0[10000002], D0[10000002];
int N1[10000002], D1[10000002];
bool S[10000002];
vlong Q[10000002];

vlong binexp(vlong b, vlong p) {
	vlong r = 1;
	for(; p; p /= 2, b *= b) if(p%2)
		r *= b;
	return r;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++N0[x];
	}
	for(int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		++D0[x];
	}
	
	N1[2] += N0[2];
	D1[2] += D0[2];
	for(vlong j = 4; j < 10000002; j += 2) {
		vlong k = j, l = 0;
		while(k%2 == 0)
			k /= 2, ++l;
		Q[2] = max(Q[2], l);
		while(N0[j])
			N1[2] += l, --N0[j], ++N0[k];
		while(D0[j])
			D1[2] += l, --D0[j], ++D0[k];
	}
	SET(S, 0);
	for(vlong i = 3; i < 100; i += 2) if(!S[i]) {
		N1[i] += N0[i];
		D1[i] += D0[i];
		for(vlong j = i*i; j < 10000002; j += 2*i) {
			S[j] = true;
			vlong k = j, l = 0;
			while(k%i == 0)
				k /= i, ++l;
			Q[i] = max(Q[i], l);
			while(N0[j])
				N1[i] += l, --N0[j], ++N0[k];
			while(D0[j])
				D1[i] += l, --D0[j], ++D0[k];
		}
	}
	
	for(int i = 0; i < 10000002; ++i)
		N0[i] = N1[i]-min(N1[i], D1[i]), D0[i] = D1[i]-min(N1[i], D1[i]);
	
	vector<vlong> N3, D3;
	for(int i = 0; i < 10000002; ++i) if(N0[i] > 0) {
		while(N0[i] >= Q[i])
			N0[i] -= Q[i], N3.push_back(binexp(i, Q[i]));
		if(N0[i] > 0)
			N3.push_back(binexp(i, N0[i]));
	}
	for(int i = 0; i < 10000002; ++i) if(D0[i] > 0) {
		while(D0[i] >= Q[i])
			D0[i] -= Q[i], D3.push_back(binexp(i, Q[i]));
		if(D0[i] > 0)
			D3.push_back(binexp(i, D0[i]));
	}
	if(N3.size() == 0)
		N3.push_back(1);
	if(D3.size() == 0)
		D3.push_back(1);
	
	printf("%d %d\n", N3.size(), D3.size());
	for(int i = 0; i < N3.size(); ++i) {
		if(i)
			printf(" ");
		printf("%I64d", N3[i]);
	}
	printf("\n");
	for(int i = 0; i < D3.size(); ++i) {
		if(i)
			printf(" ");
		printf("%I64d", D3[i]);
	}
	printf("\n");
	
	return 0;
}
