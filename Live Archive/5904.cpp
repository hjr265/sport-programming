// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5904
// Please, go first
// greedy
// 
// 
// AC (2012-06-08 15:08:44)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

int char2int(char c) {
	if(c >= '0' && c <= '9')
		return c-'0';
	if(c >= 'a' && c <= 'z')
		return c-'a'+10;
	if(c >= 'A' && c <= 'Z')
		return c-'A'+10+26;
}

char S[25002];
int D[64], C[64];
bool P[64];

int sum(vlong n) {
	return (int)(((n+1)*n)/2);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s", S);
		SET(D);
		CLR(C);
		int R = 0;
		for(int i = n-1; i >= 0; --i) {
			int v = char2int(S[i]);
			if(D[v] == -1)
				D[v] = i;
			R += (D[v]-i)*5;
			++C[v];
		}
		CLR(P);
		for(int i = 0; i < n; ++i) {
			int v = char2int(S[i]);
			if(P[v])
				continue;
			R -= sum(C[v]-1)*5;
			P[v] = true;
		}
		printf("%d\n", R);
	}
	return 0;
}
