#include <iostream>
#include <vector>

#define MAX_N 100007
using namespace std;

long long int A[ MAX_N ];
long long int DP[ MAX_N ];

/*long long f( long long index )
{
  if (index < 0) return 0;
  if( DP[ index ] == -1 ) {
    long long t = max( f(index - 2) + index*A[index], f(index - 3) + (index - 1)*(A[index - 1]));
    DP[index] = t;
    return t;
  } else {
    return DP[index];
  }
}*/

int main( void )
{
  int n;
  cin >> n;

  for( int i = 0; i < MAX_N; ++i )
    DP[ i ] = -1;

  for( int i = 0; i < n; ++i )
  {
    int in;
    cin >> in;
    ++ A[ in ];
  }

  DP[0] = 0;
  DP[1] = A[1];
  DP[2] = max(2*A[2], A[1]);
  DP[3] = max(3*A[3] + A[1], 2*A[2]);
  for (int i = 4; i < MAX_N; ++ i) {
     DP[i] = max(DP[i - 2] + i*A[i], DP[i - 3] + (i - 1)*A[i - 1]);
  }

  //long long a = max(f(MAX_N - 1), f(MAX_N - 2));
  cout << max(DP[MAX_N - 1], DP[MAX_N - 2]) << endl;

  return 0;
}
