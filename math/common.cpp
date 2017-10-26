#include <utility>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> P;
using namespace std;

ll d(ll s) {
  return s;
}

struct Matrix {
  Matrix(int rows, int columns):
      m(vector<vector<ll>>{rows, vector<ll>(columns, 0)})
      , rows(rows)
      , columns(columns) {
  }
  Matrix(int size, bool unit = false):
      m(vector<vector<ll>>{size, vector<ll>(size, 0)})
    , rows(size), columns(size) {
    if (unit) {
      for (int i = 0; i < size; ++i) {
        m[i][i] = 1;
      }
    }
  }

  Matrix operator * (const Matrix & other) const {
    Matrix result(rows, columns);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          result.m[i][j] = d(d(result.m[i][j]) + d(d(m[i][k]) * d(other.m[k][j])));
        }
      }
    }
    return result;
  }

  vector<vector<ll>> m;
  int rows, columns;
};

// nejmensi spolecny delitel
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

// kombinacni cislo: (n k)
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

// kombinacni cislo: (n k) mod p
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

// vrati vektor vsech prvocisel <= upTo
// O(n^(3/2))
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

// vrati vektor vsech prvocisel <= upTo
// se slozitosti n * log(log(n))
vector<int> eratosthenes(int upTo) {
  vector<bool> sieve(upTo + 1, false);
  for (int i = 2; i <= upTo; ++i) {
    if (!sieve[i]) {
      for (int j = 2*i; j <= upTo; j += i) {
        sieve[j] = true;
      }
    }
  }

  vector<int> result;
  for (int i = 2; i <= upTo; ++i) {
    if (!sieve[i])
      result.push_back(i);
  }
  return result;
}

// vrati vektor prvocinitelnu n
// napr 12 = 2^2 * 3 vrati
// { (2, 2), (3, 1) }
// v case O(n^(1/2))
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

// pocet delitelu pro dany rozklad na prvocinitele
// facts = result of factors(n)
int divisorsCount(const vector<pair<int, int>> &facts) {
  int d = 1;
  for (int i = 0; i < facts.size(); ++i) {
    d *= (facts[i].second + 1);
  }
  return d;
}

// pocet delitelu ktere jsou ctverce
// facts = result of factors(n)
int squareDivisors(vector<pair<int, int>> facts) {
  bool confirm = false;
  // set to false if not counting proper divisorsCount
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
    return divisorsCount(facts) - subtract;
  else
    return 0;
}

// rychle umocnovani v case log(exp)
// ocekava ctvercovou matici
Matrix ipow(Matrix base, ll exp) {
  Matrix result(base.rows, true);
  while (exp)
  {
    if (exp & 1)
        result = result * base;
    exp >>= 1;
    base = base * base;
  }

  return result;
}

// rychle umocnovani v case log(exp)
ll ipow(ll base, ll exp) {
  ll result = 1;
  while (exp)
  {
    if (exp & 1)
        result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}

// rychle modularni umocnovani v case log(exp)
ll ipowMod(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp)
  {
    if (exp & 1) {
      result *= base;
      result %= mod;
    }
    exp >>= 1;
    base *= base;
    base %= mod;
  }

  return result;
}

// rozsireni eratosthenova site, pamatuje si jmensiho prvocinitele pro kazde cislo
// lze pouzit pro rozklad na prvocinitele v log(n)
vector<int> eratosthenesExt(int upTo) {
  vector<bool> v(upTo + 1, false);
  vector<int> sp(upTo + 1, 0);
  for (int i = 2; i <= upTo; ++i) {
    if (!v[i]) {
      for (int j = 2*i; j <= upTo; j += i) {
        if (!v[j]) {
          v[j] = true;
          sp[j] = i;
        }
      }
      sp[i] = i;
    }
  }
  sp[1] = 1;
  return sp;
}

// rychla faktorizace v O(log(n)) za pomoci rozsireneho sita
vector<P> fastFactors(int n, vector<int> & sieve) {
  int c;
  vector<P> divs;
  divs.push_back({sieve[n], 1});
  n /= sieve[n];
  while (n != 1) {
    c = sieve[n];
    if (divs.back().first != c) {
      divs.push_back({c, 1});
    } else {
      divs.back().second ++;
    }
    n = n/sieve[n];
  }
  return divs;
}

// pomocna funkce pro fastDivisors
void getDivs(vector<int> & res, vector<P> & divs, int t, int i) {
  if (i >= divs.size()) {
    res.push_back(t);
    return;
  }
  int n = t;
  for (int j = 0; j <= divs[i].second; ++j) {
    getDivs(res, divs, n, i + 1);
    n *= divs[i].first;
  }
}

// ziska delitele v asymptoticky optimalnim case
vector<int> fastDivisors(int n, vector<int> sieve) {
  vector<P> divs = fastFactors(n, sieve);
  vector<int> exp(divs.size(), 0);
  vector<int> result;

  getDivs(result, divs, 1, 0);
  return result;
}

// (x - y) % k
inline ll modsub(ll x, ll y, ll k) {
  return (x%k - y%k + k) % k;
}

