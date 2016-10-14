// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);

enum {
	
};

char PbX[][5] = {
	"0000",
	"0001",
	"0010",
	"0011",
	"0100",
	"0101",
	"0110",
	"0111",
	"1000",
	"1001",
	"1010",
	"1011",
	"1100",
	"1101",
	"1110",
	"1111",
};

map<string, int> MX;

int bin2int(string b) {
	int r = 0;
	for(int i = 0; i < b.size(); ++i)
		r *= 2, r += b[i]-'0';
	return r;
}

string Z = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

string int2hex(int Wv) {
	string R = "";
	R += Z[Wv/16];
	R += Z[Wv%16];
	return R;
}

string int8bit2char(string W, int Wv) {
	if(Wv >= 0x20 && Wv <= 0x7E) {
		string R = "";
		if(Wv == '\\')
			return "\\";
		if(Wv == '#')
			return "\\#";
		R += (char)Wv;
		return R;
	} else {
		string R = "\\";
		R += int2hex(Wv);
		return R;
	}
	return "!!";
}

string kanji2str(string K) {
	K = string("000")+K;
	string R = "";
	R += Z[bin2int(K.substr(0, 4))];
	R += Z[bin2int(K.substr(4, 4))];
	R += Z[bin2int(K.substr(8, 4))];
	R += Z[bin2int(K.substr(12, 4))];
	return R;
}

int main() {
	MX["0001"] = 1;
	MX["0010"] = 2;
	MX["0100"] = 3;
	MX["1000"] = 4;
	MX["0000"] = 5;
	int P;
	cin >> P;
	while(P--) {
		int N;
		string P;
		cin >> N >> P;
		string Pb = "";
		for(int i = 0; i < P.size(); ++i)
			Pb += PbX[P[i] >= 'A' ? P[i]-'A'+10 : P[i]-'0'];
		int V = 0;
		string R = "";
		while(Pb.size() >= 4) {
			string M = Pb.substr(0, 4), C;
			//cout << M << endl;
			int Cv;
			Pb = Pb.substr(4);
			switch(MX[M]) {
			case 1:
				C = Pb.substr(0, 10);
				Cv = bin2int(C);
				V += Cv;
				Pb = Pb.substr(10);
				while(Cv) {
					if(Cv >= 3) {
						string W = Pb.substr(0, 10);
						int Wv = bin2int(W);
						string Rt = "";
						for(int i = 0; i < 3; ++i)
							Rt += (Wv%10)+'0', Wv /= 10;
						reverse(ALL(Rt));
						R += Rt;
						Pb = Pb.substr(10);
						Cv -= 3;
					} else if(Cv == 2) {
						string W = Pb.substr(0, 7);
						int Wv = bin2int(W);
						string Rt = "";
						for(int i = 0; i < 2; ++i)
							Rt += (Wv%10)+'0', Wv /= 10;
						reverse(ALL(Rt));
						R += Rt;
						Pb = Pb.substr(7);
						Cv -= 2;
					} else if(Cv == 1) {
						string W = Pb.substr(0, 4);
						int Wv = bin2int(W);
						string Rt = "";
						for(int i = 0; i < 1; ++i)
							Rt += (Wv%10)+'0', Wv /= 10;
						reverse(ALL(Rt));
						R += Rt;
						Pb = Pb.substr(4);
						--Cv;
					}
				}
				break;
			case 2:
				C = Pb.substr(0, 9);
				Cv = bin2int(C);
				V += Cv;
				Pb = Pb.substr(9);
				while(Cv) {
					if(Cv >= 2) {
						string W = Pb.substr(0, 11);
						int Wv = bin2int(W);
						string Rt = "";
						for(int i = 0; i < 2; ++i)
							Rt += Z[Wv%45], Wv /= 45;
						reverse(ALL(Rt));
						R += Rt;
						Pb = Pb.substr(11);
						Cv -= 2;
					} else if(Cv == 1) {
						string W = Pb.substr(0, 6);
						int Wv = bin2int(W);
						string Rt = "";
						for(int i = 0; i < 1; ++i)
							Rt += Z[Wv%45], Wv /= 45;
						reverse(ALL(Rt));
						R += Rt;
						Pb = Pb.substr(6);
						--Cv;
					}
				}
				break;
			case 3:
				C = Pb.substr(0, 8);
				Cv = bin2int(C);
				V += Cv;
				Pb = Pb.substr(8);
				while(Cv--) {
					string W = Pb.substr(0, 8);
					int Wv = bin2int(W);
					string Rt = int8bit2char(W, Wv);
					R += Rt;
					Pb = Pb.substr(8);
				}
				break;
			case 4:
				C = Pb.substr(0, 8);
				Cv = bin2int(C);
				V += Cv;
				Pb = Pb.substr(8);
				while(Cv--) {
					string W = Pb.substr(0, 13);
					string Rt = "#";
					Rt += kanji2str(W);
					R += Rt;
					Pb = Pb.substr(13);
				}
				break;
			case 5:
				Pb = "";
				break;
			}
		}
		cout << N << " " << V << " " << R << endl;
	}
	return 0;
}
