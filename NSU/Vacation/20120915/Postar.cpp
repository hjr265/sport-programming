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

struct State {
	pair<int, int> u;
	int l, h, d;
	
	State(pair<int, int> u_, int l_, int h_, int d_) : u(u_), l(l_), h(h_), d(d_) {}
	
	bool operator<(const State &r) const {
		return false;
	}
};

int N;
char G[52][52];
int H[52][52];
pair<int, int> P;
vector<pair<int, int> > Ks;
int D[52][52];
vector<int> Hs;

bool bfs(int l, int h) {
	SET(D, -1);
	queue<pair<int, int> > q;
	D[P.first][P.second] = 0;
	q.push(P);
	int c = Ks.size();
	while(!q.empty() && c) {
		pair<int, int> u = q.front();
		q.pop();
		if(H[u.first][u.second] < l || H[u.first][u.second] > h)
			continue;
		if(G[u.first][u.second] == 'K')
			--c;
		
		int x[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
		for(int i = 0; i < 8; ++i) {
			pair<int, int> v(u.first+x[i][0], u.second+x[i][1]);
			if(v.first >= 0 && v.first < N && v.second >= 0 && v.second < N && D[v.first][v.second] == -1) {
				D[v.first][v.second] = D[u.first][u.second]+1;
				q.push(v);
			}
		}
	}
	return c == 0;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%s", G[i]);
		for(int j = 0; j < N; ++j) switch(G[i][j]) {
		case 'P':
			P = pair<int, int>(i, j);
			break;
		case 'K':
			Ks.push_back(pair<int, int>(i, j));
			break;
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d", &H[i][j]);
			Hs.push_back(H[i][j]);
		}
	}
	sort(ALL(Hs));
	Hs.resize(unique(ALL(Hs))-Hs.begin());
	
	int z = 1<<28;
	for(int i = 0; i < Hs.size(); ++i) {
		if(!bfs(Hs[i], Hs[Hs.size()-1]))
			continue;
		int jl = 0, jh = Hs.size(), j = 1<<28;
		while(jl < jh) {
			if((jl+jh)/2 == j)
				break;
			j = (jl+jh)/2;
			if(bfs(Hs[i], Hs[j]))
				jh = j;
			else
				jl = j;
		}
		for(int jj = max(0, j-3); jj < Hs.size() && jj < j+3; ++jj) if(bfs(Hs[i], Hs[jj])) {
			z = min(z, Hs[jj]-Hs[i]);
			break;
		}
	}
	
	printf("%d\n", z);
	return 0;
}
