#include <iostream>
#include <set>
#include <vector>

enum NODE_STATE { UNVISITED, OPEN, CLOSED };

using namespace std;

int circleSource;

bool find_cycle( int v, int parent, set< int >& result, vector< NODE_STATE >& S, vector< vector<  int > >& N )
{
  if( S[ v ] == CLOSED )
  {
    result.insert( v );
    return true;
  }

  if( S[ v ] == OPEN )
  {
    result.insert( v );
    circleSource = v;
    return true;
  }

  S[ v ] = OPEN;
  for( auto w : N[ v ] )
  {
    if( w == parent )
      continue;
    if( find_cycle( w, v, result, S, N ) )
    {
      result.insert( v );
      if (v == circleSource) return false;
      return true;
    }
  }
  S[ v ] = CLOSED;
  return false;
}

void distance( int v, int p, vector< int >& D, vector< vector< int > >& N, vector< NODE_STATE >& S )
{
  if( S[ v ] != UNVISITED )
    return;

  S[ v ] = OPEN;
  if( D[ v ] > D[ p ] + 1 )
    D[ v ] = D[ p ] + 1;
  for( auto w : N[ v ] )
    if (D[ w ] != 0)
      distance( w, v, D, N, S );
  S[ v ] = CLOSED;
}


int main( void )
{
  int V;
  cin >> V;

  vector< vector< int > > N( V + 1 );
  vector< NODE_STATE > S( V + 1, UNVISITED );
  /* vector< pair< int, int > > I( V + 1 ); */

  for( int i = 0; i < V; ++i )
  {
    int v, w;
    cin >> v >> w;

    N[ v ].push_back( w );
    N[ w ].push_back( v );
  }

  // find cycle
  set< int > C;
  find_cycle( 1, 0, C, S, N );

  #ifdef DEBUG
  cout << "Na kruznici lezi: ";
  for( auto n : C )
    cout << n << " ";
  cout << endl;
  #endif

  vector< int > D( V + 1, 1000000000 );
  for( auto& v : S )
    v = UNVISITED;
  for( auto n : C )
    D[ n ] = 0;
  D[ 0 ] = 0;

  for( auto n : C )
    distance( n, 0, D, N, S );

  for( size_t i = 1; i < D.size( ) - 1; ++i )
    cout << D[ i ] << " ";
  cout << D[ D.size() - 1] << endl;

  return 0;
}
