// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/INCDSEQ
// Distinct Increasing Subsequences
// data structures, trees
// 
// 
// AC (2012-10-19 11:14:19)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

const vlong MOD = 5000000;

enum {
	
};

template<class T, int N>
class Fwtree {
	T t[N+2];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(t, 0);
	}
	
	void add(int i, T x) {
		++i;
		while(i < N+2)
			t[i] += x, i += i&-i;
	}
	
	T sum(int i) {
		++i;
		T r = 0;
		while(i)
			r += t[i], i -= i&-i;
		return r;
	}
};

vlong S[10002];
vector<vlong> Ss;
Fwtree<vlong, 100005> T[52];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; ++i) {
		scanf("%lld", &S[i]);
		Ss.push_back(S[i]);
	}
	sort(ALL(Ss));
	
	T[0].add(0, 1);
	for(int i = 1; i <= N; ++i) {
		int Si = lower_bound(ALL(Ss), S[i])-Ss.begin();
		for(int j = 1; j <= K; ++j)
			T[j].add(Si+1, (-(T[j].sum(Si+1)-T[j].sum(Si))+T[j-1].sum(Si))%MOD);
	}
	
	printf("%lld\n", (T[K].sum(100003)%MOD+MOD)%MOD);
	return 0;
}
