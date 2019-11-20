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
ll ipowMod(ll base, ll exp, ll mod=MOD) {
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

