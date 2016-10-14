// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1236
// Pairs Forming LCM
// number theory
// 
// 
// AC (2012-05-04 19:13:11)

#include <cstdio>
#include <cstring>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

vector<vlong> P;
bool S[10000005];

void psieve() {
	CLR(S);
	P.push_back(2);
	for(vlong i = 3; i < 10000005; i += 2) if(!S[i]) {
		P.push_back(i);
		for(vlong j = i*i; j < 10000005; j += 2*i)
			S[j] = true;
	}
}

int main() {
	psieve();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong n;
		scanf("%lld", &n);
		vlong r = 1;
		for(int i = 0; i < P.size() && n > 1; ++i) if(n%P[i] == 0) {
			int k = 0;
			for(; n%P[i] == 0; n /= P[i])
				++k;
			r *= 2*k+1;
		}
		if(n > 1)
			r *= 3;
		printf("Case %d: %lld\n", no++, (r+1)/2);
	}
	return 0;
}
