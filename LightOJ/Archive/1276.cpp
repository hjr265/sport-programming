// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1276
// Very Lucky Numbers
// binary search
// 
// 
// AC (2012-01-11 11:00:35)

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

vector<vlong> L;
set<vlong> Lset1;
set<vlong> Lset2;

void genlucky(vlong u = 0) {
	if(u < 1000000000002LL) if(Lset1.count(u) == 0) {
		if(u > 0) {
			Lset1.insert(u);
			L.push_back(u);
		}
		genlucky(u*10+4);
		genlucky(u*10+7);
	}
}

void genvlucky(int n, vlong u = 1) {
	for(int i = 0; i < n && u*L[i] <= 1000000000000LL; ++i) if(Lset2.count(u*L[i]) == 0) {
		if(Lset1.count(u*L[i]) == 0) {
			Lset2.insert(u*L[i]);
			L.push_back(u*L[i]);
		}
		genvlucky(n, u*L[i]);
	}
}

void init() {
	genlucky();
	sort(ALL(L));
	genvlucky(L.size());
	sort(ALL(L));
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong A, B;
		scanf("%lld %lld", &A, &B);
		printf("Case %d: %d\n", no++, upper_bound(ALL(L), B)-lower_bound(ALL(L), A));
	}
	return 0;
}
