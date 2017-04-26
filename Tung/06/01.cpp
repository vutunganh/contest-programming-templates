#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solve( )
{
  int knife_count;
  scanf( " %d", &knife_count );

  vector< int > knife_numbers;
  for( int i = 0; i < knife_count; ++i )
  {
    int n;
    scanf( " %d", &n );
    knife_numbers.push_back( n );
  }
  sort( knife_numbers.begin( ), knife_numbers.end( ) );


  unsigned long long solution = 1;
  for( size_t i = 0; i < knife_numbers.size( ); ++i )
  {
    solution *= knife_numbers[ i ] - i;
    solution %= 1000000007;
  }

  return solution;
}

int main( void )
{
  int T;
  scanf( " %d", &T );

  for( int i = 0; i < T; ++i )
    printf( "%d\n", solve( ) );

  printf( "KILL BATMAN\n" );
  return 0;
}
