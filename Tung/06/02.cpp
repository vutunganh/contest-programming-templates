   #include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd( int u, int v )
{
  while ( v != 0 )
  {
    int r = u % v;
    u = v;
    v = r;
  }
  return u;
}

const int MAX = 1000002;

int PRECOMPUTE[ MAX ];

int solve( )
{
  int a, b;
  scanf( " %d %d", &a, &b );

  return PRECOMPUTE[ gcd( a, b ) ];
}

void precalc( )
{
  for( int i = 1; i < MAX; ++i )
  {
    for( int j = i; j < MAX; j += i )
    {
      PRECOMPUTE[ j ]++;
    }
  }
}

int main( void )
{
  precalc( );

  int T;
  scanf( " %d", &T );

  for( int i = 0; i < T; ++i )
  {
    printf( "%d\n", solve( ) );
  }
  return 0;
}
