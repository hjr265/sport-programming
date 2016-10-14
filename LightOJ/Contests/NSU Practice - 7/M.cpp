// In the name of Allah, Most Gracious, Most Merciful

// IP Checking
// math
// AC (55)

#include <cstdio>

void fix(int b[]) {
	for(int i = 0; i < 4; ++i) {
		int r = b[i], t = 0;
		b[i] = 0;
		for(; r; r /= 10, ++t)
			b[i] += (r%10)<<t;
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int a[4], b[4];
		scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
		scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);
		fix(b);
		bool p = true;
		for(int i = 0; i < 4; ++i) if(a[i] != b[i])
			p = false;
		printf("Case %d: %s\n", no++, p ? "Yes" : "No");
	}
	return 0;
}
