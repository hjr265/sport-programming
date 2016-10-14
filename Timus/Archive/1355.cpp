// In the name of Allah, Most Gracious, Most Merciful

// Timus/1355
// Bald Spot Revisited
// number theory
// 
// 
// AC (23:25:10 24 Nov 2012)

#include <cstdio>
#include <cstring>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

bool S[40000];
vector<int> P;

void psieve() {
	P.push_back(2);
	SET(S, 0);
	for(int i = 3; i < 40000; i += 2) if(!S[i]) {
		P.push_back(i);
		for(int j = i*i; j < 40000; j += 2*i)
			S[j] = true;
	}
}

int main() {
	psieve();
	
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		int z = 0;
		if(b%a == 0) {
			++z;
			b = b/a;
			for(int i = 0; i < P.size(); ++i) while(b%P[i] == 0)
				++z, b /= P[i];
			if(b > 1)
				++z;
		}
		
		printf("%d\n", z);
	}
	return 0;
}
