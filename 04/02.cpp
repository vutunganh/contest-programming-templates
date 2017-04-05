#include <iostream>
#include <vector>
#include <utility>
//#define MY_DEBUG

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
#ifdef MY_DEBUG
  cout << "input: " << first << endl;
#endif

  S.push_back( make_pair( first, first ) );

  for( int i = 0; i < n - 1; ++i )
  {
    //size_t index = S.size( );
    int input;
    cin >> input;
#ifdef MY_DEBUG
    cout << "input: " << input << endl;
#endif

    if( input < S[ 0 ].first ) // put to the left
    {
      if (input < S[S.size() - 1].first) {
#ifdef MY_DEBUG
        cout << "  b" << input << endl;
#endif
        S.push_back(make_pair(input, S[S.size() - 1].second));
      } else {
        for( int j = static_cast< int >( S.size( ) ) - 1; j >= 0; --j )
          if( input > S[ j ].first && (j == 0 || S[j - 1].first > input) ) {
#ifdef MY_DEBUG
            cout << "better: " << input << " instead " << S[j].first << endl;
#endif
            S[j].first = input;
            break;
          }
      }
    } else { // put to the right
      if (input > S[S.size() - 1].second) {
        S.push_back(make_pair(S[S.size() - 1].first, input));
#ifdef MY_DEBUG
        cout << "  b" << input << endl;
#endif
      } else {
        for( int j = static_cast< int >( S.size( ) ) - 1; j >= 0; --j ) {
          //cout << "  " << input << endl;
          if (input < S[j].second && (j == 0 || S[j - 1].second < input)) {
#ifdef MY_DEBUG
            cout << "better: " << input << " instead " << S[j].second << endl;
#endif
            S[j].second = input;
            break;
          }
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
