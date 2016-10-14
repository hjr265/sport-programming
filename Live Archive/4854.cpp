// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4854
// A Digital Satire of Digital Age
// implementation
// 
// 
// AC (2011-10-02 11:56:31)

#include <cstdio>
#include <cstring>
#include <string>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

const char *p[5] = {
	".../\\...",
	"../..\\..",
	"./....\\.",
	"/......\\",
	"\\______/"
};

int binweight(char x) {
	int r = 0;
	while(x > 0)
		r += (x&1)*250+250, x >>= 1;
	return r;
}

bool readpan(int w[], string g[]) {
	char s[100];
	int b[2];
	for(int i = 0; i < 8; ++i) {
		gets(s);
		int l = 0;
		bool t = false;
		for(int j = 0; s[j]; ++j) switch(s[j]) {
			case '/':
			case '\\':
				t = !t;
				continue;
			case '|':
				l = 1;
				continue;
			case '.':
				continue;
			case '_':
				b[l] = i;
				continue;
			default:
				if(t)
					w[l] += binweight(s[j]), g[l] += s[j];
				continue;
		}
	}
	return w[0] < w[1] && b[0] < b[1] || w[0] == w[1] && b[0] == b[1] && b[0] == 5 || w[0] > w[1] && b[0] > b[1];
}

void printpan(int w[2], string g[2]) {
	int t[2];
	if(w[0] < w[1])
		t[0] = 0, t[1] = 2;
	else if(w[0] > w[1])
		t[0] = 2, t[1] = 0;
	else
		t[0] = t[1] = 1;
	char o[10][20];
	CLR(o);
	for(int i = 0; i < 7; ++i)
		for(int j = 0; j < 18; ++j)
			o[i][j] = '.';
	for(int i = 0; i < 7; ++i)
		o[i][8] = o[i][9] = '|';
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 5; ++j)
			for(int k = 0; p[j][k]; ++k)
				o[j + t[i]][k+i*10] = p[j][k];
	for(int i = 0; i < 2; ++i)
		for(int j = 0, n = g[i].size(); j < n; ++j)
			o[t[i] + 3][j+1+i*10] = g[i][j];
	for(int i = 0; i < 7; ++i)
		printf("%s\n", o[i]);
}

int main() {
	int T, no = 1;
	scanf("%d\n", &T);
	while(T--) {
		int w[2] = {0};
		string g[2];
		bool o = readpan(w, g);
		printf("Case %d:\n", no++);
		if(o)
			printf("The figure is correct.\n");
		else
			printpan(w, g);
	}
	return 0;
}
