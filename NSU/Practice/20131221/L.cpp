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

map<string, string> M[2];
set<string> Ks[2];
vector<string> K;
vector<string> R[3];
char S[105];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		M[0].clear();
		M[1].clear();

		Ks[0].clear();
		Ks[1].clear();
		K.clear();
		
		R[0].clear();
		R[1].clear();
		R[2].clear();
	
		int m = 0;
		for(int j = 0; j < 2; ++j) {
			scanf("%s", S);
			string k, v;
			for(int i = 0; S[i]; ++i) switch(S[i]) {
				case '{':
					m = 1;
					k = "";
					break;
				case '}':
					if(k.size() == 0) {
						break;
					}
				case ',':
					M[j].insert(pair<string, string>(k, v));
					if(Ks[0].count(k) == 0 && Ks[1].count(k) == 0) {
						K.push_back(k);
					}
					Ks[j].insert(k);
					m = 1;
					k = "";
					break;
				case ':':
					m = 2;
					v = "";
					break;
				default:
					if(m == 1) {
						k += S[i];
					}
					if(m == 2) {
						v += S[i];
					}
					break;
			}
		}
		
		sort(ALL(K));
		
		for(int i = 0; i < K.size(); ++i) if(Ks[0].count(K[i]) == 0 && Ks[1].count(K[i]) > 0) {
			R[0].push_back(K[i]);
		} else if(Ks[0].count(K[i]) > 0 && Ks[1].count(K[i]) == 0) {
			R[1].push_back(K[i]);
		} else if(M[0][K[i]] != M[1][K[i]]) {
			R[2].push_back(K[i]);
		}
		
		if(R[0].size() > 0) {
			for(int i = 0, l = R[0].size(); i < l; ++i) {
				if(i == 0) {
					printf("+");
				} else {
					printf(",");
				}
				printf("%s", R[0][i].c_str());
			}
			printf("\n");
		}
		if(R[1].size() > 0) {
			for(int i = 0, l = R[1].size(); i < l; ++i) {
				if(i == 0) {
					printf("-");
				} else {
					printf(",");
				}
				printf("%s", R[1][i].c_str());
			}
			printf("\n");
		}
		if(R[2].size() > 0) {
			for(int i = 0, l = R[2].size(); i < l; ++i) {
				if(i == 0) {
					printf("*");
				} else {
					printf(",");
				}
				printf("%s", R[2][i].c_str());
			}
			printf("\n");
		}
		if(R[0].size() == 0 && R[1].size() == 0 && R[2].size() == 0) {
			printf("No changes\n");
		}
		
		printf("\n");
	}
	return 0;
}
