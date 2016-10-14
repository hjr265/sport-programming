// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4493
// That is Your Queue
// data structures
// 
// 
// AC (2011-10-02 14:42:02)

#include <cstdio>
#include <list>

using namespace std;

typedef long long vlong;

int main() {
	int no = 1;
	vlong P, C;
	while(scanf("%lld %lld", &P, &C) == 2 && (P != 0 || C != 0)) {
		printf("Case %d:\n", no++);
		list<int> q;
		for(int i = 1; i <= P && i <= 1000; ++i)
			q.push_back(i);
		while(C--) {
			char d[5];
			scanf("%s", d);
			int x;
			switch(d[0]) {
				case 'N':
					x = q.front();
					printf("%d\n", x);
					q.pop_front();
					q.push_back(x);
					break;
				case 'E':
					scanf("%d", &x);
					q.remove(x);
					q.push_front(x);
					break;
			}
		}
	}
	return 0;
}
