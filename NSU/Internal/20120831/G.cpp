#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std ;

#define SET(c, v) memset(c, v, sizeof(c))

template<int N>
class Dsets {
int p[N], r[N];

public:
	Dsets() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			p[i] = i;
		SET(r, 0);
	}
	
	int parent(int a) {
		if(p[a] != a)
			p[a] = parent(p[a]);
		return p[a];
	}
	
	void merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(r[a] > r[b])
			p[b] = a;
		else
			p[a] = b;
		if(r[a] == r[b])
			++r[b];
	}
};

Dsets<1005> dset;

int solve( vector<pair<int,int> > & blues , int k  ) {
	
//	dset.merge(0, 1);
//	dset.parent(2);
	
	int tot = 0 ;
	vector<bool> taken( blues.size() , 0 ) ; 
	
	for( int i = 0 ; i < blues.size() ; i ++ ) {
		int f = blues[ i ].first ;
		int s = blues[ i ].second ;
		
		f -- , s -- ; 
		
		if( dset.parent( f ) != dset.parent( s ) ) {
			dset.merge( f , s ) ;
			taken[ i ] = true ;
//			tot ++ ;
		}	
	}
	
	map<int,int> m ; 
	
	for( int i = 0 ; i < blues.size() ; i ++ ) {
		if( taken[ i ] == 0 ) continue ; 
		m[ dset.parent( blues[ i ].first  ) ] ++ ;
		m[ dset.parent( blues[ i ].second ) ] ++ ;
	}
	
	for( int i = 0 ; i < blues.size() ; i ++ ) {
		if( taken[ i ] == 0 ) continue ; 
		
		if( m[ dset.parent( blues[ i ].first ) ] >= k ) return 1 ;
		if( m[ dset.parent( blues[ i ].second ) ] >= k ) return 1 ;
	}
	
	return 0 ;
//	if( tot >= k ) return 1 ;
//	return 0 ;
	
	
}

int main() {
	
	int n , m , k ;
	
	while( cin >> n >> m >> k ) {
	//	cerr << " h " << endl ;
		if( n == 0 && m == 0 && k == 0 ) break ;
		
		vector<pair<int,int> > blues ;
		vector<pair<int,int> > reds ;
		
		pair<int,int> cur ; 
		
		char color = 'c' ;
		
		for( int i = 0 ; i < m ; i ++ ) {
//			scanf("%c",&color) ;
			cin >> color ; 	
			scanf("%d %d",&cur.first,&cur.second ) ;
			
			if( color == 'B' ) {
				blues.push_back( cur ) ;
			}
			
			else {
				reds.push_back( cur ) ;
			}
		}
		
		int pos = solve( blues , k ) ;
		cout << pos << endl ; 
		
	}
	
	return 0 ;
}
