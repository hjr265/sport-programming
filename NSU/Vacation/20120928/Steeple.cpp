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

struct Line {
	int X1, Y1, X2, Y2;
	
	bool intersects(const Line &r) const {
		return (r.X1 >= X1 && r.X1 <= X2 || r.X1 >= X2 && r.X1 <= X1) && (Y1 >= r.Y1 && Y1 <= r.Y2 || Y1 >= r.Y2 && Y1 <= r.Y1);
	}
};

vector<Line> X;
vector<int> E[255];
int L[255], R[255];
bool c[255];

bool bpm(int u) {
	if(c[u])
		return false;
	c[u] = true;
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(R[v] == -1 || bpm(R[v])) {
			L[u] = v;
			R[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		Line x;
		cin >> x.X1 >> x.Y1 >> x.X2 >> x.Y2;
		X.push_back(x);
	}
	
	for(int i = 0; i < X.size(); ++i) if(X[i].Y1 == X[i].Y2) {
		for(int j = 0; j < X.size(); ++j) if(i != j && X[j].X1 == X[j].X2 && X[i].intersects(X[j])) {
			E[i].push_back(j);
			E[j].push_back(i);
		}
	}
	
	SET(L, -1);
	SET(R, -1);
	bool d;
	do {
		d = true;
		SET(c, 0);
		for(int u = 0; u < X.size(); ++u) if(L[u] == -1 && bpm(u))
			d = false;
	} while(!d);
	
	int r = 0;
	for(int i = 0; i < X.size(); ++i) if(L[i] != -1)
		++r;
	
	cout << X.size()-r/2 << endl;
	return 0;
}
