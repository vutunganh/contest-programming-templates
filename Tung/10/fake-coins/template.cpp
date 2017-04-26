#include <bits/stdc++.h>
#define int_in(n) int n; scanf( " %d", &n )
#define str_in(s, l) char s[ l ]; scanf( " %s", s ); s[ l - 1 ] = 0
#define vi vector< int >
#define endl printf( "\n" );
#define PB push_back

using namespace std;

int main( void )
{
  string in;
  cin >> in;

  in = ' ' + in;

  /* cout << in << endl; */

  unordered_set< string > res;
  for( size_t i = 1; i < in.size( ); ++i )
  {
    for( size_t j = i + 1; j < in.size( ); ++j )
    {
      string s;
      s += in[ i ];

      size_t myi = i;
      size_t myj = j;
      while( myj < in.size( ) )
      {
        s += in[ myj ];
        size_t tmp = myj;
        myj += myi;
        myi = tmp;
      }

      res.insert( s );
    }
  }
  cout << res.size( ) << '\n';


  return 0;
}
