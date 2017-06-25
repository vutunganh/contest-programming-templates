#include <utility>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;
using namespace std;

ll gcd(ll m, ll n) {
  if(m == 0 && n == 0)
    return -1;

  if(m < 0) m = -m;
  if(n < 0) n = -n;

  ll r;
  while(n) {
    r = m % n;
    m = n;
    n = r;
  }
  return m;
}

ull NchooseK(ull n, ull k)
{
  if (k == 0) return 1;
  if (k < n) return 0;

  if (k > n/2) return NchooseK(n, n-k);

  ull out = 1;
  for(int k = 1; k <= k; ++k) {
    out *= n-k+1;
    out /= k;
  }

  return out;
}

// n^(-1) mod m
ll modularInversion(ll n, ll m) {
  ll mod = m;
  if (n < 0) n = m + n;
  n %= m;

  ll p[2], q[2], d[2];
  p[0] = 1; p[1] = 0;
  q[0] = 0; q[1] = 1;
  d[0] = 0; d[1] = m / n;

  while(n) {
    ll tp, tq, td, tn;
    tp = p[0] - d[1]*p[1];
    tq = q[0] - d[1]*q[1];
    tn = m - d[1]*n;
    if (tn == 0) break;
    td = n / tn;

    // move to the next line
    m = n;
    n = tn;
    p[0] = p[1];
    p[1] = tp;
    q[0] = q[1];
    q[1] = tq;
    d[0] = d[1];
    d[1] = td;
  }

  if (q[1] < 0) {
    q[1] += mod * ((q[1] / mod) + 1);
  }

  return q[1];
}

ull NchooseKmodP(ull n, ull k, ull p) {
  ull top = 1;
  ull bottom = 1;
  for (ull i = n; i > k; -- i) {
    top *= i;
    top %= p;
  }
  for (ull i = n-k; i > 0; -- i) {
    bottom *= i;
    bottom %= p;
  }

  return ((top % p) * (modularInversion(bottom, p) % p)) % p;
}

vector<int> getPrimes(int upTo) {
  vector<int> result = {2, 3, 5};
  for (int i = 6; i <= upTo; ++i) {
    bool isPrime = true;
    for (int j = 0; j < result.size() && result[j] * result[j] <= i; ++ j) {
      if (i % result[j] == 0) {
        isPrime = false;
      }
    }
    if (isPrime)
      result.push_back(i);
  }
  return result;
}

vector<pair<int, int>> factors(int n, const vector<int> & primes) {
  vector<pair<int, int>> result;
  for (int i = 0; i < primes.size() && primes[i] <= n; ++i) {
    int c = 0;
    while (n % primes[i] == 0) {
      c ++;
      n /= primes[i];
    }
    if (c != 0) {
      result.push_back({primes[i], c});
    }
  }
  return result;
}

// facts = result of factors(n)
int divisors(const vector<pair<int, int>> & facts) {
  int d = 1;
  for (int i = 0; i < facts.size(); ++i) {
    d *= (facts[i].second + 1);
  }
  return d;
}

// facts = result of factors(n)
int squareDivisors(vector<pair<int, int>> facts) {
  bool confirm = false;
  // set to false if not counting proper divisors
  bool isEvenPerfectSquare = true;

  for (int i = 0; i < facts.size(); ++i) {
    if (facts[i].second % 2 != 0) isEvenPerfectSquare = false;
    if (facts[i].first == 2 && facts[i].second >= 2) {
      confirm = true;
      facts[i].second -= 2;
    }
    facts[i].second /= 2;
  }

  int subtract = (confirm && isEvenPerfectSquare) ? 1 : 0;

  if (confirm)
    return divisors(facts) - subtract;
  else
    return 0;
}
