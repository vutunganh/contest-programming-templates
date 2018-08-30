struct Edge {
  ll u, v, w;
  bool operator < (const Edge & o) const {
    return mp(w, mp(u, v)) < mp(o.w, mp(o.u, o.v));
  }
};


// Kruskal, ktery vrati nejtezsi hranu na ceste v kostre mezi zadanou dvojici vrcholu. Nasklada se do
// q jako dvojice vrcholu a na stejnych indexech je pak vaha hrany.

// edges are expected to have numbers from 0 to n-1
// returns the edges of the MST and the maximum weight edge between the set of pairs of vertices in q
pair<vector<Edge>, vector<ll>> kruskalMaxEdge(vector<Edge> & e, ll n, vector<pair<ll,ll>> q = vector<pair<ll,ll>>()) {
  sort(e.begin(), e.end());
  UnionFind uf(n);
  map<ll, unordered_set<ll>*> vToQ; // maps vertices to queries
  F(n) vToQ[i] = new unordered_set<ll>();
  F(q.size()) {
    vToQ[q[i].aa]->insert(i);
    vToQ[q[i].bb]->insert(i);
  }

  // kruskal starts here
  vector<Edge> res;
  vector<ll> queryRes(q.size());
  F(e.size()) {
    if (uf.check(e[i].u, e[i].v)) continue; // would create a cycle
    res.PB(e[i]);

    // make union of query sets and also find intersection
    auto bigger = (vToQ[uf.find(e[i].u)]->size() > vToQ[uf.find(e[i].v)]->size() ?
        vToQ[uf.find(e[i].u)] : vToQ[uf.find(e[i].v)]);
    auto smaller = (vToQ[uf.find(e[i].u)]->size() <= vToQ[uf.find(e[i].v)]->size() ?
        vToQ[uf.find(e[i].u)] : vToQ[uf.find(e[i].v)]);

    // check for the queries
    uf.do_union(e[i].u, e[i].v);
    // move the bigger set into the current parent
    vToQ[uf.find(e[i].u)] = bigger;

    // insert the smaller into bigger
    for (ll x: *smaller) {
      if (!bigger->insert(x).second) { // query in both components
        queryRes[x] = e[i].w;
        bigger->erase(x);
      }
    }
    delete smaller;
  }
  return {res, queryRes};
}


// Lehci verze Kruskala ktera pouze vrati minimalni kostru
vector<Edge> kruskal(vector<Edge> & e, ll n) {
  sort(e.begin(), e.end());
  UnionFind uf(n);

  vector<Edge> res;
  F(e.size()) {
    if (uf.check(e[i].u, e[i].v)) continue; // would create a cycle
    res.PB(e[i]);
    uf.do_union(e[i].u, e[i].v);
  }
  return res;
}
