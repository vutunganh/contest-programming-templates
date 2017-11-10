#include "../template.cpp"

// Chinese Postman Problem a.k.a. Route Inspection Problem
// - find SHORTEST CLOSED path that visits ALL EDGES
// - connected, undirected G
// O(2^n * n^2)
//  Finds Eulerian circuit after adding "fake" edges that correspond to shortest
//  paths (FloydWarshal) between optimal pairs (DP) of odd-degree vertices
 
#define MX 15 // vertices
#define FFF(n) REP(k, n)
ll n;
ll M[MX][MX];
ll deg[MX];
ll DP[1<<MX];
// floyd warshall:
void fw() {
    FFF(n) F(n) FF(n) if (M[i][k]+M[k][j] < M[i][j]) {
        M[i][j] = M[i][k] + M[k][j];
    }
}
// choose best pairing of odd vertices
ll dp(ll msk) {
    ll &ret = DP[msk]; 
    if(msk==0) return 0;
    if(~ret)return ret; else ret=INF;
    F(n-1) FOR(j,i+1,n) if((msk & (1<<i)) && (msk & (1<<j))) {
        ret=min(ret, M[i][j] + dp(msk ^ ((1<<i)|(1<<j))));
    }
    return ret;
}

ll chinesePostman(vector<vpll> &g) {
    n=g.size();
    F(n) FF(n) M[i][j] = INF;
    CL(deg,0); CL(DP,-1);
    ll sum=0;
    F(n) for(auto e: g[i]) {
        ll j=e.x, c=e.y; // edge, cost
        M[i][j] = min(M[i][j], c); // multiple edges support
        deg[i]++;
        sum+=c;
    }
    sum/=2;
    fw();
    ll oddMask = 0;
    F(n) if(deg[i]&1) {dbg(i); oddMask |= 1<<i;}
    ll best = dp(oddMask);
    dbg(best);
    return best + sum;
}
