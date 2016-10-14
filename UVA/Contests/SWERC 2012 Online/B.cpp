#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char S[102],  T[102];
int len;
int mx = 100000000;
int mem[101][101][101];

int f( int ind, int on, int ze ){
	if( ind >= len ){
		if( on > 0 || ze > 0 ) return mx;
		return 0;
	}
	if( S[ind] == T[ind] ) return f( ind+1, on, ze );
	if( mem[ind][on][ze] > -1 ) return mem[ind][on][ze];
	int mn = mx;
	if( S[ind] == '0' ){
		mn = min( mn, f( ind+1, on, ze )+1 );
		if( on > 0 ) mn = min( mn, f( ind+1, on-1, ze ) );
		mn = min( mn, f( ind+1, on, ze+1 )+1 );
	}
	else if( S[ind] == '1' ){
		if( ze > 0 ) mn = min( mn, f( ind+1, on, ze-1 ) );
		mn = min( mn, f( ind+1, on+1, ze ) + 1 );
	}
	else{
		mn = min( mn, f( ind+1, on, ze ) + 1 );
		if( T[ind] == '1' ){
			if( on > 0 ) mn = min( mn, f( ind+1, on-1, ze ) + 1 );
			mn = min( mn, f( ind+1, on, ze+1 )+2 );
		}
		else{
			if( ze > 0 ) mn = min( mn, f( ind+1, on, ze-1 )+1 );
			mn = min( mn, f( ind+1, on+1, ze ) + 2 );
		}
	}
	
	return mem[ind][on][ze]=mn;
}


int main(){
	int t;
	scanf("%d", &t);
	for( int cs = 1; cs <= t; cs++ ){
		memset( mem, -1, sizeof(mem) );
		scanf("%s %s", S, T);
		len = strlen( S );
		int ans = f( 0, 0, 0 );
		if( ans >= mx ) ans  = -1;
		cout<<"Case "<<cs<<": "<<ans<<endl;
	}
	return 0;
}

