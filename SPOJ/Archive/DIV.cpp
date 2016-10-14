// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/DIV
// Divisors
// number theory
// 
// 
// AC (2012-11-25 07:08:27)

#include <cstdio>
#include <vector>

using namespace std;

int S[1000005];
int Q[1000005];

void ssieve() {
	for(int i = 1; i <= 1000000; ++i)
		S[i] = 1;
	for(int i = 2; i <= 1000000; ++i) if(S[i] == 1) {
		for(int j = i; j <= 1000000; j += i) {
			int k = 0, x = j;
			while(x%i == 0)
				++k, x /= i;
			S[j] *= k+1;
			if(k == 1)
				++Q[j];
			else if(k > 1)
				Q[j] = 10;
		}
	}
}

int main() {
	ssieve();
	
	vector<int> R;
	for(int i = 1; i <= 1000000; ++i) if(Q[S[i]] == 2)
		R.push_back(i);
	
	for(int i = 0; i < R.size(); ++i) if(i%9 == 8)
		printf("%d\n", R[i]);
	return 0;
}
