ll a[MX]; // input
ll n; // input size
ll par[MX]; // parent 
ll tl[MX];  // current max lis (not always lis)
vll lis(){ // largest strictly increasing subsequence
    ll sl = 0;
    tl[0] = -1;
    F(n) {
        auto le = lower_bound(tl+1,tl+sl+1,a[i],[&](ll i, ll b){return a[i] < b;});
        *le = i;
        par[i] = *(le - 1);
        sl = max(sl,(ll)(le-tl));
    }
    ll i = tl[sl];
    vll res;
    while(i != -1) {
        res.pb(a[i]);
        i = par[i];
    }
    reverse(all(res));
    return res;
}

