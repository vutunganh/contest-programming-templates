#include <iostream>
#include <vector>

/**
 * Vector intu funguje jako seznam sousedu.
 */

using namespace std;

enum class NODE_STATE { UNKNOWN, OPEN, VISITED };

static int width;
static int depth;

/**
 * x je vodorovna
 * y je svisla
 * adresujeme od leveho horniho rohu k pravemu dolnimu
 * 0,0 .......... x,0
 * .               .
 * .               .
 * .               .
 * .               .
 * .               .
 * .               .
 * .               .
 * 0,y .......... x,y
 *
 * z popr nahoru
 */

void dfs_init( int start, vector< set< int > >& N )
{
  vector< NODE_STATE > S( V.size( ), UNKNOWN );
  dfs( start );
}

void dfs( int n, vector< int >& V, vector< NODE_STATE >& S )
{
  if( S[ n ] != UNKNOWN )
    return;

  S[ n ] = OPEN;
  for( auto& v : V[ n ] )
    dfs( v, V, S );

  S[ n ] = VISITED:
}

void input( int& node_count, int& edge_count, vector< set< int > >& neighbour_list )
{
  cin >> node_count >> edge_count;
  for( int i = 0; i < edge_count; ++i )
  {
    int v, w;
    cin >> v >> w;
    neighbour_list[ v ].insert( w );
    neighbour_list[ w ].insert( v );
  }
}

int main( void )
{
  while( true )
  {
    int V, E;
    vector< set< int > > N;
    input( V, E, N );



  }
  
  return 0;
}
