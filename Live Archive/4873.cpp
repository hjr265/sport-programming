// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4873
// Penney Game
// implementation
// 
// 
// AC (2011-07-30 07:15:49)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

int main() {
	int P;
	scanf("%d", &P);
	for(int x = 0; x < P; ++x) {
		int N;
		scanf("%d", &N);
		char S[45];
		scanf("%s", &S);
		int T[45];
		for(int i = 0; S[i]; ++i)
			T[i] = S[i] == 'H' ? 1 : 0;
		int Z[8];
		CLR(Z);
		for(int i = 0; S[i+2]; ++i)
			Z[(((T[i]<<1)|T[i+1])<<1)|T[i+2]] += 1;
		printf("%d", N);
		for(int i = 0; i < 8; ++i)
			printf(" %d", Z[i]);
		printf("\n");
	}
	return 0;
}
