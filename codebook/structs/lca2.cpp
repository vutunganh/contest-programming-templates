#include "../template.cpp"
#define MAX 100107
#define lMAX 20

// Lowest common ancestor - iterative version
// Doesn't recurse - use when stack would overflow.

// <O(NlogN),O(1)> where N=|E|
// usage: clear, n=X, addEdge, build, query, query, query, ...

ll n;
vll ng[MAX];
ll par[MAX];
ll dp[MAX][lMAX];
ll lev[MAX];

void build(ll root) {
    CL(lev,-1);
    queue<pair<ll,pll>> q;
    q.push({root,{-1,1}});
    while(q.size()) {
        auto act=q.front();q.pop();
        lev[act.x]=act.y.x;
        par[act.x]=act.y.y;
        for(auto i: ng[act.x]) {
            if(lev[i]!=-1) continue;
            q.push({i, {act.y.x+1, act.x}});
        }
    }
    CL(dp, -1);
    F(n) dp[i][0] = par[i];
    for (int j = 1; (1 << j) < n; j++) F(n) {
        if (dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
    }
}

int query(int p, int q)  {
    if (lev[p] < lev[q]) swap(p,q);
    ll log;
    for (log = 1; 1 << log <= lev[p]; log++);
    log--;
    for(ll i=log; i>=0; i--) if (lev[p] - (1 << i) >= lev[q]) {
        p = dp[p][i];
    }
    if (p==q)return p;
    for(ll i=log; i>=0; i--) if (dp[p][i] != -1 && dp[p][i] != dp[q][i]) {
        p = dp[p][i];
        q = dp[q][i];
    }
    return par[p];
}

void clear() {
    F(MAX) ng[i].clear();
    CL(par,-1);
}

void addEdge(ll i, ll j) {
    if(i>j) swap(i,j);
    ng[i].pb(j); ng[j].pb(i);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    n=7;
    addEdge(0,1); addEdge(1,2); addEdge(1,3); addEdge(3,4); addEdge(4,5);  addEdge(3,6);
    build(0);
    cout<<query(5,6)<<endl;
    cout<<query(2,6)<<endl;
    cout<<query(0,0)<<endl;
    return 0;
}