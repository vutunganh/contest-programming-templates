#include <iostream>

using namespace std;

const int MAX = 100001;

int FUEL[ MAX ];
int DIST[ MAX ];
int USE[ MAX ];

bool check( int N )
{
  for( int i = 0; i < N; ++i )
    if( USE[ i ] < 0 )
      return false;

  return true;
}

void solve( )
{
  int N;
  cin >> N;

  for( int i = 0; i < N; ++i )
    cin >> FUEL[ i ];
  for( int i = 0; i < N; ++i )
    cin >> DIST[ i ];

  for( int i = 0; i < N; ++i )
    USE[ i ] = FUEL[ i ] - DIST[ i ];





}

int main( void )
{
  int T;
  cin >> T;

  for( int i = 0; i < T; ++i )
    solve( );
  return 0;
}
