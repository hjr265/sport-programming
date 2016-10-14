// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1198
// Karate Competition
// graph matchings, *greedy
// 
// 
// AC (2011-12-12 21:28:08)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+(n)

using namespace std;

int A[55], B[55];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		sort(SLC(A, N));
		for(int i = 0; i < N; ++i)
			scanf("%d", &B[i]);
		sort(SLC(B, N));
		int r = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = N-1; j >= 0; --j) if(A[i] > B[j] && B[j] != -1) {
				A[i] = -1;
				B[j] = -1;
				r += 2;
				break;
			}
		}
		for(int i = 0; i < N; ++i) {
			for(int j = N-1; j >= 0; --j) if(A[i] == B[j] && B[j] != -1) {
				B[j] = -1;
				r += 1;
				break;
			}
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
