// In the name of Allah, Most Gracious, Most Merciful

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

struct Gift {
	vlong P, S;
	
	bool operator<(const Gift &r) const {
		return P+S < r.P+r.S;
	}
};

vector<Gift> G;

int main() {
	int N, B;
	cin >> N >> B;
	for(int i = 0; i < N; ++i) {
		Gift x;
		cin >> x.P >> x.S;
		G.push_back(x);
	}
	sort(ALL(G));
	int i = 0;
	while(B >= G[i].P+G[i].S) {
		B -= G[i].P+G[i].S;
		++i;
	}
	vlong m = 0;
	for(int j = 0; j < i; ++j)
		m = max(m, G[j].P);
	for(int j = 0; j < i; ++j) if(G[j].P == m) {
		B += G[j].P/2;
		break;
	}
	while(B >= G[i].P+G[i].S) {
		B -= G[i].P+G[i].S;
		++i;
	}
	cout << i << endl;
	return 0;
}
