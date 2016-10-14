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

struct Pos {
	int i, j;
};

struct Swap {
	Pos p, q;
};

int c[52];
int a[52][52];
Pos x[2800];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= c[i]; ++j) {
			scanf("%d", &a[i][j]);
			x[a[i][j]].i = i;
			x[a[i][j]].j = j;
		}
	}
	
	vector<Swap> rs;
	for(int i = 1, k = 1; i <= n; ++i) {
		for(int j = 1; j <= c[i]; ++j, ++k) if(a[i][j] != k) {
			Pos p = x[k];
			Pos q;
			q.i = i;
			q.j = j;
			Swap s;
			s.p = p;
			s.q = q;
			rs.push_back(s);
			int y = a[i][j];
			swap(a[p.i][p.j], a[q.i][q.j]);
			x[k] = q;
			x[y] = p;
		}
	}
	
	printf("%d\n", rs.size());
	for(int i = 0; i < rs.size(); ++i)
		printf("%d %d %d %d\n", rs[i].p.i, rs[i].p.j, rs[i].q.i, rs[i].q.j);
	return 0;
}
