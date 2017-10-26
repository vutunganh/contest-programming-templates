#include "mod.cpp"
#include "extended_euclid.cpp"

// Finds all solutions to 
// [ ax = b (mod n) ]]
vll modular_linear_equation_solver(ll a, ll b, ll n) {
  ll x, y;
  vll solutions;
  ll d = extended_euclid(a, n, x, y);
  if (!(b%d)) {
    x = mod(x*(b/d), n);
    for (ll i = 0; i < d; i++)
      solutions.pb(mod(x + i*(n/d), n));
  }
  return solutions;
}