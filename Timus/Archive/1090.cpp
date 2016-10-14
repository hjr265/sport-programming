// In the name of Allah, Most Gracious, Most Merciful

// Timus/1090
// In the Army Now
// data structures, trees
// 
// 
// AC (12:16:20 16 Oct 2012)

#include <cstdio>
#include <cstring>
#include <utility>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

template<class T, int n>
class Fwtree {
	T v[n+5];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(v, 0);
	}
	
	void add(int i, T x) {
		++i;
		while(i < n+5)
			v[i] += x, i += i & -i;
	}
	
	T sum(int i) {
		++i;
		T r = 0;
		while(i > 0)
			r += v[i], i -= i & -i;
		return r;
	}
};

Fwtree<int, 10005> F;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	pair<int, int> R(-1, 0);
	for(int i = 1; i <= K; ++i) {
		F.clear();
		int r = 0;
		for(int j = 0; j < N; ++j) {
			int x;
			scanf("%d", &x);
			r += F.sum(N-x);
			F.add(N-x, 1);
		}
		if(r > R.first)
			R = pair<int, int>(r, i);
	}
	printf("%d\n", R.second);
	return 0;
}
