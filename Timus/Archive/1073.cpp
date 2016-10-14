// In the name of Allah, Most Gracious, Most Merciful

// Timus/1073
// Square Country
// dp
// 
// 
// AC (09:47:07 30 Apr 2012)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

int S[60005];

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		S[i] = 1<<28;
		for(int j = 1; j*j <= i; ++j)
			S[i] = min(S[i], S[i-j*j]+1);
	}
	printf("%d\n", S[N]);
	return 0;
}
