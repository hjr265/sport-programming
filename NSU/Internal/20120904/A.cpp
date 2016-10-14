#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string str;
int siz;

string f( int l, int r )
{
	if( l > r ) return "";
	if(  l == r )
	{
		if( str[l] == '(' || str[l] == ')' ) return "(0)";
		if( str[l] == '+' ) return "0+0";
		return str[l];
	}
	
	if( str[l] == '(' )
	{
		if( l == r ) return "(0)";
		if( str[l] == '(' && str[r] == ')' ) return "(" + f( l+1, r-1 ) + ")";
		
		int fnd = -1;
		for( int i = l+1; i <= r; i++ ) if( str[i] == ')' ){ fnd = i;  break; }
		if( fnd == -1 )
		{
			 string st = "(" + f( l+1, r ) + ")";
			 return st;
		}
		else
		{
			string st="";
			if( l+1 == fnd ) st = "(0)";
			else st = f( l+1, fnd-1 );
			if( str[fnd+1] != '+' ) st += '+';
			st += f( fnd+1, r );
			return st; 
		}
	}
	if( str[l] == ')' ) return "(0)" + f( l+1, r );
	if( str[l] == '+' )
	{
		string st = "0+"; 
		return st + f( l+1, r );
	}
	string st = "";
	int fnd = -1;
	
	for( int i = l; i <= r; i++ ) 
	{
		if( str[i] == ')' str[i] == '(' ){ st += str[i] fnd = i; break; }
	}
	if( st[ st.size()-1 ] == ')' ) st = "("+st;
	return st + f( fnd+1, r );
}

int main()
{
	while( cin>>str )
	{
		siz = str.size();	
	}
	return 0;
} 	
