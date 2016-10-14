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

bool af[102];

struct Movie {
	int i;
	int d;
	vector<int> bs;
	bool bsf[102];
	bool bsuf[102];
	
	int f[3];
	
	int r;
};

vector<Movie> Ms;

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int m, k;
	scanf("%d %d", &m, &k);
	for(int i = 0; i < k; ++i) {
		int a;
		scanf("%d", &a);
		af[a] = true;
	}
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		char s[15];
		scanf("%s", s);
		Movie v;
		v.i = i;
		scanf("%d", &v.d);
		SET(v.f, 0);
		SET(v.bsf, 0);
		SET(v.bsuf, 0);
		for(int j = 0; j < v.d; ++j) {
			int b;
			scanf("%d", &b);
			if(b) {
				v.bs.push_back(b);
				if(af[b]) {
					++v.f[0];
					v.bsf[b] = true;
				} else {
					v.bsuf[b] = true;
				}
			}
		}
		int rfs = 0;
		for(int l = 1; l <= m; ++l) if(af[l] && !v.bsf[l])
			++rfs;
		v.f[2] = v.f[0]+min(rfs, (int)(v.d-v.bs.size()));
		
		int rufs = 0;
		for(int l = 1; l <= m; ++l) if(!af[l] && !v.bsuf[l])
			++rufs;
		
		v.f[1] = v.f[0]+max((int)(v.d-v.bs.size())-rufs, 0);
		
		Ms.push_back(v);
	}
	
	for(int i = 0; i < n; ++i)
		printf("%d %d %d %d\n", i, Ms[i].f[0], Ms[i].f[1], Ms[i].f[2]);
	
	for(int i = 0; i < n; ++i) {
		int x1 = 0, x2 = 0, x3 = 0, x4;
		
		bool canFav = false, sureFav = false, canUnfav = false, sureUnfav = false;
		
		for(int j = 0; j < n; ++j) if(i != j) {
			if(Ms[i].f[1] >= Ms[j].f[2])
				++x1;
			if(Ms[i].f[1] >= Ms[j].f[1])
				++x2;
			if(Ms[i].f[2] < Ms[j].f[1])
				++x3;
			if(Ms[i].f[2] < Ms[j].f[1])
				++x4;
		}
		
		if(x1 == n-1)
			canFav = sureFav = true;
		if(x2)
			canFav = true;
		if(!sureFav && x3)
			canUnfav = true;
		if(x4 == n)
			sureUnfav = true;
		
		if(sureFav)
			printf("0\n");
		else if(sureUnfav)
			printf("1\n");
		else if(canFav || canUnfav)
			printf("2\n");
	}
	return 0;
}
