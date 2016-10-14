// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/INCSEQ
// Increasing Subsequences
// data structures, trees
// 
// 
// AC (2012-10-19 11:02:26)

#include <cstdio>
#include <cstring>

#define SET(c, v) memset(c, v, sizeof(c))

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

int S[10002];
Fwtree<vlong, 100005> T[52];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &S[i]);
	
	T[0].add(0, 1);
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= K; ++j)
			T[j].add(S[i]+1, T[j-1].sum(S[i])%MOD);
	}
	
	printf("%lld\n", T[K].sum(100002)%MOD);
	return 0;
}
