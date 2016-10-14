// In the name of Allah, Most Gracious, Most Merciful

// UVA/10032
// Tug of War
// dp
// 
// 
// AC (2012-06-12 10:11:14)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+(n)

using namespace std;

typedef long long vlong;

int W[100+5];
vlong S[450*100+5];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int A = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &W[i]);
			A += W[i];
		}
		sort(SLC(W, n));
		CLR(S);
		S[0] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = A; j >= W[i]; --j)
				S[j] |= S[j-W[i]]<<1;
		}
		int l = 0, r = A;
		for(int i = 0; i <= (A+1)/2; ++i) {
            for(int j = 0; j <= (n+1)/2; ++j) {
                if(abs(n-2*j) <= 1 && (S[i]&(1LL<<j)) != 0 && (S[abs(A-i)]&(1LL<<(n-j))) != 0 && abs(A-2*i) < r-l) {
                    l = min(i, A-i);
                    r = max(i, A-i);
                }
            }
        }
		printf("%d %d\n", l, r);
		if(T > 0)
			printf("\n");
	}
	return 0;
}
