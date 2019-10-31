// returns either one or two vertices
vector<ll> treeCenters(const vector<vector<ll>> & g) {
  ll n = g.size();
  depth = vector<ll>(n, -1);
  queue<ll> q;
  F(n) if (g[i].size() == 1) {
    q.push(i);
    depth[i] = 0;
  }
  
  while (q.size()) {
    ll cur = q.front();
    q.pop();
    F(g[cur].size()) {
      if (depth[g[cur][i]] == -1) {
        q.push(g[cur][i]);
        depth[g[cur][i]] = depth[cur] + 1;
      }
    }
  }
  ll mx = -1;
  F(n) mx = max(depth[i], mx);
  vector<ll> res;
  F(n) if (depth[i] == mx) res.PB(i);
  return res;
}
