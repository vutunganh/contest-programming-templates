#include <iostream>
#include <vector>

/* Vector intu funguje jako seznam sousedu.
 */

using namespace std;
using neighbour_list = std::vector<int>;

enum class NODE_STATE { UNKNOWN, OPEN, VISITED };

/* sirka je "x"-ova
 * hloubka je "y"-ova
 */
static int width;
static int depth;

/* x je vodorovna
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
int adr_2d( int x, int y )
{
  return y * width + x;
}

int adr_3d( int x = 0, int y = 0, int z = 0 )
{
  return z * width * depth +  y * width + x;
}

/**
 * vraci seznam sousedu pro kazdy node
 */
vector< int > neighbour_2d( int x, int y )
{
  vector< int > to_ret;
  for( int r = -1; r < 2; ++r )
    for( int c = -1; c < 2; ++c )
      /* tady muzete priohybat podminky, pokud vzdalenost neni nutne kolma 1
       * jsou tam i mozna funkcni kontroly mezi bludiste
       */
      if( r * r + c * c == 1 && 
          r+y >= 0 &&
          c+x >= 0 &&
          r+y < depth &&
          c+x < width
        )
      {
        to_ret.push_back( (r+x) * width + (c+y) );
      }
  return to_ret;
}

void dfs_init( int start, vector< int >& V )
{
  vector< NODE_STATE > S( V.size( ) );
  for( auto& s : S )
    S[ start ] = UNKNOWN;

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

/* vector< int > neighbour_3d( int x, int y, int z ) */
/* { */
/*   vector< int >; */
/*   for( int r = -1; r < 2; ++r ) */
/*     for( int c = -1; c < 2; ++c ) */
/*       for( int h = -1; h < 2; ++h ) */
/*       /1* tady muzete priohybat podminky, pokud vzdalenost neni nutne kolma 1 */
/*        *1/ */
/*       if( r * r + c * c + h * h == 1 */ 
/*         ) */
/*       { */
/*         to_ret.push_back( h * width * depth + r * width + c ); */
/*       } */
/*   return to_ret; */
/* } */


int main( void )
{
  
  return 0;
}
