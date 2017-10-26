// Prime factorization
// 3 simmilar functions, they differ in output type and speed
// fact (no dependency) list of prime factors O(sqrt(N))
// sfact (erasthotenes computed to MX) count of each prime factor 
//         O(sqrt(N)/log(N)) + log(MX))
// ffact (erasthotenes computed to MX)
//         list of prime factors O(log(N))
vll fact(ll n) {
    assert(n>1);
    vll res;
    ll f = 2;
    while(f*f <= n) {
        if ((n % f) == 0) {
            res.pb(f);
            n /= f;
        } 
        else f++;
    }
    if (n > 1) res.pb(n);
    return res;
}

vll sfact(ll n) {
    assert(n>1);
    vll res(1);
    int i = 0;
    while(pri[i]*pri[i] <= n) {
        if ((n % pri[i]) == 0) {
            res.back()++;
            n /= pri[i];
        }
        else {
            res.pb(0);
            i++;
        }
    }
    if (n > 1) {
        int ind = lower_bound(all(pri),n) - begin(pri);
        int zb = ind - res.size() + 1;
        F(zb) res.pb(0);
        res.back()++;
    }
    return res;
}

vll ffact(ll n) {
    assert(n>1);
    vll res;
    while(n > 1) {
        res.pb(sp[n]);
        n /= sp[n];
    }
    return res;
}

