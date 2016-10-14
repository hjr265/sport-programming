// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1048
// Conquering Keokradong
// binary search, greedy
// 
// 
// AC (2011-12-11 21:46:47)

#include <cstdio>

int c[1005];

bool ok(int N, int K, int x, bool p = false) {
	int t = 0;
	for(int i = 0; i <= N+1; ) {
		if(K < 0)
			return false;
		t += c[i];
		if(t <= x && (!p || N-i >= K-1)) {
			++i;
		} else {
			if(p)
				printf("%d\n", t-c[i]);
			t = 0, --K;
		}
	}
	if(p)
		printf("%d\n", t);
	return K >= 0;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, K;
		scanf("%d %d", &N, &K);
		c[0] = 0;
		for(int i = 1; i <= N + 1; ++i)
			scanf("%d", &c[i]);
		int l = 0, h = 100000005, m;
		while(l < h) {
			m = (l+h)/2;
			if(ok(N, K, m))
				h = m-1;
			else
				l = m+1;
		}
		for(int i = m-20; i < m+20; ++i) if(i >= 0 && ok(N, K, i)) {
			printf("Case %d: %d\n", no++, i);
			ok(N, K, i, true);
			break;
		}
	}
	return 0;
}
