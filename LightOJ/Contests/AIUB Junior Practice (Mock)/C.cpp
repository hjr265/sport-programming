// In the name of Allah, Most Gracious, Most Merciful

// LightOJ
// AIUB Junior Practice (Mock)
// C
// Prime Jargon
// implementation
// AC (1176)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

bool S[1000002];
vector<vlong> P;
vector<vlong> R[10][6];

void psieve() {
	CLR(S);
	P.push_back(2);
	for(vlong i = 3; i <= 1000000; i += 2) if(!S[i]) {
		P.push_back(i);
		for(vlong j = i*i; j <= 1000000; j += 2*i)
			S[j] = true;
	}
}

int main() {
	psieve();
	for(int i = 0; i < P.size(); ++i) {
		for(int a = 0; a < 10; ++a) {
			int x = P[i], b = 0;
			for(; x; x /= 10) if(x%10 == a)
				++b;
			if(b <= 5)
				R[a][b].push_back(P[i]);
		}
	}
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 6; ++j)
			sort(ALL(R[i][j]));
	}
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("Case %d: ", no++);
		if(c < R[a][b].size())
			printf("%lld\n", R[a][b][c]);
		else
			printf("Not Found!\n");
	}
	return 0;
}
