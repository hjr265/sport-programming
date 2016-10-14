// In the name of Allah, Most Gracious, Most Merciful

// Building Twin Towers
// dp
// AC (1166)

#include <cstdio>
#include <algorithm>

using namespace std;

int h[52];
int d[2][500002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int s = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &h[i]);
			s += h[i];
		}
		for(int j = 0; j <= s; ++j)
			d[0][j] = -500002;
		d[0][0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = s; j >= 0; --j) {
				int p = (i-1)%2, c = i%2;
				d[c][j] = d[p][j];
				d[c][j] = max(d[c][j], d[p][abs(h[i]-j)]+(h[i] >= j ? h[i]-j : 0));
				if(j+h[i] <= s)
					d[c][j] = max(d[c][j], d[p][j+h[i]]+h[i]);	
			}
		}
		printf("Case %d: ", no++);
		if(d[n%2][0] == 0)
			printf("impossible");
		else
			printf("%d", d[n%2][0]);
		printf("\n");
	}
	return 0;
}
