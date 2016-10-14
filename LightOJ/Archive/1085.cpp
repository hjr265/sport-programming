// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1085
// All Possible Increasing Subsequences
// trees
// 
// 
// AC (2012-05-02 09:52:05)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

using namespace std;

typedef long long vlong;

const vlong mod = 1000000007LL;

class Fwtree {
	vlong t[100005];
	
public:
	Fwtree() {
		CLR(t);
	}
	
	void add(int i, vlong v) {
		while(i <= 100002)
			t[i] += v, i += i & -i;
	}
	
	vlong sum(int i) {
		vlong r = 0;
		while(i > 0)
			r += t[i], i -= i & -i;
		return r;
	}
};

struct Num {
	int i, j, v;
};

Num A[100005];

bool numcmpv(const Num &l, const Num &r) {
	return l.v < r.v;
}

bool numcmpi(const Num &l, const Num &r) {
	return l.i < r.i;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		CLR(A);
		for(int i = 0; i < n; ++i) {
			A[i].i = i+1;
			scanf("%d", &A[i].v);
		}
		sort(SLC(A, n), numcmpv);
		for(int i = 0, j = 1; i < n; ++i) {
			if(i > 0 && A[i-1].v != A[i].v)
				++j;
			A[i].j = j;
		}
		sort(SLC(A, n), numcmpi);
		Fwtree F;
		int z = 0;
		for(int i = 0; i < n; ++i) {
			F.add(A[i].j, (F.sum(A[i].j-1)+1)%mod);
			z = max(z, A[i].j);
		}
		printf("Case %d: %lld\n", no++, F.sum(z)%mod);
	}
	return 0;
}
