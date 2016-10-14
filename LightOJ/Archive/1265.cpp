// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1265
// Island of Survival
// probabilities
// 
// 
// AC (2012-05-09 17:09:02)

#include <cstdio>

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int t, d;
		scanf("%d %d", &t, &d);
		printf("Case %d: %0.6lf\n", no++, t%2 == 0 ? 1/(double)(t+1) : 0);
	}
	return 0;
}
