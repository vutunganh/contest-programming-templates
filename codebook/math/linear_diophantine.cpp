#include "gcd.cpp";
#include "mod_inverse.cpp";

// Computes x and y such that
// [ ax + by = c; ]
// ...on failure, x = y = -1

void linear_diophantine(ll a, ll b, ll c, ll &x, ll &y) {
  ll d = gcd(a,b);
  if (c%d) {
    x = y = -1;
  } else {
    x = c/d * mod_inverse(a/d, b/d);
    y = (c-a*x)/b;
  }
}