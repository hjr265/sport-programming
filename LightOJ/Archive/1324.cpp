// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1324
// Equivalent Boolean Expressions
// brute force, parsing
// 
// 
// AC (2012-05-15 02:28:34)

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string in2post(string S) {
	stack<char> k;
	string r = "";
	bool c = false;
	for(int i = 0; i < S.size(); ++i) {
		if(S[i] >= 'a' && S[i] <= 'j') {
			r += S[i];
			while(!k.empty() && k.top() == '!') {
				r += '!';
				k.pop();
			}
		} else if(S[i] == '!') {
			k.push('!');
		} else if(S[i] == '(') {
			k.push('(');
		} else if(S[i] == ')') {
			while(k.top() != '(') {
				r += k.top();
				k.pop();
			}
			k.pop();
			while(!k.empty() && k.top() == '!') {
				r += '!';
				k.pop();
			}
		} else if(k.empty()) {
			k.push(S[i]);
		} else {
			while(!k.empty() && k.top() == '&') {
				r += '&';
				k.pop();
			}
			k.push(S[i]);
		}
	}
	while(!k.empty()) {
		r += k.top();
		k.pop();
	}
	return r;
}

int eval(string S, int v) {
	stack<char> k;
	for(int i = 0; i < S.size(); ++i) {
		if(S[i] >= 'a' && S[i] <= 'j') {
			k.push((v>>(S[i]-'a'))&1);
		} else if(S[i] >= 'A' && S[i] <= 'J') {
			k.push(((v>>(S[i]-'a'))&1)^1);
		} else if(S[i] == '!') {
			int a = k.top();
			k.pop();
			k.push(a^1);
		} else {
			int a = k.top();
			k.pop();
			int b = k.top();
			k.pop();
			if(S[i] == '&')
				k.push(a&b);
			else
				k.push(a|b);
		}
	}
	return k.top();
}

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		string a, b;
		cin >> a;
		a = in2post(a);
		cin >> b;
		b = in2post(b);
		bool r = true;
		for(int i = 0; i < 1<<10; ++i) if(eval(a, i) != eval(b, i)) {
			r = false;
			break;
		}
		printf("Case %d: %s\n", no++, r ? "Equivalent" : "Not Equivalent");
	}
	return 0;
}
