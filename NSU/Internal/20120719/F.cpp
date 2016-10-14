// In the name of Allah, Most Gracious, Most Merciful

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

struct Cow {
	vlong x;
	bool k;
	int i;
	
	Cow(vlong x_, bool k_, int i_) : x(x_), k(k_), i(i_) {}
	
	bool operator<(const Cow &r) const {
		return x < r.x;
	}
};
	
vector<Cow> Cs;
bool T[50005];

int main() {
	int N, K;
	vlong M;
	cin >> N >> K >> M;
	for(int i = 0; i < N; ++i) {
		vlong P_i, C_i;
		cin >> P_i >> C_i;
		Cs.push_back(Cow(P_i, false, i));
		Cs.push_back(Cow(C_i, true, i));
	}
	sort(ALL(Cs));
	SET(T, 0);
	int Z = 0;
	for(int i = 0; i < Cs.size(); ++i) {
		cout << Cs[i].x << endl;
		if(M >= Cs[i].x && (K > 0 || !Cs[i].k) && !T[Cs[i].i]) {
			M -= Cs[i].x;
			if(Cs[i].k)
				--K;
			T[Cs[i].i] = true;
			++Z;
		}
	}
	cout << Z << endl;
	return 0;
}
