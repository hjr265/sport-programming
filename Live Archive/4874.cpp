// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4874
// Nim-B Sum
// implementation
// 
// 
// AC (2011-07-30 07:53:03)

#include <cstdio>

int ans(int B, int X, int Y) {
	int R = 0, i = 1;
	while(X > 0 || Y > 0) {
		R += (((X%B)+(Y%B))%B)*i;
		X /= B;
		Y /= B;
		i *= B;
	}
	return R;
}

int main() {
	int P;
	scanf("%d", &P);
	while(P--) {
		int t, B, X, Y;
		scanf("%d %d %d %d", &t, &B, &X, &Y);
		printf("%d %d\n", t, ans(B, X, Y));
	}
	return 0;
}
