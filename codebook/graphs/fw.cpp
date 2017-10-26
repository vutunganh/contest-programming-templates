#include "../template.cpp"

// Floyd Warshall Algorithm
// All Pairs Shortest Path problem
// O(V^3)

#define FFF(n) REP(k, n)
ll M[MX][MX];
ll P[MX][MX];
// fw method ACed on https://www.codechef.com/IOIPRAC/problems/INOI1402
void fw(vector<vpll>& G)
{
  CL(P, -1);
  F(MX)FF(MX) M[i][j] = INF;
  F(G.size()) FF(G[i].size()) M[i][G[i][j].x] = G[i][j].y, P[i][G[i][j].x] = G[i][j].x;
  FFF(MX) F(MX) FF(MX)
  if (M[i][k] + M[k][j] < M[i][j])
  {
    M[i][j] = M[i][k] + M[k][j];
    P[i][j] = P[i][k];
  }
}
// Returns path a->b
vll fwp(ll a, ll b)
{
  vll res;
  if (~P[a][b]) return res;
  res.pb(a);
  while (a != b)
    a = P[a][b], res.pb(a);
  return res;
}
