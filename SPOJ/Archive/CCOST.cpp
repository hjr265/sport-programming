// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/CCOST
// Calculate The Cost
// data structures, trees
// 
// 
// AC (2012-10-19 12:02:40)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

template<class T, int N>
class Fwtree {
	T t[N+2];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(t, 0);
	}
	
	void add(int i, T x) {
		++i;
		while(i < N+2)
			t[i] += x, i += i&-i;
	}
	
	T sum(int i) {
		++i;
		T r = 0;
		while(i)
			r += t[i], i -= i&-i;
		return r;
	}
};

struct Point {
	int t;
	int x, y;
	int v;
	
	bool operator<(const Point &r) const {
		if(x < r.x)
			return true;
		if(x == r.x && t == 0)
			return true;
		return false;
	}
};

struct Rect {
	int x1, y1, x2, y2;
	int v;
};

vector<Point> Ts;
vector<Rect> Rs;
vector<Point> Ps;
Fwtree<int, 600005> FT;
vector<int> ys;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		Ts.clear();
		Ps.clear();
		ys.clear();
		while(n--) {
			Point p;
			p.t = 0;
			scanf("%d %d %d", &p.x, &p.y, &p.v);
			Ts.push_back(p);
			Ps.push_back(p);
			ys.push_back(p.y);
		}
		int r;
		scanf("%d", &r);
		Rs.clear();
		for(int i = 0; r--; ++i) {
			Rect t;
			t.v = 0;
			scanf("%d %d %d %d", &t.x1, &t.y1, &t.x2, &t.y2);
			Rs.push_back(t);
			Point p[4];
			p[0].x = t.x2;
			p[0].y = t.y2;
			p[1].x = t.x1-1;
			p[1].y = t.y2;
			p[2].x = t.x2;
			p[2].y = t.y1-1;
			p[3].x = t.x1-1;
			p[3].y = t.y1-1;
			for(int j = 0; j < 4; ++j) {
				p[j].t = j+1;
				p[j].v = i;
				Ps.push_back(p[j]);
				ys.push_back(p[j].y);
			}
		}
		sort(ALL(Ps));
		sort(ALL(ys));
		
		FT.clear();
		for(int i = 0; i < Ps.size(); ++i) {
			Ps[i].y = upper_bound(ALL(ys), Ps[i].y)-ys.begin();
			switch(Ps[i].t) {
			case 0:
				FT.add(Ps[i].y, Ps[i].v);
				break;
			case 1:
				Rs[Ps[i].v].v += FT.sum(Ps[i].y);
				break;
			case 2:
				Rs[Ps[i].v].v -= FT.sum(Ps[i].y);
				break;
			case 3:
				Rs[Ps[i].v].v -= FT.sum(Ps[i].y);
				break;
			case 4:
				Rs[Ps[i].v].v += FT.sum(Ps[i].y);
				break;
			}
		}
		
		for(int i = 0; i < Rs.size(); ++i)
			printf("%d\n", Rs[i].v);
	}
	return 0;
}
