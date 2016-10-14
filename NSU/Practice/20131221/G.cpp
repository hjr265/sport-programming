// In the name of Allah, Most Gracious, Most Merciful

// Disjoint Sets
// data structures

#include <cstdio>
#include <cstring>
#include <map>
#include <string>


#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

template<int N>
class Dsets {
	int p[N], r[N];
	
public:
	Dsets() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			p[i] = i;
		SET(r, 0);
	}
	
	int parent(int a) {
		if(p[a] != a)
			p[a] = parent(p[a]);
		return p[a];
	}
	
	void merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(r[a] > r[b])
			p[b] = a;
		else
			p[a] = b;
		if(r[a] == r[b])
			++r[b];
	}
};

map<string, int> M;
Dsets<100005> D;
int R[100005];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		M.clear();
		D.clear();
		for(int i = 0; i < 100005; ++i) {
			R[i] = 1;
		}
		
		int F;
		scanf("%d", &F);
		
		while(F--) {
			char A[25], B[25];
			scanf("%s %s", A, B);
			
			string As(A), Bs(B);
			
			if(!M[As]) {
				M[As] = M.size()+1;
			}
			if(!M[Bs]) {
				M[Bs] = M.size()+1;
			}
			
			int Ap = D.parent(M[As]),
				Bp = D.parent(M[Bs]);
			if(Ap != Bp) {
				D.merge(M[As], M[Bs]);
				
				int Tp = D.parent(M[As]);
				R[Tp] = R[Ap] + R[Bp];
			}
			
			
			printf("%d\n", R[D.parent(M[As])]);
		}
	}
	return 0;
}
