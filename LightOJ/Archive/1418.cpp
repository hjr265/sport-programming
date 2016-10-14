// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1418
// Trees on My Island
// geometry
// 
// 
// AC (2012-02-27 17:28:30)

#include <cstdio>
#include <cstdlib>

typedef long long vlong;

struct Point {
	vlong x, y;
};

Point P[10002];

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%lld %lld", &P[i].x, &P[i].y);
		P[N] = P[0];
		vlong a = 0;
		for(int i = 0; i < N; ++i)
			a += P[i].x*P[i+1].y-P[i].y*P[i+1].x;
		a = abs(a);
		vlong b = 0;
		for(int i = 0; i < N; ++i)
			b += gcd(abs(P[i].x-P[i+1].x), abs(P[i].y-P[i+1].y));
		printf("Case %d: %lld\n", no++, (a-b+2)/2);
	}
	return 0;
}
