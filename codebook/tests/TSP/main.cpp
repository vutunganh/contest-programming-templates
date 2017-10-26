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

using T = ll;
#define MX 11
T dist[MX][MX];
T dp[MX][1<<MX];

void init() {
    fill(*dp,*dp+sizeof(dp)/sizeof(T),-1);
}
T tsp(int pos, int vis) {
    if (not vis) return dist[pos][0];
    T& res = dp[pos][vis];
    T mix = INF;
    if (res == -1) {
        F(MX) {
            if ((1<<i) & vis) {
                mix = min(mix,tsp(i,vis ^ (1<<i)) + dist[pos][i]);
            }
        }
    }
    return mix;
}

int main(void) {
	ios_base::sync_with_stdio(false);
    IN(tcs);
    REP(t,tcs) {
        IN(xs) IN(ys);
        IN(sx) IN(sy);
        IN(bc);
        vector<pll> bp;
        bp.pb({sx,sy});
        F(bc) {
            IN(bx) IN(by);
            bp.pb({bx,by});
        }
        F(bc+1) FF(bc+1) {
            dist[i][j] = abs(bp[i].x - bp[j].x) + abs(bp[i].y - bp[j].y);
        }
        init();
        cout << "The shortest path has length " << tsp(0,(1<<(bc+1))-2) << endl;
    }
 	return 0;
}

