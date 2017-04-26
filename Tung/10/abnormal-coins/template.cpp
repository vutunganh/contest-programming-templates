#include <bits/stdc++.h>
#define int_in(n) int n; scanf( " %d", &n )
#define str_in(s, l) char s[ l ]; scanf( " %s", s ); s[ l - 1 ] = 0
#define vi vector< int >
#define endl printf( "\n" );
#define PB push_back

using namespace std;

int main( void )
{
  int_in( n );
  int a = 3;
  int cnt = 0;
  while( a <= n )
  {
    a += ++a;
    cnt++;
  }

  printf( "%d\n", cnt );


  return 0;
}
