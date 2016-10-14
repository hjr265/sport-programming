// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1179
// Josephus Problem
// math
// 
// 
// AC (2012-03-12 01:55:24)

#include <cstdio>

int last(int n, int k) {
	if(n == 1)
		return 1;
	int t = (last(n-1, k)+k)%n;
	return t ? t : n;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("Case %d: %d\n", no++, last(n, k));
	}
	return 0;
}
