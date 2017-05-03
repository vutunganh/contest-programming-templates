#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main( void )
{
  int N;
  cin >> N;

  vector< pair< string, string > > V( N );

  for( int i = 0; i < N; ++i )
  {
    cin >> V[ i ].first;
    V[ i ].second = V[ i ].first;
    reverse( V[ i ].first.begin( ), V[ i ].first.end( ) );
  }

  sort( V.begin( ), V.end( ), 
        [ ]( pair< string, string > s1, pair< string, string > s2 )
        {
          return s1.first < s2.first;
        }
      );


  return 0;
}
