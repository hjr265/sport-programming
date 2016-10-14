// In the name of Allah, Most Gracious, Most Merciful

// LightOJ
// AIUB Junior Practice (Mock)
// A
// Number System Crackdown
// implementation
// AC (1154)

#include <cstdio>

char S[10002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int B;
		scanf("%d %s", &B, S);
		int r = 0;
		for(int i = 0; S[i]; ++i)
			r = (r*B+S[i]-'0')%1000003;
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
