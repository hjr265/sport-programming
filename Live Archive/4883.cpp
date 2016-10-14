// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4883
// Ropes
// implementation
// 
// 
// AC (2011-08-09 10:43:36)

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N;
	while(scanf("%d", &N) == 1 && N != 0) {
		int P[N];
		for(int i = 0; i < N; ++i)
			scanf("%d", &P[i]);
		int Pmax = P[0], Psum = P[0];
		for(int i = 1; i < N; ++i) {
			Pmax = max(Pmax, P[i]);
			Psum += P[i];
		}
		int r[] = {50, 60, 70};
		for(int i = 0; i < 3; ++i) {
			int z = 0;
			if(i != 0)
				printf(" ");
			if(r[i] >= Psum*2)
				z = r[i]/Pmax+1;
			printf("%d", z);
		}
		printf("\n");
	}
	return 0;
}
