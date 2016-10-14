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

struct Tree {
	int x, y;
	bool v;
};

struct Path {
	int x, y;
};

struct Event {
	int x, y, t, i;
	
	Event(int x_, int y_, int t_, int i_) : x(x_), y(y_), t(t_), i(i_) {}
	
	bool operator<(const Event &r) const {
		if(x == r.x)
			return y < r.y;
		return x < r.x;
	}
};

vector<Tree> Ts;
vector<Path> Ps;
vector<Event> Es;

int main() {
	int F;
	scanf("%d", &F);
	while(F--) {
		int T, P;
		scanf("%d %d", &T, &P);
		Ts.clear();
		for(int i = 0; i < T; ++i) {
			Tree t;
			scanf("%d %d", &t.x, &t.y);
			t.v = false;
			Ts.push_back(t);
			Es.push_back(Event(t.x, t.y, 0, i));
		}
		Ps.clear();
		for(int i = 0; i < P; ++i) {
			Path p;
			char x[3];
			int v;
			scanf("%s %d", x, &v);
			switch(x[0]) {
			case 'H':
				p.x = -1000002;
				p.y = v;
				break;
			case 'V':
				p.x = v;
				p.y = -1000002;
				break;
			}
			Ps.push_back(p);
			Es.push_back(Event(p.x, p.y, 1, i));
		}
		
		for(int i = 0; i < 4; ++i) {
			sort(ALL(Es));
			for(int j = 0; j < Es.size(); ++j) {
				printf("%d %d\n", Es[j].t, Es[j].i);
				if(Es[j].t == 1) {
					
				}
			}
			for(int j = 0; j < Es.size(); ++j)
				Es[j].y *= -1, swap(Es[j].x, Es[j].y);
		}
		
		int r = 0;
		for(int i = 0; i < Ts.size(); ++i) if(Ts[i].v)
			++r;
		printf("%d %s\n", r, (r*100)/Ts.size() >= 60 ? "PASSED" : "FAILED");
	}
	return 0;
}
