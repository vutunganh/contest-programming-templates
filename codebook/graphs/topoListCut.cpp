// Toposort: Odrezavani listu
// O(n + m), by _maty_
// vraci posloupnost indexu odpovidajici topologickemu usporadani
vector<int> topsort(vector<Vertex> & g) {
  vector<int> res;
  vector<int> s;
  for (int i = 0; i < g.size(); ++i) {
    if (g[i].deg_in == 0) s.push_back(i);
  }
  while (!s.empty()) {
    const int cur = s.back();
    s.pop_back();
    res.push_back(cur);

    for (int i = 0; i < g[cur].e.size(); ++i) {
      const int v = g[cur].e[i];
      g[v].deg_in --;
      if (g[v].deg_in == 0) {
        s.push_back(v);
      }
    }
  }
  return res;
}