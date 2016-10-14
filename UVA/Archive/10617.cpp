// In the name of Allah, Most Gracious, Most Merciful

// UVA/10617
// Again Palindrome
// dp
// 
// 
// AC (2012-06-12 13:12:15)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

char S[60+2];
vlong D[60+2][60+2];

vlong dp(int i, int j) {
	if(i > j)
		return 0;
	vlong &r = D[i][j];
	if(r == -1) {
		r = 0;
		r += dp(i+1, j);
		r += dp(i, j-1);
		r -= dp(i+1, j-1);
		if(S[i] == S[j])
			r += 1+dp(i+1, j-1);
	}
	return r;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", S);
		SET(D);
		printf("%lld\n", dp(0, strlen(S)-1));
	}
	return 0;
}
