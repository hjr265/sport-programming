// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1158
// Anagram Division
// dp
// 
// 
// AC (2012-02-04 15:20:24)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

char s[12];
vlong m[1025][1005];

vlong dp(int n, int d, int x, int o) {
	if(x == (1<<n)-1)
		return o == 0;
	vlong &r = m[x][o];	
	if(r == -1) {
		r = 0;
		bool t[11];
		CLR(t);
		for(int i = 0; i < n; ++i) if((x&(1<<i)) == 0 && !t[s[i]-'0']) {
			r += dp(n, d, x|(1<<i), (o*10+(s[i]-'0'))%d);
			t[s[i]-'0'] = true;
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int d;
		scanf("%s %d", s, &d);
		SET(m);
		printf("Case %d: %d\n", no++, dp(strlen(s), d, 0, 0));
	}
	return 0;
}
