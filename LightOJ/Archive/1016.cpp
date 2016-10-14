// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1016
// Brush (II)
// greedy
// 
// 
// AC (2011-09-14 13:01:53)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+(n)

using namespace std;

struct Pt {
	int x, y;
	
	bool operator<(const Pt &b) const {
		return y < b.y;
	}
};

Pt p[50005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, w;
		scanf("%d %d", &N, &w);
		for(int i = 0; i < N; ++i)
			scanf("%d %d", &p[i].x, &p[i].y);
		sort(SLC(p, N));
		int z = 1, x = w;
		for(int i = 1; i < N; ++i) {
			if(p[i].y - p[i-1].y > x)
				++z, x = w;
			else
				x -= p[i].y-p[i-1].y;
		}
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
