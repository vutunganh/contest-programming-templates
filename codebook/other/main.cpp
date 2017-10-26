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
struct d_ {
    template<typename T> d_ & operator ,(const T & x) { cerr << ' ' <<  x; return *this;}
    template<typename T> d_ & operator ,(const vector<T> & x) { for(auto x: x) cerr << ' ' <<  x; return *this;}
} d_t;
#define D(args ...) { d_t,"|",__LINE__,"|",#args,":",args,"\n"; }
#define dbg(args ...) D(args)
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define all(x) begin(x),end(x)
#define IN(n) ll n;cin >> n;
#define x first
#define y second

#include <gtest/gtest.h>

ll part(ll l, ll r, vll & v) {
    ll med = v[l];
    swap(v[l],v[r-1]);
    ll ind = l;
    FOR(i,l,r) {
        if(v[i] < med) { 
            swap(v[ind],v[i]);
            ind++; 
        }
    }
    swap(v[ind],v[r-1]);
    return ind;
}

ll median(vll & v) {
    ll left = 0;
    if(v.size()==1) return v[0];
    while(left < v.size()/2) {
        left += part(left, v.size(), v);
    }
    return (v.size()%2 ? v[v.size()/2] : (v[v.size()/2] + v[v.size()/2+1])/2);
}

int main() {
    vll v = { 2, 5, 1, 8, 7, 9, 9, 1, 4, 2, 6, 7, 0, 3 };
    cout << median(v) << endl;  // 4
    return 0;
}

