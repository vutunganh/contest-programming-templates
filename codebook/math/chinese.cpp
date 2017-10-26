#include "extended_euclid.cpp"

// Chinese remainder theorem (special case): find z such that
// z % x = a, z % y = b.  Here, z is unique modulo M = lcm(x,y).
// Return (z,M).  On failure, M = -1.
pll chinese_remainder_theorem(ll x, ll a, ll y, ll b) {
  ll s, t;
  ll d = extended_euclid(x, y, s, t);
  if (a%d != b%d) return {0, -1};
  return {mod(s*b*x+t*a*y,x*y)/d, x*y/d};
}

// Chinese remainder theorem: find z such that
//  z % x[i] = a[i] for all i.
// Note that the solution is
// 	unique modulo M = lcm_i (x[i]).
// Return (z,M).  On failure, M = -1.
// 	Note that we do not require the a[i]'s to be relatively prime.
pll chinese_remainder_theorem(const vll &x, const vll &a) {
  pll ret = make_pair(a[0], x[0]);
  for (ll i = 1; i < x.size(); i++) {
    ret = chinese_remainder_theorem(ret.first, ret.second, x[i], a[i]);
    if (ret.second == -1) break;
  }
  return ret;
}