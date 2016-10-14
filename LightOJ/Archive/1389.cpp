// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1389
// Scarecrow
// greedy
// 
// 
// AC (2012-01-10 23:37:00)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		char S[102];
		scanf("%s", &S);
		int r = 0;
		for(int i = 0; i < N; ++i) if(S[i] == '.') {
			++r;
			for(int j = i; j < i+3 && j < N; ++j)
				S[j] = '#';
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
