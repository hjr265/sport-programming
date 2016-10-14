// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1317
// Throwing Balls into the Baskets
// probabilities
// 
// 
// AC (2012-05-09 17:01:17)

#include <cstdio>

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double N, M, K, P;
		scanf("%lf %lf %lf %lf", &N, &M, &K, &P);
		printf("Case %d: %0.6lf\n", no++, N*K*P);
	}
	return 0;
}
