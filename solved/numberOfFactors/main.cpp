#include <iostream>
#include <vector>

using namespace std;

vector<uint64_t> primes;
vector<uint64_t> squares;

int main() {
  //ios_base::sync_with_stdio(true);
  string result = "";

  for (int i = 2; i <= 320000; ++ i) {
    bool isPrime = true;
    for (int j = 0; j < primes.size() && primes[j]*primes[j] <= i; ++ j) {
      if (i % primes[j] == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(i);
      squares.push_back(i*i);
    }
  }

  int t;
  //cin >> t;
  scanf("%d", &t);

  for (int k = 0; k < t; ++k) {
    unsigned long long n;
    //cin >> n;
    scanf("%llu", &n);


    for (int i = 0; i < squares.size(); ++ i) {
      if (n == 1 || n < squares[i]) break;

      while (n % squares[i] == 0) {
        n /= squares[i];
      }
      if( n % primes[ i ] == 0 ) {
        n = 2;
        break;
      }

    }
    if (n != 1) {
      //cout << "NO\n";
      //result += "NO\n";
      printf("NO\n");
    } else {
      //cout << "YES\n";
      //result += "YES\n";
      printf("YES\n");
    }
  }
  //cout << flush;
  //printf("%s", result.c_str());
  return 0;
}