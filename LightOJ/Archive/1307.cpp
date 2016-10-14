// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1307
// Counting Triangles
// binary search
// 
// 
// AC (2011-12-11 21:00:11)

#include <cstdio>
#include <algorithm>

typedef long long vlong;

using namespace std;

vlong A[2002], B[2002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%lld", &A[i]);
		sort(A, A+N);
		for(int i = 0; i < N; ++i)
			B[i] = A[i]*A[i];
		vlong r = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j)
				r += lower_bound(B+j+1, B+N, (A[i]+A[j])*(A[i]+A[j]))-upper_bound(B+j+1, B+N, A[i]);
		}
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
