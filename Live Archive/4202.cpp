// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4202
// Schedule of a Married Man
// implementation
// 
// 
// AC (2011-10-02 11:04:57)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m[2][2];
		for(int i = 0; i < 2; ++i) {
			for(int j = 0, x, y; j < 2; m[i][j] = x*60+y, ++j)
				scanf("%d:%d", &x, &y);
		}
		printf("Case %d: %s Meeting\n", no++, m[0][0] <= m[1][1] && m[0][1] >= m[1][0] ? "Mrs" : "Hits");
	}
	return 0;
}
