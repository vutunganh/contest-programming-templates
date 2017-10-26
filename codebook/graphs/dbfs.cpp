#include "../template.cpp"

// vraci vektor vzdalenosti
vll bfs(vector<vll>& G, ll u)
{
  vll d(G.size(), -1);
  queue<ll> q; q.push(u);
  while (q.size())
  {
    auto u = q.front();q.pop();
    F(G[u].size())
    {
      ll v = G[u][i];
      if (~d[v])
      {
        d[v] = d[u] + 1;
        q.push(d[v]);
      }
    }
  }
  return d;
}

void dfs(vector<vll>& G, ll u, vll& res)
{
  res[u] = 1;
  F(G[u].size())
  {
    ll v = G[u][i];
    if (!res[v])
      dfs(G, v, res);
  }
}
