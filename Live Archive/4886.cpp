// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4886
// Page Count
// implementation
// 
// 
// AC (2011-08-09 09:29:52)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

char s[40000];

int main() {
	int n;
	while(scanf("%d\n", &n) == 1 && n != 0) {
		int t = 0;
		gets(s);
		char p[n+1];
		CLR(p);
		int l, h, v;
		while((v = 0) == 0 && sscanf(s+t, "%d-%d", &l, &h) == 2 || (v = 1) == 1 && sscanf(s+t, "%d", &l) == 1) {
			switch(v) {
				case 0:
					if(l <= h) {
						for(int i = l; i <= h && i <= n; ++i)
							p[i] = 1;
					}
					break;
				case 1:
					if(l <= n)
						p[l] = 1;
					break;
			}
			while(s[t] && s[t] != ',')
				t++;
			if(s[t])
				t++;
			else
				break;
		}
		int z = 0;
		for(int i = 1; i <= n; ++i) if(p[i])
			z += 1;
		printf("%d\n", z);
	}
	return 0;
}
