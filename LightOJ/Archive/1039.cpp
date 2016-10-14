// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1039
// A Toy Company
// dfs and similar
// 
// 
// AC (2012-01-27 10:06:43)

#include <cstring>
#include <iostream>
#include <queue>
#include <string>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

bool f[20000];
int d[20000];

int hash(const string &s) {
	return (s[0]-'a')*26*26+(s[1]-'a')*26+(s[2]-'a');
}

int bfs(const string &s, const string &t) {
	SET(d);
	queue<string> q;
	d[hash(s)] = 0;
	q.push(s);
	while(!q.empty()) {
		string u = q.front();
		q.pop();
		if(f[hash(u)])
			continue;
		if(u == t)
			return d[hash(u)];
		for(int i = 0; i < 3; ++i) {
			for(int j = -1; j <= 1; j += 2) {
				string v = u;
				v[i] = ((((v[i]-'a'+j)%26)+26)%26)+'a';
				if(d[hash(v)] == -1) {
					d[hash(v)] = d[hash(u)]+1;
					q.push(v);
				}
			}
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		int n;
		cin >> n;
		CLR(f);
		while(n--) {
			string a, b, c;
			cin >> a >> b >> c;
			for(int i = 0; i < a.size(); ++i)
				for(int j = 0; j < b.size(); ++j)
					for(int k = 0; k < c.size(); ++k)
						f[hash(a.substr(i, 1)+b.substr(j, 1)+c.substr(k, 1))] = true;
		}
		cout << "Case " << no++ << ": " << bfs(s, t) << '\n';
	}
	return 0;
}
