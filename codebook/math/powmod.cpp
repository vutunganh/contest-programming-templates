#include "../template.cpp"

ll pw(ll n, ll k)
{
  ll r = 1;
  while (k)
  {
    if (k&1) r*=n;
    n*=n;k>>=1;
  }
  return r;
}

#define MD (1000000007)
#define MX (1<<19)
ll pwmod(ll n, ll k)
{
  ll r = 1;
  while (k)
  {
    if (k&1) r*=n, r%=MD;
    n*=n, n%=MD;k>>=1;
  }
  return r;
}

ll inv(ll a) { return pwmod(a, MD-2); }
ll IN[MX] = {1}, FA[MX] = {1};
void comp() {FOR(i, 1, MX) IN[i] = inv(FA[i]=FA[i-1]*i%MD); }
ll comb(ll n, ll k)
{
  return n < k ? 0 : (FA[n]*IN[k]%MD)*IN[n-k]%MD;
}
