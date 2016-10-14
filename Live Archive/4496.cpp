// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4496
// A Match Making Problem
// implementation
// 
// 
// AC (2011-10-02 13:51:06)

#include <cstdio>
#include <algorithm>

using namespace std;

int X[10005], Y[10005];

int main() {
	int no = 1, B, S;
	while(scanf("%d %d", &B, &S) == 2 && (B != 0 || S != 0)) {
		int z = 1234567890;
		for(int i = 0; i < B; z = min(z, X[i]), ++i)
			scanf("%d", &X[i]);
		for(int i = 0; i < S; ++i)
			scanf("%d", &Y[i]);
		printf("Case %d: ", no++);
		if(B <= S)
			printf("0");
		else
			printf("%d %d", B-S, z);
		printf("\n");
	}
}
