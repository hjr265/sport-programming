// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1338
// Hidden Secret!
// implementation
// 
// 
// AC (2011-10-17 01:41:51)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

inline char lower(char x) {
	return x >= 'A' && x <= 'Z' ? x - 'A' + 'a' : x;
}

bool okay(char a[], char b[]) {
	static int g[256];
	CLR(g);
	for(int i = 0; a[i]; ++i)
		++g[lower(a[i])];
	for(int i = 0; b[i]; ++i) {
		if(g[lower(b[i])] == 0)
			return false;
		--g[lower(b[i])];
	}
	return true;
}

int main() {
	int T, no = 1;
	scanf("%d\n", &T);
	while(T--) {
		char a[105], b[105];
		gets(a);
		gets(b);
		printf("Case %d: %s\n", no++, strlen(a) < strlen(b) && okay(b, a) || okay(a, b) ? "Yes" : "No");
	}
	return 0;
}
