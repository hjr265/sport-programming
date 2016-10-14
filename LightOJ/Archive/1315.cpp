// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1315
// Game of Hyper Knights
// games
// 
// 
// AC (2012-01-06 10:03:57)

#include <cstdio>
#include <cstring>
#include <set>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int G[502][502];
const int M[][2] = {{-2, 1}, {-3, -1}, {-2, -1}, {-1, -2}, {-1, -3}, {1, -2}};

int grundy(int x, int y) {
	if(x < 0 || y < 0)
		return -1;
	if(x > 500 || y > 500)
		return -1;
	if(G[y][x] != -1)
		return G[y][x];
	set<int> s;
	for(int i = 0; i < 6; ++i)
		s.insert(grundy(x+M[i][0], y+M[i][1]));
	int r = 0;
	while(s.count(r) != 0)
		++r;
	G[y][x] = r;
	return r;
}

void init() {
	SET(G);
	for(int y = 0; y < 502; ++y) {
		for(int x = 0; x < 502; ++x)
			G[y][x] = grundy(x, y);
	}
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int r = 0;
		while(n--) {
			int x, y;
			scanf("%d %d", &x, &y);
			r ^= G[y][x];
		}
		printf("Case %d: %s\n", no++, r == 0 ? "Bob" : "Alice");
	}
	return 0;
}
