// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1075
// Finding Routes
// sortings
// 
// 
// AC (2012-02-03 18:56:12)

#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<string> n;
map<string, int> d;
vector<int> e[335];
int g[335];
bool c[335];
vector<int> r;

void dfs(int u) {
	if(c[u])
		return;
	c[u] = true;
	for(int i = 0; i < e[u].size(); ++i)
		dfs(e[u][i]);
	r.push_back(u);
}

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		int S;
		cin >> S;
		n.clear();
		d.clear();
		for(int u = 1; u <= S; ++u)
			e[u].clear();
		CLR(g);
		for(int i = 0; i < S-1; ++i) {
			string u, v;
			cin >> u >> v;
			if(d[u] == 0) {
				d[u] = n.size()+1;
				n.push_back(u);
			}
			if(d[v] == 0) {
				d[v] = n.size()+1;
				n.push_back(v);
			}
			e[d[u]].push_back(d[v]);
			++g[d[v]];
		}
		CLR(c);
		r.clear();
		for(int u = 1; u <= n.size(); ++u) if(g[u] == 0) {
			dfs(u);
			break;
		}
		cout << "Case " << no++ << ":\n";
		for(int i = r.size()-1; i >= 0; --i) {
			cout << n[r[i]-1] << "\n";
		}
		cout << "\n";
	}
	return 0;
}
