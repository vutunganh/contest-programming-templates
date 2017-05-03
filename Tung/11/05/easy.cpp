#include <bits/stdc++.h>
using namespace std;

int main( void )
{
  int n;
  while( scanf( " %d", &n ) == 1 )
  {
    int k;
    scanf( " %d", &k );
    vector< vector< int > > V( n, vector< int >( 50, 50 ) );
    for( int i = 0; i < n; ++i )
    {
      int p;
      scanf( " %d", &p );
      V[ i ].resize( p );
      for( int j = 0; j < p; ++j )
      {
        int tmp;
        scanf( " %d", &tmp );
        V[ i ][ j ] = ( tmp );
      }

      // sort( V[ i ].begin( ), V[ i ].end( ) );
    }

    #ifdef DEBUG
    for( size_t r = 0; r < V.size( ); ++r )
    {
      for( size_t c = 0; c < V[ r ].size( ); ++c )
        printf( "%d ", V[ r ][ c ] );
      printf( "\n" );
    }
    #endif

    int sum = 0;
    int added = 0;

    for( int c = 0; c < 50 && added < k; ++c )
    {
      for( int r = 0; r < n && added < k; ++r )
      {
        if( V[ r ][ c ] >= sum || V[ r ][ c ] == 50 )
        {
          sum += V[ r ][ c ];
          added++;
        }
      }
    }

    printf( "%d\n", sum );
  }
  return 0;
}