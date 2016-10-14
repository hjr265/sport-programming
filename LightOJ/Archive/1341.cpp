// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1341
// Aladdin and the Flying Carpet
// number theory
// 
// 
// AC (2012-03-19 23:05:54)

#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

bool S[1000002];
vector<vlong> P;
vector<pair<vlong, int> > F;

void psieve() {
	CLR(S);
	P.push_back(2);
	for(vlong i = 3; i < 1000002; i += 2) if(!S[i]) {
		P.push_back(i);
		for(vlong j = i*i; j < 1000002; j += i*2)
			S[j] = true;
	}
}

void factorize(vlong n) {
	F.clear();
	for(int i = 0; i < P.size() && P[i]*P[i] <= n && n > 1; ++i) if(n%P[i] == 0) {
		int k = 0;
		while(n%P[i] == 0)
			++k, n /= P[i];
		F.push_back(pair<vlong, int>(P[i], k));
	}
	if(n > 1)
		F.push_back(pair<vlong, int>(n, 1));
}

vlong count(vlong l, vlong h, int i, vlong x) {
	vlong r = 0;
	if(i == F.size() && x >= l && x <= h)
		r += 1;
	if(i < F.size()) {
		vlong y = 1;
		for(int j = 0; j <= F[i].second; ++j, y *= F[i].first)
			r += count(l, h, i+1, x*y);
	}
	return r;
}

int main() {
	psieve();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong a, b;
		scanf("%lld %lld", &a, &b);
		factorize(a);
		printf("Case %d: %lld\n", no++, count(b, (a+b-1)/b, 0, 1)/2);
	}
	return 0;
}
