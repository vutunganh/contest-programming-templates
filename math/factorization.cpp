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

// rychla faktorizace v O(log(n)) za pomoci rozsireneho sita
vector<P> fastFactors(int n, vector<int> & sieve) {
  int c;
  vector<P> divs;

  if (sieve[n] == 1)
    divs.push_back({sieve[n], 0});
  else
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

