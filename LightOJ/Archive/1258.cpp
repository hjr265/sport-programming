// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1258
// Making Huge Palindromes
// strings
// 
// 
// AC (2012-01-18 09:45:25)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

using namespace std;

char S[2000005];
char T[1000005];
int p[2000005];

int ans(char S[]) {
	CLR(p);
	int n = strlen(S);
	strcpy(T, S);
	reverse(SLC(S, n));
	strcat(S, T);
	strcat(S, "$");
	int l = 2*n+1;
	p[0] = -1;
	p[1] = 0;
	for(int i = 2, j = 0; i < l; ) {
		if(S[i-1] == S[j])
			p[i++] = ++j;
		else if(j > 0)
			j = p[j];
		else
			p[i++] = 0;
	}
	int r = p[l-1];
	while(r > n)
		r = p[r];
	return 2*n-r;
}

int main() {
	int T, no = 1;
	scanf("%d\n", &T);
	while(T--) {
		gets(S);
		printf("Case %d: %d\n", no++, ans(S));
	}
	return 0;
}
