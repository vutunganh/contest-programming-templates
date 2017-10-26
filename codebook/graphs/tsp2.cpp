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

#define MX 11

using ll = long long;

void bp(ll u,ll n) {
    F(n) cout<<((u&(1<<i))>0);
    cout<<endl;
}

struct Tsp {
	int n;
    int s = 0;
    ll DP[1<<(MX+1)][MX];
    ll D[MX][MX];
    Tsp() {
        CL(DP,-1);
        F(n)FF(n) {
            D[i][j] = 0;
        }
    }
    ll comp() {
        REP(mask,(1<<n)) {
            F(n) {
                ll prev = mask & ~(1<<i);
                if(mask==prev) continue;
                if(!prev) {
                    DP[mask][i]=D[s][i];
                    break;
                }
                ll lm = INF;
                FF(n) if(prev & 1<<j) {
                    lm=min(lm, DP[prev][j] + D[j][i]);
                }
                DP[mask][i] = lm;
            }
        }
        ll lm=INF;
        F(n) if(i!=s) lm=min(lm, D[i][s] + DP[(1<<n)-1-(1<<s)][i]);
        return lm;
    }
};

ll naive(Tsp & tsp) {
    vll v;
    F(tsp.n) if(i!=tsp.s) v.pb(i);
    ll lm = INF;
    do {
        ll r=tsp.D[tsp.s][v[0]];
        FOR(i,1,v.size()) r+=tsp.D[v[i-1]][v[i]];
        r+=tsp.D[v[v.size()-1]][tsp.s];
        lm=min(lm,r);
    } while(next_permutation(all(v)));
    return lm;
}

using Pt = pair<ll,ll>;
ll dist(Pt & a, Pt & b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

void test(vector<Pt> & v) {
    Tsp tsp;
    tsp.n=v.size();
    F(v.size())FF(v.size())tsp.D[i][j]=dist(v[i],v[j]);
    ll r1 = naive(tsp), r2 = tsp.comp();
    dbg(r1,r2);
    assert(r1==r2);
}

int main() {
    ios_base::sync_with_stdio(false);


    vector<Pt> v1 = {{0,0},{1,1},{2,4},{5,8},{2,6},{3,4}};
    test(v1);
    vector<Pt> v2 = {{0,0},{1,0},{2,0},{3,0}};
    test(v2);

    return 0;
}
