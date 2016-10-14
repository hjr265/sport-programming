// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5900
// Binomial coefficients
// combinatorics, binary search
// 
// 
// AC (2012-06-08 15:05:04)

#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef long long vlong;

struct Coeff {
	vlong n, r, v;
	
	Coeff(vlong n_, vlong r_, vlong v_) : n(n_), r(r_), v(v_) {}
	
	bool operator<(const Coeff &b) const {
		return v < b.v;
	}
};

vlong C[2][100000005];
vector<Coeff> R;
vlong Z[300000];

void init() {
	for(int i = 2; i < 2000005; ++i) {
		for(int j = 1; j <= i; ++j) {
			if(i == j)
				C[i%2][j] = 1;
			else if(j == 1)
				C[i%2][j] = i;
			else
				C[i%2][j] = C[(i+1)%2][j]+C[(i+1)%2][j-1];
			if(C[i%2][j] > 1000000000000000LL)
				break;
			if(j != 2 && j != 1 && j != i-1 && j != i-2 && j <= i/2)
				R.push_back(Coeff(i, j, C[i%2][j]));
		}
	}
	sort(ALL(R));
	for(int i = 0; i < R.size(); ++i)
		Z[i] = R[i].v;
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	while(T--) {
		vlong m;
		scanf("%lld", &m);
		vector<pair<vlong, vlong> > G;
		for(vlong *i = lower_bound(SLC(Z, R.size()), m), *e = upper_bound(SLC(Z, R.size()), m); i != e; ++i) {
			G.push_back(pair<vlong, vlong>(R[i-Z].n, R[i-Z].r));
			if(R[i-Z].n-R[i-Z].r != R[i-Z].r)
				G.push_back(pair<vlong, vlong>(R[i-Z].n, R[i-Z].n-R[i-Z].r));
		}
		G.push_back(pair<vlong, vlong>(m, 1));
		if(m > 3)
			G.push_back(pair<vlong, vlong>(m, m-1));
		vlong l = 2, h = 100000005LL, x = -1;
		while(l < h && x != (l+h)/2) {
			x = (l+h)/2;
			if(x*(x-1) == 2*m)
				break;
			if(x*(x-1) < 2*m)
				l = x;
			else
				h = x;
				
		}
		for(vlong i = max(x-2, 3LL); i < x+2; ++i) if(i*(i-1) == 2*m) {
			G.push_back(pair<vlong, vlong>(i, 2));
			if(i > 4)
				G.push_back(pair<vlong, vlong>(i, i-2));
			break;
		}
		sort(ALL(G));
		printf("%d\n", G.size());
		for(int i = 0; i < G.size(); ++i) {
			if(i > 0)
				printf(" ");
			printf("(%lld,%lld)", G[i].first, G[i].second);
		}
		printf("\n");
	}
	return 0;
}
