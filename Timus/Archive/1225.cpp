// In the name of Allah, Most Gracious, Most Merciful

// Timus/1225
// Flags
// dp
// 
// 
// AC (19:18:19 29 Apr 2012)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

typedef long long vlong;

vlong M[50][5];

vlong dp(int N, int i, int j) {
	if(i == N)
		return 1;
	if(i > N)
		return 0;
	vlong &r = M[i][j];
	if(r == -1) {
		r = 0;
		switch(j) {
		case 0:
			r = dp(N, i+1, 1)+dp(N, i+1, 3);
			break;
		case 1:
			r = dp(N, i+1, 3)+dp(N, i+2, 3);
			break;
		case 3:
			r = dp(N, i+1, 1)+dp(N, i+2, 1);
			break;
		}
	}
	return r;
}

int main() {
	int N;
	scanf("%d", &N);
	SET(M);
	printf("%lld\n", dp(N, 0, 0));
	return 0;
}
