#include <bits/stdc++.h>

using namespace std;

struct E
{
  E( )
  {
  }
  E( int _f, int _t, int _w )
    : from( _f ), to( _t ), w( _w )
  {
  }
  int from;
  int to;
  unsigned long long w;
};

unsigned long long solve( )
{
  int n;
  scanf( " %d", &n );
  int auto_increment = 1;
  unordered_map< int, unordered_map< int, E > > G;
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
      G[ auto_increment ][ a ] = E( auto_increment, a, b );
      /* G[ a ][ auto_increment ] = E( auto_increment, a, b ); */
    }
    auto_increment++;
  }

  auto cmp = [ ]( const E& a, const E& b ) { return a.w > b.w; };

  priority_queue< E, vector< E >, decltype( cmp ) > PQ( cmp );
  for( const auto& w : G[ 1 ] )
  {
    #ifdef DEBUG
    printf( "PQ <- %d - %d, %llu\n", w.second.from, w.second.to, w.second.w );
    #endif
    PQ.push( w.second );
  }

  unsigned long long result = 0;
  unordered_set< int > T;
  T.insert( 1 );
  /* while( T.size( ) < n ) */
  for( int i = 0; i < n - 1; ++i )
  {
    while( true )
    {
      E e = PQ.top( );
      /* if( ( V[ e.from ] && V[ e.to ] ) || ( !V[ e.from ] && !V[ e.to ] ) ) */
      if( ( T.find( e.from ) != T.end( ) && T.find( e.to ) != T.end( ) ) 
          || ( T.find( e.from ) == T.end( ) && T.find( e.to ) == T.end( ) ) )
      {
        #ifdef DEBUG
        printf( "Popped %d - %d, %llu\n", e.from, e.to, e.w );
        #endif
        PQ.pop( );
      }
      else
        break;
    }
    E e = PQ.top( );
    #ifdef DEBUG
    printf( "Popped %d - %d, %llu\n", e.from, e.to, e.w );
    #endif
    PQ.pop( );
    #ifdef DEBUG
    printf( "Added %d -> %d, %llu\n", e.from, e.to, e.w );
    #endif
    result += e.w;
    T.insert( e.to );
    for( const auto& w : G[ e.to ] )
    {
      #ifdef DEBUG
      printf( "PQ <- %d - %d, %llu\n", w.second.from, w.second.to, w.second.w );
      #endif
      PQ.push( w.second );
    }
  }

  return result;
}

int main( void )
{
  int s;
  scanf( " %d", &s );
  for( int i = 0; i < s; ++i )
    printf( "%llu\n", solve( ) );
  return 0;
}
