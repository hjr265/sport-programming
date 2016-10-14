// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1025
// The Specials Menu
// dp
// 
// 
// AC (2012-02-04 13:51:19)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

char W[62];
vlong m[62][62];

vlong dp(int i, int j) {
	if(i > j)
		return 0;
	vlong &r = m[i][j];
	if(r == -1) {
		r = 0;
		r += dp(i+1, j);
		r += dp(i, j-1);
		r -= dp(i+1, j-1);
		if(W[i] == W[j])
			r += dp(i+1, j-1)+1;
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", W);
		SET(m);
		printf("Case %d: %lld\n", no++, dp(0, strlen(W)-1));
	}
	return 0;
}
