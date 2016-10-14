// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1133
// Array Simulation
// implementation
// 
// 
// AC (2011-09-14 11:32:28)

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int a[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		while(m--) {
			char c[5];
			scanf("%s", &c[0]);
			if(c[0] == 'S') {
				int D;
				scanf("%d", &D);
				for(int i = 0; i < n; ++i)
					a[i] += D;
			} else if(c[0] == 'M') {
				int D;
				scanf("%d", &D);
				for(int i = 0; i < n; ++i)
					a[i] *= D;
			} else if(c[0] == 'D') {
				int K;
				scanf("%d", &K);
				for(int i = 0; i < n; ++i)
					a[i] /= K;
			} else if(c[0] == 'R') {
				for(int i = 0; i < n / 2; ++i)
					swap(a[i], a[n-i-1]);
			} else {
				int M, N;
				scanf("%d %d", &M, &N);
				swap(a[M], a[N]);
			}
		}
		printf("Case %d:\n%d", no++, a[0]);
		for(int i = 1; i < n; ++i)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}
