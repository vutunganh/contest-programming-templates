struct Vertex {
  vector<int> e;
  int deg_in;
  bool v = false;
  int depth;
  vector<pll> query;
};

// nalezne nejblizsi polecne predky na stromu pro predem zadanou mnozinu dvojic vrcholu.
// O(n * log*(n))
void treeLCA(int v = 0, vector<Vertex> & g, UnionFind & uf, vector<int> & results, int depth = 0) {
  g[v].v = true;
  g[v].depth = depth;

  for (int i = 0; i < g[v].query.size(); ++i) {
    const int u = g[v].query[i].second;
    const int resultIndex = g[v].query[i].first;
    if (g[u].v) {
      // vypocita vzdalenost dvou vrcholu (pocet hran cesty)
      // d(v, u) = u.depth + v.depth - 2*lca(u, v).depth
      results[resultIndex] = g[u].depth + g[v].depth - 2*g[ uf.root(u) ].depth;

      // vypocita nejblizsiho spolecneho predka
      //results[resultIndex] = uf.root(u);
    }
  }

  for (int i = 0; i < g[v].e.size(); ++i) {
    if (!g[ g[v].e[i] ].v) {
      treeLCA(g[v].e[i], g, uf, results, depth + 1);
      uf.parent[g[v].e[i]] = v;
    }
  }
}
// pridani dotazu pro treeLCA. Vraci index, na kterem se bude nachazet vysledek
// v poli results.
int addTreeLCAQuery(vector<Vertex> & g, vector<int> & results, int v, int u) {
  g[v].query.push_back({results.size(), u});
  g[u].query.push_back({results.size(), v});
  const int r = (int) results.size();
  results.push_back(0);
  return r;
}

