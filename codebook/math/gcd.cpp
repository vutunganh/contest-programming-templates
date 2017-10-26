// Finds gcd of numbers
// When not needed extended,
// use __gcd(a,b); but carefull -> exception when 0
ll gcd(ll a, ll b) {
  ll tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

ll lcm(ll a, ll b) {
    return a/gcd(a,b)*b;
}
