// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4056
// Nested Squares
// implementation
// 
// 
// AC (2011-10-05 19:35:59)

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f(int n, int i, int j) {
	--i;
	--j;
	if(i >= n)
		i = n-i%n-2;
	if(j >= n)
		j = n-j%n-2;
	return min(i, j);
}

char S[50005];

int main() {
	int N, no = 1;
	scanf("%d", &N);
	while(N--) {
		printf("Square %d:\n", no++);
		int Q, l;
		scanf("%s %d", S, &Q);
		l = strlen(S);
		for(int i = 1; i <= Q; ++i) {
			int r1, c1, r2, c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			printf("Query %d:\n", i);
			for(int j = r1; j <= r2; ++j) {
				for(int k = c1; k <= c2; ++k)
					printf("%c", S[f(l, j, k)]);
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
