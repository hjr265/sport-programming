// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1354
// IP Checking
// implementation
// 
// 
// AC (2011-11-20 16:12:07)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int p[2][4];
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 4; ++j)
				scanf("%d.", &p[i][j]);
		}
		for(int i = 0; i < 4; ++i) {
			int r = 0;
			int x = 1;
			while(p[1][i]) {
				if(p[1][i]%10)
					r += x;
				x *= 2;
				p[1][i] /= 10;
			}
			p[1][i] = r;
		}
		printf("Case %d: ", no++);
		if(p[0][0] == p[1][0] && p[0][1] == p[1][1] && p[0][2] == p[1][2] && p[0][3] == p[1][3])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
