// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5970
// An Average Game
// trees
// 
// 
// AC (2012-09-11 05:34:57)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef long long vlong;

class Fwtree {
	vlong t[10004];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(t, 0);
	}
	
	void add(int i, vlong v) {
		++i;
		while(i < 10004)
			t[i] += v, i += i & -i;
	}
	
	vlong sum(int i) {
		++i;
		vlong r = 0;
		while(i > 0)
			r += t[i], i -= i & -i;
		return r;
	}
};

struct Query {
	int i, j, k;
	double r;
	
	bool operator<(const Query &r) const {
		return i < r.i;
	}
};

int X[10004], Y[10004], Z[10004], L[10004];
bool W[10004];
vector<Query> Q;
Fwtree FT, FTU;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &X[i]);
		
		for(int i = 0; i < n; ++i)
			Y[i] = X[i];
		sort(SLC(Y, n));
		for(int i = 0; i < n; ++i)
			Z[i] = lower_bound(SLC(Y, n), X[i])-Y;
		
		SET(Y, -1);
		for(int i = n-1; i >= 0; --i) {
			L[i] = Y[Z[i]];
			Y[Z[i]] = i;
		}
		
		FT.clear();
		FTU.clear();
		SET(W, 0);
		for(int i = 0; i < n; ++i) if(!W[Z[i]]) {
			FT.add(i, X[i]);
			FTU.add(i, 1);
			W[Z[i]] = true;
		}
				
		int q;
		scanf("%d", &q);
		Q.clear();
		for(int k = 0; k < q; ++k) {
			Query q;
			scanf("%d %d", &q.i, &q.j);
			--q.i, --q.j;
			q.k = k;
			Q.push_back(q);
		}
		
		sort(ALL(Q));
		int l = 0;
		for(int i = 0; i < Q.size(); ++i) {
			if(l < Q[i].i) {
				for(int j = l; j < Q[i].i; ++j) {
					FT.add(j, -FT.sum(j)+FT.sum(j-1));
					FTU.add(j, -FTU.sum(j)+FTU.sum(j-1));
					if(L[j] != -1) {
						FT.add(L[j], X[j]);
						FTU.add(L[j], 1);
					}
				}
				l = Q[i].i;
			}
			
			Q[i].r = (double)(FT.sum(Q[i].j)-FT.sum(Q[i].i-1))/(double)(FTU.sum(Q[i].j)-FTU.sum(Q[i].i-1));
			
			swap(Q[i].k, Q[i].i);
		}
		sort(ALL(Q));
		
		printf("Case %d:\n", no++);
		for(int i = 0; i < Q.size(); ++i)
			printf("%0.6lf\n", Q[i].r);
	}
	return 0;
}
