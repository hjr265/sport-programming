// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/LINES
// Game of Lines
// implementation
// 
// 
// AC (2012-11-24 19:47:57)

#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

vector<pair<int, int> > P;

int main() {
	int N;
	while(scanf("%d", &N) == 1 && N != 0) {
		P.clear();
		for(int i = 0; i < N; ++i) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			P.push_back(pair<int, int>(X, Y));
		}
		
		vector<pair<int, int> > Fs;
		for(int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j) {
				pair<int, int> F(P[i].first-P[j].first, P[i].second-P[j].second);
				int G = gcd(abs(F.first), abs(F.second));
				F.first = F.first*F.second < 0 ? -abs(F.first)/G : abs(F.first)/G;
				F.second = abs(F.second)/G;
				Fs.push_back(F);
			}
		}
		
		sort(ALL(Fs));
		printf("%d\n", unique(ALL(Fs))-Fs.begin());
	}
	return 0;
}
