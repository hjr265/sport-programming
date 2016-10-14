// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1055
// Going Together
// dfs and similar
// 
// 
// AC (2012-01-09 12:41:42)

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Robot {
	int x, y;
};

int N;
char g[12][12];

struct Triplet {
	Robot r[3];
	bool m[3];

	void move(int dx, int dy) {
		for(int i = 0; i < 3; ++i)
			m[i] = false;
		for(int i = 0; i < 3; ++i) if(!m[i])
			shove(i, dx, dy);
	}
	
	int occupied(int x, int y) {
		for(int i = 0; i < 3; ++i) if(r[i].x == x && r[i].y == y)
			return i;
		return -1;
	}
	
	void shove(int i, int dx, int dy) {
		if(m[i])
			return;
		m[i] = true;
		int j = occupied(r[i].x+dx, r[i].y+dy);
		if(j != -1)
			shove(j, dx, dy);
		if(valid(r[i].x+dx, r[i].y+dy))
			r[i].x += dx, r[i].y += dy;
	}
	
	bool valid(int x, int y) {
		return x >= 0 && y >= 0 && x < N && y < N && g[y][x] != '#' && occupied(x, y) == -1;
	}
	
	bool success() {
		for(int i = 0; i < 3; ++i) if(g[r[i].y][r[i].x] != 'X')
			return false;
		return true;
	}
	
	int hash() {
		int z = 0;
		for(int i = 0; i < 3; ++i)
			z *= 11*11, z += r[i].x*11+r[i].y;
		return z;
	}
};

int d[2000000];
Triplet s;

int bfs() {
	memset(d, -1, sizeof(d));
	d[s.hash()] = 0;
	queue<Triplet> q;
	q.push(s);
	while(!q.empty()) {
		Triplet u = q.front();
		q.pop();
		const int dx[] = {0, 0, 1, -1};
		const int dy[] = {1, -1, 0, 0};
		for(int i = 0; i < 4; ++i) {
			Triplet v = u;
			v.move(dx[i], dy[i]);
			if(d[v.hash()] == -1) {
				d[v.hash()] = d[u.hash()]+1;
				if(v.success())
					return d[v.hash()];
				q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; ++i) {
			scanf("%s", g[i]);
			for(int j = 0; j < N; ++j) if(g[i][j] >= 'A' && g[i][j] <= 'C') {
				s.r[g[i][j]-'A'].x = j;
				s.r[g[i][j]-'A'].y = i;
			}
		}
		int r = bfs();
		printf("Case %d: ", no++);
		if(r == -1)
			printf("trapped\n");
		else
			printf("%d\n", r);
	}
	return 0;
}
