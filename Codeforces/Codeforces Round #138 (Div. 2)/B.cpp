// In the name of Allah, Most Gracious, Most Merciful

// Codeforces/Codeforces Round #138 (Div. 2)/B
// Array
// data structures, implementation, two pointers
// http://codeforces.com/contest/224/problem/B
// 
// AC (00:36:59)

#include <cstdio>
#include <cstring>

#define SET(c, v) memset(c, v, sizeof(c))

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

int A[100005], B[100005], C[100005];
Fwtree<int, 100005> FT;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	
	FT.clear();
	SET(C, -1);
	for(int i = n-1; i >= 0; --i) {
		if(C[A[i]] != -1)
			FT.add(C[A[i]], -1);
		FT.add(i, 1);
		B[i] = C[A[i]];
		C[A[i]] = i;
	}
	
	int l = -1, r = -1;
	for(int i = 0; i < n; ++i) if(FT.sum(i) == k) {
		r = i+1;
		
		for(int j = 0; j <= i; ++j) if(FT.sum(i) == k) {
			l = j+1;
			
			FT.add(j, -FT.sum(j)+FT.sum(j-1));
			if(B[j] != -1)
				FT.add(B[j], 1);
		}
		
		break;
	}
	
	printf("%d %d\n", l, r);
	return 0;
}
