#define MAX 1000001
// v arrayi nesmi byt zaporna cisla
ll T[MAX]; // T[0] se nepouziva!!!

// nabuildi z toho, co v arrayi lezi (asi)
void build(){
  FOR(i,1,MAX){
    int nextindex=i+(i&-i);
    if(nextindex<=MAX)T[nextindex]+=T[i];
  }
}

void add(int i,ll delta){while(i<=MAX)T[i]+=delta,i+=(i&-i);}

ll pref_sum(int i){
  ll s=0;
  while(i>0)s+=T[i],i=i&(i-1);
  return s;
}

ll get(int l,int r){return pref_sum(r)-pref_sum(l-1);}



// sealed in a structure
// modified so we can use index 0
struct Fenwick {
  ll n;
  vector<ll> t;
  Fenwick(ll n): n(n), t(n+1) {
    build();
  }
  Fenwick(vector<ll> in): n(in.size()) {
    t = vector<ll>(1);
    t.insert(t.end(), in.begin(), in.end());
    build();
  }

  void build(){
    FOR(i,1,n+1){
      int nextindex=i+(i&-i);
      if(nextindex<=n)t[nextindex]+=t[i];
    }
  }

  void add(int i,ll delta){i++; while(i<=n)t[i]+=delta,i+=(i&-i);}

  ll pref_sum(int i){
    i++;
    ll s=0;
    while(i>0)s+=t[i],i=i&(i-1);
    return s;
  }

  // get sum on interval [l, r]
  ll get(int l,int r){return pref_sum(r)-pref_sum(l-1);}
};
