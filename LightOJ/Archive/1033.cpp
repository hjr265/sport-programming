// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1033
// Generating Palindromes
// dp
// 
// 
// AC (2011-08-01 19:59:04)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

char s[105];
int mo[105][105];

int dp(int n, int i, int j) {
	if(i < 1 || j < 1)
		return 0;
	int &m = mo[i][j];
	if(m == -1) {
		if(s[i] == s[n - j + 1])
			m = dp(n, i-1, j-1)+1;
		else
			m = max(dp(n, i-1, j), dp(n, i, j-1));
	}
	return m;
}

int main() {
	int T, no = 1;
	scanf("%d\n", &T);
	while(T--) {
		gets(s+1);
		SET(mo);
		int n = strlen(s+1);
		printf("Case %d: %d\n", no++, n-dp(n, n, n));
	}
	return 0;
}
