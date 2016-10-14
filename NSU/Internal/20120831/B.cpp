#include<cstdio>
#include<iostream>
using namespace std;

int N;
long long C;
long long ar[1000003];
long long sum[1000003];
long long mem[1000003];

long long f()
{
	mem[0] = 0;
	int md = 1;
	for( int i = 1; i <= N; i++ )
	{
		long long cst = ar[i] - ar[md];
		cst *= cst;
		int tm = md;
		if( cst < C )
		{
			cst += mem[md-1]+C;
			for( int j = md+1; j <= i; j++ )
			{
				long long cur = ar[i] - ar[j];
				cur *= cur;
				cur += mem[j-1]+C;
				if( cur < cst ){ cst = cur; tm = j; }
				else if( cur > cst ) break;
			}
			for( int j = md-1; j >= 1; j-- )
			{
				long long cur = ar[i] - ar[j];
				cur *= cur;
				cur += mem[j-1]+C;
				if( cur < cst ){ cst = cur; tm = j; }
				else if( cur > cst ) break;
			}
		}
		else
		{
			md = i;  tm = md;
			cst = C + mem[i-1];
			for( int j = i-1; j >= 1; j-- )
			{
				long long cur = ar[i] - ar[j];
				cur *= cur;
				cur += mem[j-1]+C;
				if( cur < cst ){ cst = cur; tm = j; }
				else if( cur > cst ) break;
			}
		}
	
		md = tm;
		mem[i] = cst;
	}
	return mem[N];
}

int main()
{
	while( scanf("%lld %lld", &N, &C) )
	{
		if( N+C == 0 ) break;
		for( int i = 1; i <= N; i++ )
		{
			scanf("%lld", &ar[i]);
		}
		cout<<f()<<'\n';
	}
	return 0;
}
