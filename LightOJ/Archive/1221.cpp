// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1221
// Travel Company
// shortest paths
// 
// 
// AC (2012-05-03 11:05:09)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+n

using namespace std;

int N;
int D[102][102];

bool floydwarshall() {
	for(int i = 0; i < 102; ++i)
		D[i][i] = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < N; ++k)
				D[j][k] = max(D[j][k], D[j][i]+D[i][k]);
		}
	}
	for(int i = 0; i < N; ++i) if(D[i][i] > 0)
		return true;
	return false;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int R, P;
		scanf("%d %d %d", &N, &R, &P);
		for(int i = 0; i < 102; ++i)
			fill(SLC(D[i], 102), -(1<<28));
		while(R--) {
			int A, B, I, E;
			scanf("%d %d %d %d", &A, &B, &I, &E);
			D[A][B] = I-E*P;
		}
		printf("Case %d: %s\n", no++, floydwarshall() ? "YES" : "NO");
	}
	return 0;
}
