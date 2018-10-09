// returns -1 if the n-th root of n is not an integer
ll iroot(ll n, ll root) {
  ll bot = 0;
  ll top = pow(numeric_limits<ll>::max(), 1.0/root) - 100;
  while (top > bot) {
    ll mid = (top+bot+1)/2;
    ll p = ipow(mid, root);
    if (p > n) top = mid - 1;
    else if (p < n) bot = mid;
    else return mid;
  }
  return -1;
}
