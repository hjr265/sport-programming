// In the name of Allah, Most Gracious, Most Merciful

// Timus/1005
// Stone Pile
// dp
// 
// 
// AC (19:09:12 28 Apr 2012)

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define CLR(c) memset(c, 0, sizeof(c))

bool S[1000005];

int main() {
	int N;
	scanf("%d", &N);
	CLR(S);
	S[0] = true;
	int T = 0, R = 1<<28;
	while(N--) {
		int Wi;
		scanf("%d", &Wi);
		T += Wi;
		for(int j = min(T, 1000000); j >= 0; --j) if(S[j] && j+Wi <= 1000000) {
			S[j+Wi] = true;
			if(N == 0)
				R = min(R, abs(T-2*(j+Wi)));
		}
	}
	printf("%d\n", R);
	return 0;
}
