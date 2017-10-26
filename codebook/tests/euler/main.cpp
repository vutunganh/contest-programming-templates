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

// Find euler path stored in forward_list in O(n)
// Initialize by add_edge
#define MV 50
#define ME 1000
vector<pll> g[MX]; // number of vertices
bitset<MX> used; // number of edges
deque<ll> pth;
int ec;
void init() {
    ec = 0;
    F(MX) g[i].clear();
    used.reset();
    pth.clear();
}

void add_edge(int f, int t) {
    g[t].pb({f,ec}); // if bidirectional
    g[f].pb({t,ec++});
}

void path(int i) {
    for(auto& e : g[i]) {
        if (used[e.y]) continue;
        used[e.y] = 1;
        path(e.x);
    }
    pth.push_front(i);
}
deque<ll> euler_path(int st) {
    path(st);
    return pth;
}




int main(void) {
	ios_base::sync_with_stdio(false);
    IN(tcs);
    REP(t,tcs) {
        init();
        if (t) cout << endl;
        IN(n);
        int vc;
        F(n) {
            IN(f) IN(t);
            add_edge(--f,--t);
            vc = f;
        }
        cout << "Case #" << t+1<< endl;
        int co = 0;
        int oi = -1;
        F(50) {
            if (g[i].size() % 2) co++,oi=i;
        }
        
        if (co == 0) {  euler_path(oi == -1 ? vc : oi); }
        if (co > 0 or used.count() != n) {
            cout << "some beads may be lost" << endl;
        }
        else {
            //euler_path(oi == -1 ? vc : oi);
            F(pth.size()-1) {
                cout << pth[i]+1 << " " << pth[i+1]+1 << endl;
            }
        }
    }

 	return 0;
}

