// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5971
// Permutation Counting
// combinatorics
// 
// 
// AC (2012-09-11 10:57:43)

#include <iostream>

using namespace std;

typedef long long vlong;

const vlong MOD = 1000000007;

vlong Z[1000006];

int main() {
	Z[1] = Z[2] = 1;
	for(int i = 3; i <= 1000000; ++i)
		Z[i] = (((Z[i-1]*(i-1))%MOD) + ((Z[i-2]*(i-2))%MOD))%MOD;
	
	int T, no = 1;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		cout << "Case " << no++ << ": " << Z[N] << endl;
	}
	return 0;
}
