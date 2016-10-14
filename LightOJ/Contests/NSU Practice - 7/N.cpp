// In the name of Allah, Most Gracious, Most Merciful

// Secret Origins
// implementation
// AC (1080)

#include <cstdio>

typedef long long vlong;

vlong ans(vlong N) {
	int x = 0;
	for(int i = 0; i < 32; ++i) {
		if(((N>>i)&3) == 1) {
			N ^= (3<<i);
			for(int j = 0; j < i; ++j) if(N&(1<<j))
				N ^= 1<<j;
			for(int j = 0; j < x; ++j)
				N ^= 1<<j;
			break;
		} else if((N&(1<<i))) {
			++x;
		}
	}
	return N;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong N;
		scanf("%lld", &N);
		printf("Case %d: %lld\n", no++, ans(N));
	}
	return 0;
}
