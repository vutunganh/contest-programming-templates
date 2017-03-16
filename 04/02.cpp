#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int solve( )
{
  int n;
  cin >> n;

  if( !n )
    return 0;

  //int plus_result = 0;

  vector< pair< int, int > > S;

  int first;
  cin >> first;

  S.push_back( make_pair( first, first ) );

  for( int i = 0; i < n - 1; ++i )
  {
    //size_t index = S.size( );
    int input;
    cin >> input;

    if( input < S[ 0 ].first )
    {
      if (input < S[S.size() - 1].first) {
        S.push_back(make_pair(input, S[S.size() - 1].second));
      } else {
        for( int j = static_cast< int >( S.size( ) ) - 1; j >= 0; --j )
          if( input < S[ j ].first ) {
            S[j].first = input;
            break;
          }
      }
    } else {
      if (input > S[S.size() - 1].second) {
        S.push_back(make_pair(S[S.size() - 1].first, input));
      } else {
        for( int j = static_cast< int >( S.size( ) ) - 1; j >= 0; --j )
          if( input < S[ j ].second ) {
            S[j].first = input;
            break;
          }
      }
    }

    /*for( size_t k = 0; k < S.size( ); ++k )
    {
      if( S[ k ] < j )
      {
        index = k;
        break;
      }
    }*/

    /*if( index == S.size( ) )
      S.push_back( j );
    else if( index == 0 && j < S[ 0 ] )
      plus_result++;
    else if( index == S.size( ) - 1 )
      S[ index ] = j;
    else if( index == 0 )
      S[ 0 ] = j;*/
  }

  return S.size( );
}

int main( void )
{
  int T;
  cin >> T;

  for( int i = 0; i < T; ++i )
  {
    cout << solve( ) << endl;
  }
  return 0;
}
