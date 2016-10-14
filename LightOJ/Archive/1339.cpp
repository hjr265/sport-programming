// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1339
// Strongest Community
// trees
// 
// 
// AC (2011-11-11 17:17:31)

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct Segtree {
	int *a, *t, l;
	
	Segtree(int a_[], int l_) : a(a_), l(l_)  {
		int n = 1<<int(ceil(log(l)/log(2)+1));
		t = new int[n];
		memset(t, -1, sizeof(int)*n);
		init(1, 0, l-1);
	}
	
	~Segtree() {
		delete[] t;
	}
	
	void init(int n, int l, int r) {
		if(l == r) {
			t[n] = l;
			return;
		}
		init(2*n, l, (l+r)/2);
		init(2*n+1, (l+r)/2+1, r);
		if(a[t[2*n]] >= a[t[2*n+1]])
			t[n] = t[2*n];
		else
			t[n] = t[2*n+1];
	}
	
	int query(int i, int j) {
		return query(i, j, 1, 0, l-1);
	}
	
	int query(int i, int j, int n, int l, int r) {
		if(i > r || j < l)
			return -1;
		if(i <= l && j >= r)
			return t[n];
		int x = query(i, j, 2*n, l, (l+r)/2),
			y = query(i, j, 2*n+1, (l+r)/2+1, r);
		if(x == -1)
			return y;
		if(y == -1)
			return x;
		if(a[x] >= a[y])
			return x;
		else
			return y;
	}
};

int A[100005];
int F[100005];
int L[100005];
int R[100005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, c, q;
		scanf("%d %d %d", &n, &c, &q);
		for(int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; ) {
			int f = 1;
			for(int j = i+1; j < n && A[i] == A[j]; ++j)
				++f;
			for(int j = i; j-i < f; ++j)
				F[j] = f;
			i += f;
		}
		L[0] = 0;
		for(int i = 0; i < n; ++i)
			L[i] = (A[i] == A[i-1] ? L[i-1] : i);
		R[n-1] = n-1;
		for(int i = n-2; i >= 0; --i)
			R[i] = (A[i] == A[i+1] ? R[i+1] : i);
		Segtree t(F, n);
		printf("Case %d:\n", no++);
		while(q--) {
			int i, j;
			scanf("%d %d", &i, &j);
			i -= 1;
			j -= 1;
			int l = R[i]+1, r = L[j]-1;
			int m = (l <= r ? F[t.query(l, r)] : 0),
				p = (R[i] < j ? R[i]-i+1 : j-i+1),
				q = (L[j] > i ? j-L[j]+1 : j-i+1);
			printf("%d\n", max(m, max(p, q)));
		}
	}
	return 0;
}
