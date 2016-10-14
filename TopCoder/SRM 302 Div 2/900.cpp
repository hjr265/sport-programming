// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 302 Div 2/900
// Divisor Inc
// dfs and similar
// http://community.topcoder.com/stat?c=problem_statement&pm=6186&rd=9823
// (DivisorInc) countOperations(int, int) int
// AC (896)

#include <cstring>
#include <queue>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

class DivisorInc {
	int D[100000+2];
	
public:
	int countOperations(int N, int M) {
		if(N == M)
			return 0;
		SET(D);
		queue<int> q;
		D[N] = 0;
		q.push(N);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i = 2; i*i <= u; ++i) if(u%i == 0) {
				int v = u+i;
				if(v <= 100000 && D[v] == -1) {
					D[v] = D[u]+1;
					if(v == M)
						return D[v];
					q.push(v);
				}
				v = u+u/i;
				if(v <= 100000 && D[v] == -1) {
					D[v] = D[u]+1;
					if(v == M)
						return D[v];
					q.push(v);
				}
			}
		}
		return -1;
	}
};

