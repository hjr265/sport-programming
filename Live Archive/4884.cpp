// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4884
// Chain Code
// geometry
// 
// 
// AC (2011-08-09 11:28:02)

#include <cstdio>

using namespace std;

typedef long long vlong;

int main() {
	while(true) {
		int c1[] = {0, 0}, c2[] = {0, 0}, b = 0;
		vlong A = 0;
		char x;
		int z;
		while((z = scanf("%c", &x)) == 1 && x != '\n') {
			b++;			x -= '0';
			c1[0] = c2[0];
			c1[1] = c2[1];
			switch(x) {
				case '0':
					c2[0] += 1;
					c2[1] += 0;
					break;
				case '1':
					c2[0] += 1;
					c2[1] += 1;
					break;
				case '2':
					c2[0] += 0;
					c2[1] += 1;
					break;
				case '3':
					c2[0] += -1;
					c2[1] += 1;
					break;
				case '4':
					c2[0] += -1;
					c2[1] += 0;
					break;
				case '5':
					c2[0] += -1;
					c2[1] += -1;
					break;
				case '6':
					c2[0] += 0;
					c2[1] += -1;
					break;
				case '7':
					c2[0] += 1;
					c2[1] += -1;
					break;
			}
			A += c1[0]*c2[1]-c1[1]*c2[0];
		}
		A /= 2;
		vlong i = A-b/2+1;
		if(z == -1)
			break;
		else
			printf("%lld\n", i+b);
	}
	return 0;
}
