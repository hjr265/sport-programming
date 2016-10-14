// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1170
// Counting Perfect BST
// *binary search, dp, *combinatorics
// 
// 
// AC (2012-01-10 01:31:38)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

const vlong mod = 100000007LL;

vlong modpow(vlong b, vlong p, vlong m) {
	vlong r = 1;
	for(; p; p /= 2) {
		b %= m;
		if(p%2)
			r = (r*b)%m;
		b *= b;
	}
	return r;
}

template<class T> T modinv(T b, T m) {
	return modpow(b, m-2, m);
}

set<vlong> Pset;
vector<vlong> P;

void initperfpow() {
	for(vlong i = 2; i*i < 10000000005LL; ++i) {
		for(vlong j = i*i; j < 10000000005LL; j *= i) {
			if(Pset.count(j) == 0) {
				Pset.insert(j);
				P.push_back(j);
			}
		}
	}
	sort(ALL(P));
}

vlong C[100010];

vlong initcatalan() {
	C[0] = C[1] = 1;
	for(vlong i = 1; i < 100005; ++i)
		C[i+1] = (((((((C[i]*(4*i+2))%mod)+mod)%mod)*modinv(i+2, mod))%mod)+mod)%mod;
}

int main() {
	initperfpow();
	initcatalan();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong a, b;
		scanf("%lld %lld", &a, &b);
		vector<vlong>::iterator left = lower_bound(ALL(P), a), right = upper_bound(ALL(P), b);
		printf("Case %d: ", no++);
		if(right == left)
			printf("0\n");
		else
			printf("%lld\n", C[right-left]%mod);
	}
	return 0;
}
