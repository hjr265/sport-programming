// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1255
// Substring Frequency
// strings
// 
// 
// AC (2011-09-17 11:45:24)

#include <cstdio>
#include <cstring>

char s[1000005];
char w[1000005];
int p[1000005];

int kmp(char s[], char w[]) {
	int n = strlen(s), m = strlen(w);
	p[0] = -1;
	p[1] = 0;
	for(int i = 2, j = 0; i < m; ) {
		if(w[i-1] == w[j])
			p[i++] = ++j;
		else if(j > 0)
			j = p[j];
		else
			p[i++] = 0;
	}
	int z = 0;
	for(int i = 0, j = 0; j+i < n; ) {
		if(w[i] == s[j+i]) {
			if(i == m-1) {
				++z;
				j += i - p[i];
				if(p[i] > -1)
					i = p[i];
				else
					i = 0;
				continue;
			}
			++i;
		} else {
			j += i - p[i];
			if(p[i] > -1)
				i = p[i];
			else
				i = 0;
		}
	}
	return z;
}

int main() {
	int T, no = 1;
	scanf("%d\n", &T);
	while(T--) {
		gets(s);
		gets(w);
		printf("Case %d: %d\n", no++, kmp(s, w));
	}
	return 0;
}
