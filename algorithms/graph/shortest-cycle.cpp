// floyd warshall which remembers directions for every shortest path
// returns one of the shortest cycles
vector<ll> shortestCycle(vector<vector<ll>>& g) {
  vector<vector<ll>> mtx(g.size(), vector<ll>(g.size(), INF));
  vector<vector<ll>> dir(g.size(), vector<ll>(g.size(), -1));
  F(g.size()) {
    FF(g[i].size()) {
      mtx[i][g[i][j]] = 1; // replace with weigth
      dir[i][g[i][j]] = g[i][j];
    }
  }

  FOR(k,0,g.size()) {
    F(g.size()) {
      FF(g.size()) {
        if (mtx[i][k] + mtx[k][j] < mtx[i][j]) {
          mtx[i][j] = mtx[i][k] + mtx[k][j];
          dir[i][j] = dir[i][k];
        }
      }
    }
  }
  // find shortest len
  ll sz = INF;
  F(g.size()) sz = min(mtx[i][i], sz);
  if (sz >= INF) return vector<ll>();
  F(g.size()) {
    if (mtx[i][i] == sz) {
      vector<ll> res;
      ll cur = i;
      do {
        res.PB(cur);
        cur = dir[cur][i];
      } while (cur != i);
      return res;
    }
  }
  return vector<ll>(); // no cycle found
}
