// In the name of Allah, Most Gracious, Most Merciful

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long vlong;

vlong Imax = 0;
vector<vlong> L;

char ans(vlong N, int I) {
	if(I == 0)
		return N == 1 ? 'm' : 'o';
	vlong X = (L[I]-I-3)/2;
	if(N <= X)
		return ans(N, I-1);
	else if(N > (L[I]-I-3)/2+I+3)
		return ans(N-((L[I]-I-3)/2+I+3), I-1);
	else
		return N == (L[I]-I-3)/2+1 ? 'm' : 'o';
}

int main() {
	L.push_back(3);
	vlong N = 3, I = 1;
	while(N <= 1000000000LL) {
		N = N*2+I+3;
		L.push_back(N);
		++I;
	}
	Imax = I-1;
	cin >> N;
	cout << ans(N, Imax-1) << endl;
	return 0;
}
