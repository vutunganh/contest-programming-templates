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
#define x first
#define y second

#define MX 
vll g[MX];

int dp[MX][1<<MX];
void init() {
    CL(dp,-1);
}

int ham(int pos,int vis) {
    int& res = dp[pos][vis];
    if (res == -1) {
        res = -2;
        if (not vis) {
            for (auto& e : g[pos]) if (e == 0) res = 0; // hamiltonian cycle
            //res = 0; // hamiltonian path
        }
        else {
            for(auto& e : g[pos]) {
                if (vis & (1 << e) and ham(e,vis ^ (1 << e)) != -2) res = e;
            }
        }
    }
    return res;
}

int print() {
    int nx = 0;
    int vis = (1 << 20) - 2;
    while(vis) {
        cout << nx << endl;
        nx = ham(nx, vis);
        vis ^= (1 << nx);
    }
    cout << nx << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
    int f, t;
    while(cin >> f >> t) {
        g[f].pb(t);
        g[t].pb(f);
    }
    init();
    D(ham(0,(1<<20)-2));
    print();
 	return 0;
}

