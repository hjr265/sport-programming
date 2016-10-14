// In the name of Allah, Most Gracious, Most Merciful

// Codechef/July Cook-Off 2012/CIELRCPT
// Ciel and Receipt
// *implementation, math
// http://www.codechef.com/COOK24/problems/CIELRCPT
// 
// AC

#include <cstdio>

int O[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int p;
		scanf("%d", &p);
		int r = 0;
		for(int i = 11; i >= 0 && p; --i) if(p >= O[i]) {
			p -= O[i];
			++r;
			i = 12;
		}
		printf("%d\n", r);
	}
	return 0;
}
