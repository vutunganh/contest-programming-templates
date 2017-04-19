#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
struct Stree
{
  Stree( int size )
    :arr_size( size ), T( 2 * size + 20, 0 )
  {
    for( int i = arr_size - 1; i > 0; --i )
      T[ i ] = T[ i << 1 ] + T[ i << 1 | 1 ];

  }

  void modify( int l, int r, int v )
  {
    for( l += arr_size, r += arr_size; l < r; l >>= 1, r >>= 1 )
    {
    if( l & 1 ) 
      T[ l++ ] += v;
    if( r & 1 ) 
      T[ --r ] += v;
    }
  }

  int operator[ ]( int p ) const
  {
    int res = 0;
    for( p += arr_size; p > 0; p >>= 1 )
      res += T[ p ];
    return res;
  }
  size_t arr_size;
  vector< int > T;
};

int main( )
{
  int N, M, n;
  scanf( " %d %d %d", &N, &M, &n );
  Stree T( n );

  for( int i = 0; i < N; ++i )
  {
    int L, R;
    scanf( " %d %d", &L, &R );

    T.modify( L, R + 1, 1 );
  }

  for( int i = 0; i < M; ++i )
  {
    int Q;
    scanf( " %d", &Q );

    printf( "%d\n", T[ Q ] );
  }
  return 0;
}
