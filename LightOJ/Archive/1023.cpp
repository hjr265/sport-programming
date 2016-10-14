// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1023
// Discovering Permutations
// implementation
// 
// 
// AC (2011-07-28 09:13:11)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+n

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, K;
		scanf("%d %d", &N, &K);
		char Z[N];
		Z[0] = 'A';
		for(int i = 1; i < N; ++i)
			Z[i] = Z[i-1]+1;
		Z[N] = '\0';
		printf("Case %d:\n", no++);
		while(K--) {
			printf("%s\n", Z);
			if(!next_permutation(SLC(Z, N)))
				break;
		}
	}
	return 0;
}
