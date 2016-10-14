// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1414
// February 29
// math
// 
// 
// AC (2012-02-27 15:50:37)

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long vlong;

map<string, int> M;

vlong divs(vlong l, vlong h, vlong d) {
	return h/d-(l-1)/d;
}

bool leap(vlong y) {
	return y%4 == 0 && (y%100 != 0 || y%400 == 0);
}

int main() {
	M["January"] = 1;
	M["February"] = 2;
	M["March"] = 3;
	M["April"] = 4;
	M["May"] = 5;
	M["June"] = 6;
	M["July"] = 7;
	M["August"] = 8;
	M["September"] = 9;
	M["October"] = 10;
	M["November"] = 11;
	M["December"] = 12;
	int T, no = 1;
	cin >> T;
	while(T--) {
		string ml, mh, g_;
		vlong dl, dh, yl, yh;
		cin >> ml >> dl >> g_ >> yl;
		cin >> mh >> dh >> g_ >> yh;
		vlong r = divs(yl, yh, 4)-divs(yl, yh, 100)+divs(yl, yh, 400);
		if(leap(yl) && M[ml] > 2)
			--r;
		if(leap(yh) && (M[mh] == 2 && dh < 29 || M[mh] < 2))
			--r;
		cout << "Case " << no++ << ": " << r << endl;
	}
	return 0;
}
