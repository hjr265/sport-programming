// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1088
// Points in Segments
// binary search
// 
// 
// AC (2011-10-25 02:45:34)

#include <cstdio>
#include <algorithm>

using namespace std;

int p[100005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i = 0; i < n; ++i)
			scanf("%d", &p[i]);
		printf("Case %d:\n", no++);
		while(q--) {
			int A, B;
			scanf("%d %d", &A, &B);
			printf("%d\n", upper_bound(p, p+n, B)-lower_bound(p, p+n, A));
		}
	}
	return 0;
}
