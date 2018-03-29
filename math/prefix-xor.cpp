// calculates xor of numbers from 0 to a inclusive
ll xorSum(ll a) {
  if (a == 0) return 0;
  if (a == 1) return 1;
  ll output = ((a+1)/2)%2;

  F(62) {
    if (i == 0) continue;
    ll bit = (1LL << i);
    if (bit > a) return output;
    //cout << bit << endl;
    if ((a%(bit*2)) >= bit)
      output |= ((((ll)((a%(bit*2))-bit)+1)%2) << i);
  }
  return output;
}

ll subseqXorSum(ll a,b){
  ll res=0;
  res^=xorSum(a+b);
  res^=xorSum(a-1);
}
