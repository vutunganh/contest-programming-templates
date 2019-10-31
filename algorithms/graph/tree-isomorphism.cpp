map<vector<ll>,ll> hsh;
set<ll> vis;
ll hashDfs(const vector<vector<ll>> & g, int v = 0) {
  vis.insert(v);
  vector<ll> r;
  F(g[v].size()) {
    if (!vis.count(g[v][i])) {
      r.PB(hashDfs(g[v][i], g));
    }
  }
  sort(r.begin(), r.end());
  if (hsh.find(r) != hsh.end()) return hsh[r];
  else return hsh[r] = hsh.size();
}
