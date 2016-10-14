// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1089
// Points in Segments (II)
// binary search
// 
// 
// AC (2012-05-02 10:08:41)

#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

vector<int> S, E;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, q;
		scanf("%d %d", &n, &q);
		S.clear();
		E.clear();
		for(int i = 0; i < n; ++i) {
			int A, B;
			scanf("%d %d", &A, &B);
			S.push_back(A);
			E.push_back(B);
		}
		sort(ALL(S));
		sort(ALL(E));
		printf("Case %d:\n", no++);
		while(q--) {
			int P;
			scanf("%d", &P);
			int i = lower_bound(ALL(S), P)-S.begin(), j = lower_bound(ALL(E), P)-E.begin();
			while(S[i] == P)
				++i;
			printf("%d\n", i-j);
		}
	}
	return 0;
}
