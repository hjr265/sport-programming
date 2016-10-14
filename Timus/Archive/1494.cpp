// In the name of Allah, Most Gracious, Most Merciful

// Timus/1494
// Monobilliards
// data structures
// 
// 
// AC (12:04:29 16 Oct 2012)

#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int C = 0;
	stack<int> K;
	bool F = false;
	while(N--) {
		int X;
		scanf("%d", &X);
		if(X > C) {
			for(int i = C+1; i <= X; ++i)
				K.push(i);
			C = X;
		}
		if(K.empty() || K.top() != X)
			F = true;
		K.pop();
	}
	printf("%s\n", F ? "Cheater" : "Not a proof");
	return 0;
}
