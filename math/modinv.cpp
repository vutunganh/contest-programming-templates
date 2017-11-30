// pouze pro prvociselne moduly
// vychazi z MFV
#define MOD ((ll)1e9+7)
inline ll mpow(ll b,ll ex=MOD-2){
  if(b==1)return 1;
  ll r=1;
  while(ex){
    if(ex&1)r=(r*b)%MOD;
    ex>>=1;
    b=(b*b)%MOD;
  }
  return r;
}
