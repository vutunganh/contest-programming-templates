#include <iostream>

#define MAX 2002


char MAP[ MAX ][ MAX ];

using namespace std;

struct data
{
  int up;
  int down;
  int left;
  int right;
};

data SOLUTION[ MAX ][ MAX ];

void clear( int N )
{
  for( int i = 1; i <= N; ++i )
    for( int j = 1; j <= N; ++j )
    {
      SOLUTION[ i ][ j ].up = 0;
      SOLUTION[ i ][ j ].down = 0;
      SOLUTION[ i ][ j ].left = 0;
      SOLUTION[ i ][ j ].right = 0;
    }
}

int minData( data d )
{
  int min = d.up;
  if( d.down < min )
    min = d.down;
  if( d.left < min )
    min = d.left;
  if( d.right < min )
    min = d.right;

  return min;
}

void solve( )
{
  int N;
  cin >> N;

  for( int i = 1; i <= N; ++i )
    for( int j = 1; j <= N; ++j )
      cin >> MAP[ i ][ j ];

  for( int i = 1; i <= N; ++i )
    for( int j = 1; j <= N; ++j )
    {
      if( MAP[ i ][ j ] == '#' )
      {
        SOLUTION[ i ][ j ].up = SOLUTION[ i - 1 ][ j ].up + 1;
        SOLUTION[ i ][ j ].left = SOLUTION[ i ][ j - 1 ].left + 1;
      }
    }

  for( int i = N; i >= 1; --i )
    for( int j = N; j >= 1; --j )
    {
      if( MAP[ i ][ j ] == '#' )
      {
        SOLUTION[ i ][ j ].down = SOLUTION[ i + 1 ][ j ].down + 1;
        SOLUTION[ i ][ j ].right = SOLUTION[ i ][ j + 1 ].right + 1;
      }
    }

  int solution = 0;
  for( int i = 1; i <= N; ++i )
    for( int j = 1; j <= N; ++j )
    {
      int min = minData( SOLUTION[ i ][ j ] );
      if( min > solution )
      {
        solution = min;
      }
    }

  #ifdef DEBUG
  for( int i = 1; i <= N; ++i )
  {
    for( int j = 1; j <= N; ++j )
    {
      cout << SOLUTION[ i ][ j ].up << ":" << SOLUTION[ i ][ j ].down << ":" << SOLUTION[ i ][ j ].left << ":" << SOLUTION[ i ][ j ].right << "\t";
    }
    cout << endl;
  }
  #endif

  cout << solution << endl;
  clear( N );
}

int main( void )
{
  int T;
  cin >> T;

  for( int i = 0; i < T; ++i )
  {
    solve( );
  }
  return 0;
}
