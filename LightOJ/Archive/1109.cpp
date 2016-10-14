// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1109
// False Ordering
// number theory
// 
// 
// AC (2011-07-27 00:00:09)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

using namespace std;

struct Num {
	int i, v;
	
	bool operator<(const Num &r) const {
		return v < r.v || v == r.v && i > r.i;
	}
};

Num Z[1005];

int main() {
	CLR(Z);
	for(int i = 1; i <= 1000; ++i) {
		Z[i-1].i = i;
		for(int j = 1; j*j <= i; ++j) if(i%j == 0)
			Z[i-1].v += j*j == i ? 1 : 2;
	}
	sort(SLC(Z, 1000));
	int T, no = 1;
	scanf("%d", &T);
	while(T-- > 0) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", no++, Z[n-1].i);
	}
	return 0;
}
