// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// ??

#include <cstdio>
#include <cstring>

int A[100005];
int T[4*100005];
int D[4*100005];
int P[1000006];

void fix(int u, int a, int b) {
	if(D[u]) {
		if(P[D[u]] == 1) {
			T[u] = b-a+1;
		} else {
			T[u] = 0;
		}
		if(a != b) {
			D[u*2] = D[u];
			D[u*2+1] = D[u];
		}
		D[u] = 0;
	}
}

void set(int u, int a, int b, int i, int j, int v) {
	if(a > b || a > j || b < i) {
		fix(u, a, b);
		return;
	}
	if(a >= i && b <= j) {
		D[u] = v;
		fix(u, a, b);
		return;
	}
	fix(u, a, b);
	set(u*2, a, (a+b)/2, i, j, v);
	set(u*2+1, (a+b)/2+1, b, i, j, v);
	if(a != b) {
		T[u] = T[u * 2] + T[u * 2 + 1];
	}
}

int sum( int u, int a, int b, int i, int j) {
	if(a > b || a > j || b < i) {
		return 0;
	}
	fix(u, a, b);
	if(a >= i && b <= j) {
		return T[u];
	}
	return sum(u*2, a, (a+b)/2, i, j) + sum(u*2+1, (a+b)/2+1, b, i, j);
}

void make(int u, int i, int j) {
	if(i == j) {
		if(P[A[i]] == 1) {
			T[u] = 1;
		} else {
			T[u] = 0;
		}
		D[u] = 0;
	} else {
		make(u*2, i, (i+j)/2);
		make(u*2+1, (i+j)/2+1, j);
		T[u] = T[u*2] + T[u*2+1];
		D[u] = 0;
	}
}

void init() {
	memset(P, -1, sizeof(P));
	P[2] = 1;
	for(int i = 3; i < 1000006; i += 2) if(P[i] == -1) {
		P[i] = 1;
		for(int j = i*2; j < 1000006; j += i)
			P[j] = 0;
	}
}

int main() {
	init();

	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}
		make(1, 0, n-1);

		printf("Case %d:\n", no++);
		while(q--) {
			int c, x, y, v;
			scanf("%d", &c);
			switch(c) {
				case 0:
					scanf("%d %d %d", &x, &y, &v);
					set(1, 0, n-1, x-1, y-1, v);
					break;

				case 1:
					scanf("%d %d", &x, &y);
					printf("%d\n", sum(1, 0, n-1, x-1, y-1));
					break;
			}
		}
	}
	return 0;
}
