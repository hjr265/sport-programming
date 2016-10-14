// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4876
// Show Me The Fax
// implementation
// 
// 
// AC (2011-07-30 10:29:22)

#include <cstdio>

char z[1000000];
char s[10010];

int htoi(char a) {
	return a >= '0' && a <= '9' ? a-'0' : a-'A'+10;
}

int btoi(char a[], int i) {
	return (htoi(a[i])<<4)|htoi(a[i+1]);
}

int main() {
	int P;
	scanf("%d", &P);
	while(P--) {
		int t, B;
		scanf("%d %d\n", &t, &B);
		int k = 0, d = 0;
		int f = 0;
		s[0] = '\0';
		while(B > 0) {
			gets(s+f);
			f += 80;
			B -= 40;
		}
		for(int i = 0; s[i]; ) {
			int x = btoi(s, i);
			i += 2;
			if((x&(1<<7)) > 0) {
				int y = btoi(s, i);
				for(int j = 0; j < (x^(1<<7))+3 && s[i]; ++j) {
					if(d%40 == 0) {
						sprintf(z+k, "\n", y);
						k += 1;
					}
					sprintf(z+k, "%02X", y);
					k += 2;
					d += 1;
				}
				i += 2;
			} else {
				for(int j = 0; j <= x && s[i]; ++j, i += 2, B -= 1) {
					int y = btoi(s, i);
					if(d%40 == 0) {
						sprintf(z+k, "\n", y);
						k += 1;
					}
					sprintf(z+k, "%02X", y);
					k += 2;
					d += 1;
				}
			}
		}
		printf("%d %d%s\n", t, d, z);
	}
	return 0;
}
