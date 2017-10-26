#include "../template.cpp"

// Toposort: DFS version
// O(V+E)
#define MX 100000 // vertices
bitset<MX> vis;
vll path; // reverse path
void tdfs(vector<vll>& G, ll n)
{
  vis[n] = 1;
  F(G[n].size())
    if (!vis[G[n][i]])
      tdfs(G, G[n][i]);
  path.pb(n);
}
void topo(vector<vll>& G)
{
  F(G.size()) if (!vis[i]) tdfs(G, i);
}
