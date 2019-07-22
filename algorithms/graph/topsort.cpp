// O(n + m)
// vraci posloupnost indexu odpovidajici topologickemu usporadani
vector<int> topsort(const vector<vector<ll>> & g) {
  vector<int> res;
  vector<int> s;
  vector<int> deg_in(g.size());
  for (int i = 0; i < g.size(); ++ i)
    for (int j = 0; j < g[i].size(); ++ j)
      deg_in[g[i][j]] ++;
      
  for (int i = 0; i < g.size(); ++i)
    if (deg_in[i] == 0) s.push_back(i);

  while (s.size()) {
    const int cur = s.back();
    s.pop_back();
    res.push_back(cur);

    for (int i = 0; i < g[cur].e.size(); ++i) {
      const int v = g[cur].e[i];
      deg_in[v] --;
      if (!g[v].deg_in) s.push_back(v);
    }
  }
  return res;
}
