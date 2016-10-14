// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1188
// Fast Queries
// trees
// 
// 
// AC (2012-09-15 11:04:55)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define ALL(c) c.begin(), c.end()

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

struct Query {
	int i, j, k;
	int r;
	
	bool operator<(const Query &r) const {
		return i < r.i;
	}
};

int A[100005], B[100005], C[100005];
Fwtree<int, 100005> FT;
vector<Query> Q;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, q;
		scanf("%d %d", &N, &q);
		for(int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		
		FT.clear();
		SET(C, -1);
		for(int i = N-1; i >= 0; --i) {
			if(C[A[i]] != -1)
				FT.add(C[A[i]], -1);
			FT.add(i, 1);
			B[i] = C[A[i]];
			C[A[i]] = i;
		}
		
		Q.clear();
		for(int k = 0; k < q; ++k) {
			Query q;
			scanf("%d %d", &q.i, &q.j);
			--q.i, --q.j;
			q.k = k;
			Q.push_back(q);
		}
		
		sort(ALL(Q));
		int l = 0;
		for(int i = 0; i < Q.size(); ++i) {
			if(l < Q[i].i) {
				for(int j = l; j < Q[i].i; ++j) {
					FT.add(j, -FT.sum(j)+FT.sum(j-1));
					if(B[j] != -1)
						FT.add(B[j], 1);
				}
				l = Q[i].i;
			}
			
			Q[i].r = FT.sum(Q[i].j)-FT.sum(Q[i].i-1);
			
			swap(Q[i].k, Q[i].i);
		}
		sort(ALL(Q));
		
		printf("Case %d:\n", no++);
		for(int i = 0; i < Q.size(); ++i)
			printf("%d\n", Q[i].r);
	}
	return 0;
}
