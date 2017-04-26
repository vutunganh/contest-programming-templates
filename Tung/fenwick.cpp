#include <bits/stdc++.h>
#define int_in(n) int n; scanf( " %d", &n )
#define str_in(s, l) char s[ l ]; scanf( " %s", s ); s[ l - 1 ] = 0
#define vi vector< int >
#define endl printf( "\n" );
#define PB push_back

using namespace std;

vi T;

void add( int i, int delta )
{
  while( i < T.size( ) )
  {
    T[ i ] += delta;
    i += ( i & -i );
  }
}

int pref_sum( int i )
{
  int res = 0;
  while( i > 0 )
  {
    s += T[ i ];
    i = i & ( i - 1 );
  }

  return res;
}

int main( void )
{
  return 0;
}
