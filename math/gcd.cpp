// fasater than __gcd
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  while (a != 0) swap(b=b%a,a);
  return b;
}
