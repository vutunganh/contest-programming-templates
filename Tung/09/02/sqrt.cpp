#include <bits/stdc++.h>
#define int_in(n) int n; scanf( " %d", &n )
#define str_in(s, l) char s[ l ]; scanf( " %s", s ); s[ l - 1 ] = 0
#define vi vector< int >
#define endl printf( "\n" );
using namespace std;

vi V;
vi SQRT;

int calc_block( int i )
{
  return 1 + i / sqrt( SQRT.size( ) );
}

bool solve( int to_print )
{
  int_in( n );
  if( !n )
    return false;
  printf( "Case %d:\n", to_print );

  V.resize( n + 1 );
  SQRT.resize( n + 1 );

  for( int i = 1; i <= n; ++i )
  {
    int_in( tmp );
    V[ i ] = tmp;
    SQRT[ calc_block( i ) ] += tmp;
  }

  #ifdef DEBUG
  for( size_t i = 0; i < SQRT.size( ); ++i )
    printf( "%d ", SQRT[ i ] );
  #endif

  char s[ 4 ];
  while( true )
  {
    scanf( " %s", s );
    if( s[ 0 ] == 'M' )
    {
      int_in( L );
      int_in( R );
      int index_L = calc_block( L );
      int index_R = calc_block( R );

      int acc = 0;
      while( calc_block( L ) == index_L && L <= R )
      {
        acc += V[ L ];
        L += 1;
      }


      while( calc_block( R ) == index_R && R >= L )
      {
        acc += V[ R ];
        R -= 1;
      }

      for( int i = calc_block( L ); i <= calc_block( R ); ++i )
      {
        acc += SQRT[ i ];
      }

      printf( "%d\n", acc );
    }
    else if( s[ 0 ] == 'S' )
    {
      int_in( index );
      int_in( delta );
      SQRT[ calc_block( index ) ] += ( - V[ index ] + delta );
      V[ index ] = delta;
    }
    else
      break;
  }

  V.clear( );
  SQRT.clear( );
  printf( "\n" );
  return true;
}

int main( void )
{
  for( int i = 1; ; ++i )
    if( !solve( i ) )
      break;

  return 0;
}
