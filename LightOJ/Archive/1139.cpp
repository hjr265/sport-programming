// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1139
// 8 Puzzle
// dfs and similar
// 
// 
// AC (2012-06-07 01:47:08)

#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int move(int u, char d) {
	int g[3][3];
	int y, x;
	for(int i = 2; i >= 0; --i) {
		for(int j = 2; j >= 0; --j, u /= 10) {
			g[i][j] = u%10;
			if(g[i][j] == 0)
				y = i, x = j;
		}
	}
	switch(d) {
	case 'u':
		if(y-1 < 0)
			return -1;
		swap(g[y][x], g[y-1][x]);
		break;
	case 'r':
		if(x+1 >= 3)
			return -1;
		swap(g[y][x], g[y][x+1]);
		break;
	case 'd':
		if(y+1 >= 3)
			return -1;
		swap(g[y][x], g[y+1][x]);
		break;
	case 'l':
		if(x-1 < 0)
			return -1;
		swap(g[y][x], g[y][x-1]);
		break;
	}
	int v = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j)
			v *= 10, v += g[i][j];
	}
	return v;
}

map<int, int> d;

void init() {
	queue<int> q;
	map<int, bool> c;
	d[123456780] = 0;
	c[123456780] = true;
	q.push(123456780);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		char x[] = {'u', 'r', 'd', 'l'};
		for(int i = 0; i < 4; ++i) {
			int v = move(u, x[i]);
			if(v != -1 && c[v] == false) {
				d[v] = d[u]+1;
				c[v] = true;
				q.push(v);
			}
		}
	}
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int s = 0;
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {	
				s *= 10;
				int x;
				scanf("%d", &x);
				s += x;
			}
		}
		printf("Case %d: ", no++);
		int r = d[s];
		if(r == 0 && s != 123456780)
			printf("impossible\n");
		else
			printf("%d\n", d[s]);
	}
	return 0;
}
