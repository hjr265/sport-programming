// In the name of Allah, Most Gracious, Most Merciful

// Timus/1087
// The Time to Take Stones
// games
// 
// 
// AC (14:35:58 29 Apr 2012)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

int k[55];
bool S[10005];

int main() {
	CLR(S);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i)
		scanf("%d", &k[i]);
	S[0] = true;
	S[1] = false;
	for(int i = 2; i <= n; ++i) {
		for(int j = 0; j < m; ++j) if(i-k[j] >= 0)
			S[i] = S[i]||!S[i-k[j]];
	}
	printf("%d\n", S[n] ? 1 : 2);
	return 0;
}
