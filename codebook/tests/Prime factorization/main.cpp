#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

#define pb push_back
#define FOR(i, m, n) for (ll i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
#define all(x) begin(x),end(x)
struct d_ {
    template<typename T> d_ & operator ,(const T & x) { cerr << ' ' <<  x; return *this;}
    template<typename T> d_ & operator ,(const vector<T> & x) { for(auto& x : x) cerr << ' ' <<  x; return *this;}
} d_t;
#define D(args ...) { d_t,"|",__LINE__,"|",#args,":",args,"\n"; }
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define IN(n) ll n;cin >> n;
#define x first
#define y second

#define MX 10000
bitset<MX> era;
ll sp[MX]; // for prime factorization (can be ommited)
// also in init function
vll pri;
void init() {
    era.set(); // all ones
    era[0] = era[1] = 0;
    FOR(i,2,MX) {
        if (!era[i]) continue;
        pri.pb(i);
        sp[i] = i;
        for (int m = 2; i*m < MX; m++) {
            if (era[i*m]) sp[i*m]=i;
            era[i*m] = 0;
        }
    }
}

// Prime factorization
// 3 simmilar functions, they differ in output type and speed
// fact (no dependency) list of prime factors O(log(N))
// sfact (erasthotenes computed to MX) count of each prime factor 
//         O(log(log(N)) + log(primes_to_mx))
// ffact (erasthotenes computed to sqrt(MX) + 1) 
//         list of prime factors O(log(log(N)))
vll fact(ll n) {
    assert(n>1);
    vll res;
    ll f = 2;
    while(f < sqrt(n) + 1) {
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
    while(pri[i] < sqrt(n) + 1) {
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


int main(void) {
	ios_base::sync_with_stdio(false);
    D(fact(22));
    D(fact(81));
    D(fact(5));
    D(fact(5304));
    init();
    D(sfact(22));
    D(sfact(81));
    D(sfact(5));
    D(sfact(5304));
    D(sfact(3163).size());
    D(ffact(22));
    D(ffact(81));
    D(ffact(5));
    D(ffact(5304));
    D(ffact(3163));
 	return 0;
}

