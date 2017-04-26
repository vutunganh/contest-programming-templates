#include <iostream>
#include <vector>

using namespace std;

bool solve( )
{
  int N, K;
  cin >> N >> K;
  vector< int > B( K + 1, 0 );
  bool works = false;

  int first;
  cin >> first;
  first = first % K;
  if (first < 0) 
    first = K + first;

  B[first%K] = 1;
  if (N == 1 && B[0] == 1) return true;

  for (int i = 0; i < N - 1; ++ i) {
    int n;
    cin >> n;
    vector<int> Bold = B;

    n = n % K;
    if (n < 0) n = K + n;

    int m = (K - n) % K;

    if (!works) {
      for (int j = 0; j < K; ++ j) {
        if (Bold[j] == i + 1) {
          B[(j + n) % K] = i + 2;
          B[(j + m) % K] = i + 2;
          /*cout << n << ": " << (j + n) % K << endl;
          cout << m << ": " << (j + m) % K << endl;*/
        }
        if (B[0] == N) works = true;
      }
    }
  }

  return works;
}

int main( void )
{
  int M;
  cin >> M;

  for( int i = 0; i < M; ++i )
    if( solve( ) )
      cout << "Divisible" << endl;
    else
      cout << "Not divisible" << endl;
}
