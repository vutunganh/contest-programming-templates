#include <cstdio>
#include <vector>
#define int_in(n) int n; scanf( " %d", &n )
#define str_in(s, l) char s[ l ]; scanf( " %s", s ); s[ l - 1 ] = 0
#define vi vector< long long >
#define endl printf( "\n" );

using namespace std;

vi strom;

void pricti(unsigned int index, int rozdil) {
  while (index < strom.size()) {
    strom[index] += rozdil;
    index = index + (index & -index);
    // "&" značí bitový AND
  }
}

int pref_soucet(unsigned int index) {
  int soucet = 0;
  while (index>0) {
    soucet = soucet + strom[index];
    index = index & (index-1);
  }
  return soucet;
}

int solve( int c )
{
  int_in( n );
  if( !n )
    return 0;
  strom.resize( n + 116, 0 );
  if( c != 1 )
    endl;
  printf( "Case %d:\n", c );

  for( int i = 1; i <= n; ++i )
  {
    int_in( tmp );
    pricti( i, tmp - pref_soucet( i ) + pref_soucet( i - 1 ) );
  }

  int next = 1;
  char s[ 4 ];
  while( next )
  {
    scanf( " %s", s );
    if( s[ 0 ] == 'M' )
    {
      int_in( l );
      int_in( r );
      printf( "%d\n", pref_soucet( r ) - pref_soucet( l - 1 ) );
    }
    else if( s[ 0 ] == 'S' )
    {
      int_in( index );
      int_in( tmp );
      pricti( index, tmp - pref_soucet( index ) + pref_soucet( index - 1 ) );
    }
    else
      break;
  }
  return 1;
}

int main( )
{
  for( int i = 1; ; ++i )
  {
    if( !solve( i ) )
      break;
  }
  return 0;
}
