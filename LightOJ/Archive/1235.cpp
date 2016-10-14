// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1235
// Coin Change (IV)
// binary search
// 
// 
// AC (2012-05-26 23:36:08)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

using namespace std;

int P[10];
int A[20];
int L[20000];

int main() {
	P[0] = 1;
	for(int i = 1; i < 10; ++i)
		P[i] = P[i-1]*3;
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, K;
		scanf("%d %d", &n, &K);
		for(int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		CLR(L);
		for(int i = 0; i < P[n/2+n%2]; ++i) {
			for(int j = 0, x = i; j < n/2+n%2; ++j, x /= 3)
				L[i] += A[j]*(x%3);
		}
		sort(SLC(L, P[n/2+n%2]));
		printf("Case %d: ", no++);
		bool k = false;
		for(int i = 0; i < P[n-n/2-n%2] && !k; ++i) {
			int R = 0;
			for(int j = n/2+n%2, x = i; j < n; ++j, x /= 3)
				R += A[j]*(x%3);
			int j = lower_bound(SLC(L, P[n/2+n%2]), K-R)-L;
			if(L[j] == K-R) {
				printf("Yes\n");
				k = true;
			}
		}
		if(!k)
			printf("No\n");
	}
	return 0;
}
