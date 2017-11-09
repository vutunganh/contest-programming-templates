#include "../template.cpp"

// Toposort: DFS version
// O(V+E)
void tdfs(vector<vll>& g, ll n, vll &path, set<ll> &vis) {
  vis.insert(n);
  for(auto j: g[i]) if (!vis.count(j)) tdfs(G, j, path, vis);
  path.pb(n);
}
vll topo(vector<vll>& G) {
  vll path; set<ll> vis;
  F(G.size()) if (!vis.count(i)) tdfs(G, i, path, vis);
  reverse(all(path));
  return path;
}
