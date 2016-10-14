// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1163
// Bank Robbery
// number theory
// 
// 
// AC (2011-08-04 10:47:34)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong Z;
		scanf("%lld", &Z);
		vlong N1 = Z+Z/9, N2 = -1;
		for(vlong i = N1-10; i <= N1+10; ++i) if(i != N1 && i-i/10 == Z) {
			N2 = i;
			break;
		}
		if(N1 > N2)
			swap(N1, N2);
		printf("Case %d: ", no++);
		if(N1 == -1)
			printf("%lld\n", N2);
		else
			printf("%lld %lld\n", N1, N2);
	}
	return 0;
}
