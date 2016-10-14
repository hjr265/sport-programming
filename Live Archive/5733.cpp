// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5733
// Iterated Difference
// implementation
// 
// 
// AC (2012-01-21 12:09:32)

#include <cstdio>
#include <cmath>

using namespace std;

int N;
int A[22];

void step() {
	int T[22];
	for(int i = 0; i < N; ++i)
		T[i] = abs(A[i]-A[(i+1)%N]);
	for(int i = 0; i < N; ++i)
		A[i] = T[i];
}

bool done() {
	for(int i = 0; i < N; ++i) if(A[0] != A[i])
		return false;
	return true;
}

int main() {
	int no = 1;
	while(scanf("%d", &N) == 1 && N != 0) {
		for(int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		printf("Case %d: ", no++);
		for(int i = 0; i <= 1000; ++i) {
			if(done()) {
				printf("%d iterations\n", i);
				break;
			} else if(i == 1000) {
				printf("not attained\n");
				break;
			}
			step();
		}
	}
	return 0;
}
