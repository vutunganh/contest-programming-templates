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
  ll top = 1;
  ll bottom = 1;
  for (ll i = n; i > k; -- i) {
    top *= i;
    top %= p;
  }
  for (ll i = n-k; i > 0; -- i) {
    bottom *= i;
    bottom %= p;
  }

  return ((top % p) * (mpow(bottom, p-2) % p)) % p;
}

// combination number with caching
inline ll d(ll n) {
  return n >= MOD ? n%MOD : n;
}

vector<ll> facts;
vector<ll> invFacts;
void precompFacts(int max) {
  facts = vector<ll>(max+1);
  invFacts = vector<ll>(max+1);
  ll cur = 1;
  facts[0] = invFacts[0] = 1;
  for (ll i = 1; i <= max; ++ i) {
    cur *= i;
    cur = d(cur);
    facts[i] = cur;
    invFacts[i] = mpow(facts[i]);
  }
}

ll Cp(ll n, ll k, ll mod = MOD) {
  if (n == k) return 1;
  if (k < 0 || n < 0) return 0;
  if (k == 0) return 1;
  return d(d(facts[n] * invFacts[n-k]) * invFacts[k]);
}
