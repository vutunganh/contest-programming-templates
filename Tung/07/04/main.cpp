#include <bits/stdc++.h>

using namespace std;

vector< int > V;
vector< pair< int, int > > Q;
int BS;

void add( int x, int v )
{
}

int main( void )
{
  while( true )
  {
    int n, q;
    scanf( " %d", &n );
    if( !n )
      break;
    scanf( " %d", &q );

    BS = static_cast< int >( sqrt( n ) );

    for( int i = 0; i < n; ++i )
    {
      int a;
      scanf( " %d", &a );
      V.push_back( a );
    }

    for( int i = 0; i < q; ++i )
    {
      int l, r;
      scanf( " %d %d", &l, &r );
      Q.push_back( make_pair( l, r ) );
    }

    sort( Q.begin( ), Q.end( ), 
        [ ]( pair< int, int >& x, pair< int, int >& y )
        { 
        if( x.first / BS != y.first / BS ) 
        return x.first / BS < y.first / BS;
        return x.second < x.second;
        } );

    int currL = 0, currR = 0;
    int currSum = 0;

    for( size_t i = 0; i < Q.size( ); ++i )
    {
      int L = Q[i].first, R = Q[i].second;

      while (currL < L)
      {
        currSum -= V[currL];
        currL++;
      }

      // Add Elements of current Range
      while (currL > L)
      {
        currSum += V[currL-1];
        currL--;
      }
      while (currR <= R)
      {
        currSum += V[currR];
        currR++;
      }

      // Remove elements of previous range.  For example
      // when previous range is [0, 10] and current range
      // is [3, 8], then a[9] and a[10] are subtracted
      while (currR > R+1)
      {
        currSum -= V[currR-1];
        currR--;
      }

      // Print sum of current range
      printf( "%d\n", currSum );
    }
  }

  return 0;
}
