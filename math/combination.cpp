ll C(ll n, ll k) {
  if (k == 0) return 1;
  if (n < k) return 0;
  if (k > n/2) return C(n, n-k);
  ll out = 1;
  for(int i = 1; i <= k; ++i) {
    out *= n-i+1;
    out /= i;
  }

  return out;
}
// the module must be prime
ll Cmod(ll n, ll k, ll p) {
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

  return ((top % p) * (mpow(bottom, p-2) % p)) % p;
}

