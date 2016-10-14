// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1079
// Just another Robbery
// dp, probabilities
// 
// 
// AC (2012-01-29 22:34:06)

#include <cstdio>
#include <algorithm>

using namespace std;

const double inf = 1e20;

double F[10002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double P;
		int N;
		scanf("%lf %d", &P, &N);
		for(int i = 0; i < 10002; ++i)
			F[i] = inf;
		F[0] = 0;
		for(int j = 0; j < N; ++j) {
			int Mj;
			double Pj;
			scanf("%d %lf", &Mj, &Pj);
			for(int i = 10000; i >= Mj; --i)
				F[i] = min(F[i-Mj]+(1-F[i-Mj])*Pj, F[i]);
		}
		for(int i = 10000; i >= 0; --i) if(F[i] <= P) {
			printf("Case %d: %d\n", no++, i);
			break;
		}
	}
	return 0;
}
