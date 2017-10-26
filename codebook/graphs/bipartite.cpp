#include "../template.cpp"

bool isbip(vector<vll>& G, ll s = 0)
{
  vll c(G.size(), 2); c[s] = 0;
  queue<ll> q;q.push(s);
  while (q.size())
  {
    ll n = q.front(); q.pop();
    F(G[n].size())
    {
      ll v = G[n][i];
      if (c[v] == 2)
        c[v] = 1-c[n], q.push(v);
      else
        if (c[v] == c[n])
          return false;
    }
  }
  return true;
}
