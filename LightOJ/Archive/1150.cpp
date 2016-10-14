// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1150
// Ghosts!
// binary search, graph matchings
// 
// 
// AC (2012-02-28 12:29:52)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct Edge {
	int v, w;
	
	Edge(int v_, int w_) : v(v_), w(w_) {
	}
};

int n;
char G[27][27];
int H[27][27];
int d[27*27];
vector<Edge> E[52];

void bfs(pair<int, int> s) {
	SET(d);
	queue<pair<int, int> > q;
	d[s.first*26+s.second] = 0;
	q.push(s);
	while(!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		const int x[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
		for(int i = 0; i < 4; ++i) {
			pair<int, int> v(u.first+x[i][0], u.second+x[i][1]);
			if(v.first >= 0 && v.first < n && v.second >= 0 && v.second < n && G[v.first][v.second] != '#' && d[v.first*26+v.second] == -1) {
				d[v.first*26+v.second] = d[u.first*26+u.second]+1;
				if(G[v.first][v.second] == 'H')
					E[H[s.first][s.second]].push_back(Edge(H[v.first][v.second], 2*d[v.first*26+v.second]+2));
				q.push(v);
			}
		}
	}
}

int L[2005], R[2005], c[2005];

bool bpmdfs(int u, int t) {
	if(c[u])
		return false;
	c[u] = true;
	for(int i = 0, l = E[u].size(); i < l; ++i) if(E[u][i].w <= t) {
		int v = E[u][i].v;
		if(R[v] == -1 || bpmdfs(R[v], t)) {
			L[u] = v;
			R[v] = u;
			return true;
		}
	}
	return false;
}

bool bpm(int g, int w, int t) {
	SET(L);
	SET(R);
	bool d;
	do {
		d = true;
		CLR(c);
		for(int u = 0; u < g; ++u) if(L[u] == -1 && bpmdfs(u, t))
			d = false;
	} while(!d);
	for(int u = 0; u < g; ++u) if(L[u] != -1)
		--w;
	return w == 0;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%s", G[i]);
		for(int u = 0; u < 52; ++u)
			E[u].clear();
		int g = 0, w = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) switch(G[i][j]) {
				case 'G':
					H[i][j] = g++;
					break;
				case 'H':
					H[i][j] = w++;
					break;
			}	
		}
		for(int i = 0, l = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) if(G[i][j] == 'G')
				bfs(pair<int, int>(i, j));
		}
		int l = 0, h = 700, m;
		while(l < h) {
			m = (l+h)/2;
			if(bpm(g, w, m))
				h = m-1;
			else
				l = m+1;
		}
		printf("Case %d: ", no++);
		bool p = false;
		for(int t = max(m-4, 0); t < m+4; ++t) if(bpm(g, w, t)) {
			p = true;
			printf("%d\n", t);
			break;
		}
		if(!p)
			printf("Vuter Dol Kupokat\n");
	}
	return 0;
}
