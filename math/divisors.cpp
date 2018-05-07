vll divisors(ll n){
  vll a,b;
  for(ll i=1;i<=(n+i-1)/i;++i)
    if(n%i==0)a.PB(i),b.PB(n/i);
  if(b.back()==a.back())b.pop_back();
  reverse(b.begin(),b.end());
  a.insert(a.end(),b.begin(),b.end());
  return a;
}
