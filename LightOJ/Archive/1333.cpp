// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1333
// Grid Coloring
// combinatorics, number theory
// 
// 
// AC (2012-05-04 20:19:49)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

const vlong mod = 1000000000LL;

struct Block {
	int x, y;
	
	Block(int x_, int y_) : x(x_), y(y_) {}
	
	bool operator<(const Block &r) const {
		return y < r.y || y == r.y && x < r.x;
	}
};

vlong modpow(vlong b, vlong p, vlong m) {
	vlong r = 1;
	for(; p; p >>= 1, b *= b) {
		b %= m;
		if(p&1)
			r = (r*b)%m;
	}
	return r;
}

vector<Block> G;
bool H[1000005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int M, N, K, B;
		scanf("%d %d %d %d", &M, &N, &K, &B);
		G.clear();
		CLR(H);
		while(B--) {
			int x, y;
			scanf("%d %d", &x, &y);
			G.push_back(Block(x, y));
			if(!H[y]) {
				H[y] = true;
				--N;
			}
		}
		sort(ALL(G));
		vlong r = modpow(modpow(K-1, M-1, mod)*K, N, mod);
		for(int l = 0; l < G.size(); ) {
			vlong x = 1, y = G[l].y;
			for(; l < G.size() && G[l].y == y; ++l) {
				if(G[l].x-x > 0)
					r = (((r*modpow(K-1, G[l].x-x-1, mod))%mod)*K)%mod;
				x = G[l].x+1;
			}
			if(M+1-x > 0)
				r = (((r*modpow(K-1, M-x, mod))%mod)*K)%mod;
		}
		printf("Case %d: %lld\n", no++, (r%mod+mod)%mod);
	}
	return 0;
}
