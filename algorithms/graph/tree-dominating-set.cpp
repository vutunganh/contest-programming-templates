// zjisti velikost minimalniho dominujiciho setu na stromu
// zalozeno na greedy strategii: pridej do setu rodice kazdeho listu, odstran dominovane vrcholy, opakuj.
// returns whether the vertex is currently dominated and whether it is in the dominating set
pair<bool,bool> treeDomSet(const vector<vector<ll>> & g, vector<bool> & v, int u, int depth = 0) {
  v[u] = true;
  if (depth > 0 && g[u].size() == 1) return make_pair(false, false);
  bool inSet = false;
  bool isDominated = false;
  F(g[u].size()) {
    if (v[g[u][i]]) continue;
    auto t = treeDomSet(g, v, g[u][i], depth + 1);
    inSet |= !t.aa;
    isDominated |= t.bb;
  }
  if (inSet) res ++; // pridani vrcholu do setu
  return make_pair(isDominated || inSet, inSet);
}

