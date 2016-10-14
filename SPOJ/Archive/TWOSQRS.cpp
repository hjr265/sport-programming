// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/TWOSQRS
// Two squares or not two squares
// number theory
// 
// 
// AC (2012-11-24 20:21:59)

#include <cstdio>
#include <cstring>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

typedef long long vlong;

bool S[1000005];
vector<vlong> P;

void psieve() {
	SET(S, 0);
	for(vlong i = 3; i < 1000005; i += 2) if(!S[i]) {
		P.push_back(i);
		for(vlong j = i*i; j < 1000005; j += 2*i)
			S[j] = true;
	}
}

int main() {
	psieve();
	
	int c;
	scanf("%d", &c);
	while(c--) {
		vlong n;
		scanf("%lld", &n);
		
		bool f = true;
		for(int i = 0; i < P.size(); ++i) if(n%P[i] == 0) {
			int k = 0;
			while(n%P[i] == 0)
				++k, n /= P[i];
			if((P[i]-3)%4 == 0 && k%2 != 0)
				f = false;
		}
		if(n > 1 && (n-3)%4 == 0)
			f = false;
		printf("%s\n", f ? "Yes" : "No");
	}
	return 0;
}
