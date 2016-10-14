// In the name of Allah, Most Gracious, Most Merciful

// Codeforces/Codeforces Round #127 (Div. 2)/B
// Brand New Easy Problem
// brute force, hashing
// http://codeforces.com/contest/202/problem/B
// 
// AC (01:12:56)

#include <algorithm>
#include <iostream>
#include <utility>

#define SLC(c, n) c, c+(n)

using namespace std;

string w[5];
int k[11];
string s[11][21];
int z[200];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> w[i];
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> k[i];
		for(int j = 0; j < k[i]; ++j)
			cin >> s[i][j];
	}
	pair<int, int> r(-1, 1<<28);
	int d[] = {0, 1, 2, 3};
	do {
		int x = 0;
		for(int i = 0; i < n; ++i) {
			//cout << w[d[i]] << " ";
			for(int j = i+1; j < n; ++j) if(d[j] < d[i]) {
				++x;
			}
		}
		//cout << x << endl;
		for(int l = 0; l < m; ++l) {
			bool f = false;
			for(int i = 0, j = 0; i < n && j < k[l]; ++j) if(w[d[i]] == s[l][j]) {
				++i;
				if(i == n) {
					f = true;
					break;
				}
			}
			int p = (n*(n-1))/2-x+1;
			if(f && (p > r.first || p == r.first && l < r.second))
				r = pair<int, int>(p, l);
		}
	} while(next_permutation(SLC(d, n)));
	//cout << n << " " << r.first << " " << r.second << endl;
	if(r.first == -1) {
		cout << "Brand new problem!" << endl;
	} else {
		cout << r.second+1 << endl;
		cout << "[:";
		for(int i = 0; i < r.first; ++i)
			cout << "|";
		cout << ":]" << endl;
	}
	return 0;
}
