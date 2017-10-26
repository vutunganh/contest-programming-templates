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
struct d_ {template<typename T> d_ & operator ,(const T & x) { cerr << ' ' <<  x; return *this;}} d_t;
#define D(args ...) { d_t,"|",__LINE__,"|",#args,":",args,"\n"; }
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define all(x) begin(x),end(x)
#define IN(n) ll n;cin >> n;
#define xx first
#define yy second

using ptt = double;
using pt = complex<ptt>;
#define x real()
#define y imag()
#define eq(x,y) (abs(x-(y)) <= EPS)
struct line { double a, b, c; };
#define dot(a,b) (conj(a)*(b)).x // dot product
#define crs(a,b) (conj(a)*(b)).y // cross product

// is polygon convex
// dependency (crs)
bool is_conv(vector<pt> pol) {
    int sz = pol.size();
    if (sz <= 3) return 1; // degenerative (choose arbitary)
    ptt pr = crs(pol[sz-1]-pol[0],pol[1]-pol[0]);
    F(sz-2) {
        ptt ac = crs(pol[i+1]-pol[i],pol[i+2]-pol[i]);
        if (ac*pr < -EPS) return 0;
        if (abs(ac) > pr) pr = ac;
    }
    return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
    vector<pt> pol = {pt(0,0), pt(2,0), pt(2,2), pt(0,0)};
    vector<pt> pol2 = {pt(-2,0), pt(2,0), pt(1,2), pt(-2,0)};
    vector<pt> pol3 = pol2;
    reverse(all(pol3));
    vector<pt> npol = {pt(0,0), pt(1,0), pt(2,0), pt(2,-2), pt(1,-1), pt(0,-2), pt(0,0)};
    D(is_conv(pol));
    D(is_conv(pol2));
    D(is_conv(pol3));
    D(is_conv(npol));
 	return 0;
}

