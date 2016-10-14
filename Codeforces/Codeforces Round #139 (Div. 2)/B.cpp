// In the name of Allah, Most Gracious, Most Merciful

// Codeforces/Codeforces Round #139 (Div. 2)/B
// Well-known Numbers
// greedy
// http://codeforces.com/contest/225/problem/B
// 
// AC (00:22:39)

#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

vlong F[100];

int main() {
	vlong s, k;
	cin >> s >> k;
	
	int l = 2;
	F[0] = 0;
	F[1] = 1;
	vlong r = 1;
	for(int i = 2; i < k; ++i, ++l) {
		F[i] = r, r += F[i];
		if(F[i] > 1000000000LL)
			break;
	}
	for(int i = k; i < 100; ++i, ++l) {
		F[i] = r, r += F[i]-F[i-k];
		if(F[i] > 1000000000LL)
			break;
	}
	
	vector<vlong> z;
	for(int i = l-1; s > 0; --i) if(s >= F[i]) {
		z.push_back(F[i]);
		s -= F[i];
	}
	
	cout << z.size()+1 << endl;
	sort(ALL(z));
	cout << "0";
	for(int i = 0; i < z.size(); ++i)
		cout << " " << z[i];
	cout << endl;
	return 0;
}
