// Computes b such that ab = 1 (mod n), returns -1 on failure
ll mod_inverse(ll a, ll n) {
  ll x, y;
  ll d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x,n);
}

// using power
ll pw(ll n,ll k){
    ll r(1);
    while(k){
        if(k&1)r*=n,r%=MOD;
        n*=n,n%=MOD,k>>=1;
    }
    return r;
}
