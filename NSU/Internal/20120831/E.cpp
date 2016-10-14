#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ; 

int numbers[ 2002 ] ;
int sums[ 2002 ] ; 
long long dp[ 2002 ][ 30 ] ;
int n = 0 ;

long long solve( int pos , int remk ) {
	if( pos == n ) {
		if( remk > 0 ) return 1LL << 60LL ;
		return 0 ;
	}
	
	if( remk == 0 ) return 1LL << 60LL ;
	
	long long minRes = 1LL << 60 ;
	
	for( int i = pos ; i < n ; i ++ ) {
		int val = sums[ i + 1 ] - sums[ pos ] ;
		val /= ( ( i - pos ) + 1 ) ;
		 
	
	}
}

int main() {
	
	int k ;
	
	while( cin >> n >> k ) {
		if( n == 0 && k == 0 ) break ;
	
		int sum = 0 ; 
		memset( dp , -1 , sizeof dp ) ;
				
		for( int i = 0 ; i < n ; i ++ ) {
			scanf("%d",&numbers[ i ] ) ;
			sum += numbers[ i ];
			sums[ i + 1 ] = sum ; 
			
		}
		
		long long res = solve( 0 , k ) ;
		cout << res << endl ; 
		
		
	}
	return 0 ;
}
