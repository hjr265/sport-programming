// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1309
// Children's Math
// implementation, parsing
// 
// 
// AC (2012-05-15 18:42:01)

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long vlong;

struct Expr {
	vlong a, b;
	
	Expr(vlong a_, vlong b_) : a(a_), b(b_) {}
	
	Expr(string v) {
		if(v == "x") {
			a = 1, b = 0;
		} else {
			a = 0;
			sscanf(v.c_str(), "%lld", &b);
		}
	}
	
	Expr operator*(const Expr &r) const {
		if(a == 0) {
			return Expr(b*r.a, b*r.b);
		}
		return Expr(r.b*a, r.b*b);
	}
	
	Expr operator+(const Expr &r) const {
		return Expr(a+r.a, b+r.b);
	}
	
	Expr operator-(const Expr &r) const {
		return Expr(a-r.a, b-r.b);
	}
};

string E;
vector<string> L, R;

bool cmpoper(char a, char b) {
	switch(a) {
	case '*':
		return true;
	case '-':
		return b != '*';
	case '+':
		return b != '*' && b != '-';
	}
	return false;
}

void in2post(const string &S, vector<string> &R) {
	stack<char> k;
	for(int i = 0; i < S.size(); ++i) {
		if(S[i] >= '0' && S[i] <= '9') {
			string x = "";
			for(int j = i; j < S.size() && S[j] >= '0' && S[j] <= '9'; ++j, i = j-1)
				x += S[j];
			R.push_back(x);
		} else if(S[i] == 'x') {
			R.push_back("x");
		} else if(S[i] == '(') {
			k.push('(');
		} else if(S[i] == ')') {
			while(k.top() != '(') {
				string x = "";
				x += k.top();
				R.push_back(x);
				k.pop();
			}
			k.pop();
		} else if(k.empty()) {
			k.push(S[i]);
		} else {
			while(!k.empty() && cmpoper(k.top(), S[i])) {
				string x = "";
				x += k.top();
				R.push_back(x);
				k.pop();
			}
			k.push(S[i]);
		}
	}
	while(!k.empty()) {
		string x = "";
		x += k.top();
		R.push_back(x);
		k.pop();
	}
}

Expr eval(const vector<string> S) {
	stack<Expr> k;
	for(int i = 0; i < S.size(); ++i) {
		if(S[i] == "x" || S[i][0] >= '0' && S[i][0] <= '9') {
			k.push(Expr(S[i]));
		} else {
			Expr a = k.top();
			k.pop();
			Expr b = k.top();
			k.pop();
			switch(S[i][0]) {
			case '*':
				k.push(b*a);
				break;
			case '+':
				k.push(b+a);
				break;
			case '-':
				k.push(b-a);
				break;
			}
		}
	}
	return k.top();
}

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		cin >> E;
		L.clear();
		R.clear();
		for(int i = 0; i < E.size(); ++i) if(E[i] == '=') {
			in2post(E.substr(0, i), L);
			in2post(E.substr(i+1, E.size()-i-1), R);
			break;
		}
		Expr a = eval(L), b = eval(R);
		vlong n = b.b-a.b, d = a.a-b.a, g = gcd(abs(n), abs(d));
		printf("Case %d: ", no++);
		if(d == 0 && n == 0) {
			printf("infinitely many solutions\n");
		} else if(d == 0) {
			printf("no solution\n");
		} else {
			n /= g;
			d /= g;
			if(d < 0)
				n *= -1, d *= -1;
			if(d == 1) {
				printf("%lld\n", n);
			} else {
				printf("%lld/%lld\n", n, d);
			}
		}
	}
	return 0;
}
