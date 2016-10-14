// In the name of Allah, Most Gracious, Most Merciful

// Timus/1100
// Final Standings
// sortings
// 
// 
// AC (17:57:16 15 Oct 2012)

#include <cstdio>
#include <vector>

using namespace std;

vector<int> X[102];

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
		int ID, M;
		scanf("%d %d", &ID, &M);
		
		X[M].push_back(ID);
	}
	
	for(int i = 100; i >= 0; --i) {
		for(int j = 0; j < X[i].size(); ++j)
			printf("%d %d\n", X[i][j], i);
	}
	return 0;
}
