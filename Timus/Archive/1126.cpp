// In the name of Allah, Most Gracious, Most Merciful

// Timus/1126
// Magnetic Storms
// data structures
// 
// 
// AC (18:26:35 15 Oct 2012)

#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main() {
	int M;
	scanf("%d", &M);
	
	multiset<int> X;
	queue<int> Y;
	int N;
	while(scanf("%d", &N) == 1 && N != -1) {
		X.insert(-N);
		Y.push(N);
		if(X.size() == M) {
			printf("%d\n", -(*X.begin()));
			X.erase(X.find(-Y.front()));
			Y.pop();
		}
	}
	return 0;
}
