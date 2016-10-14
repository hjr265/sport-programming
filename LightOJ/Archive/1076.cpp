// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1076
// Get the Containers
// binary search, greedy
// 
// 
// AC (2011-10-25 09:24:37)

#include <cstdio>

int c[1005];

bool ok(int n, int m, int x) {
	int t = 0;
	for(int i = 0; i < n; ) {
		if(m < 0)
			return false;
		t += c[i];
		if(t <= x)
			++i;
		else
			t = 0, --m;
			
	}
	return m > 0;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &c[i]);
		int l = 0, h = 1000000005, x;
		while(l < h) {
			x = (l+h)/2;
			if(ok(n, m, x))
				h = x;
			else
				l = x + 1;
		}
		for(int i = x - 10; i < x + 10; ++i) if(ok(n, m, i)) {
			printf("Case %d: %d\n", no++, i);
			break;
		}
	}
	return 0;
}
