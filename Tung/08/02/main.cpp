#include <bits/stdc++.h>
using namespace std;

int solve( )
{
  int n;
  scanf( " %d", &n );
  int auto_increment = 1;
  unordered_map< int, vector< pair< int, int > > > G;
  for( int i = 0; i < n; ++i )
  {
    char trash[ 14 ];
    scanf( " %s", trash );
    int p;
    scanf( " %d", &p );
    for( int w = 0; w < p; ++w )
    {
      int a, b;
      scanf( " %d %d", &a, &b );
      G[ auto_increment ].push_back( make_pair( a, b ) );
      /* G[ a ][ auto_increment ] = E( auto_increment, a, b ); */
    }
    auto_increment++;
  }

  vector< bool > V( n + 4, false );
  V[ 1 ] = true;
  auto cmp = [ ]( const pair< int, int >& a, const pair< int, int >& b )
  {
    return a.second > b.second;
  };
  priority_queue< pair< int, int >, vector< pair< int, int > >, decltype( cmp ) > PQ( cmp );
  for( const auto& w : G[ 1 ] )
  {
    PQ.push( w );
  }

  int tree_size = 1;
  int result = 0;
  while( tree_size < n )
  {
    pair< int, int > E = PQ.top( );
    PQ.pop( );
    result += E.second;

    for( const auto& w : G[ E.first ] )
      if( !V[ w.second ] && E.first )
        PQ.push( w );

    tree_size++;
  }

  return result;
}

int main( void )
{
  int s;
  scanf( " %d", &s );
  for( int i = 0; i < s; ++i )
    printf( "%d\n", solve( ) );
}
