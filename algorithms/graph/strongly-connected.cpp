void stDfs(ll k, const vector<vector<ll>>& g, vector<bool>& v, stack<ll>& st) {
  if (v[k]) return;
  v[k] = true;
  F(g[k].size()) stDfs(g[k][i], g, v, st);
  st.push(k);
}

void markDfs(ll k, vector<vector<ll>>& g, vector<ll>& res, ll comp) {
  if (res[k] != -1) return;
  res[k] = comp;
  F(g[k].size()) markDfs(g[k][i], g, res, comp);
}

// Strongly connected components of graph g. Returns vector a, such that a_i is the component of vertex v_i.
// the components are numbers from [0, (number of components) - 1]
vector<ll> strongComp(vector<vector<ll>>& g) {
  // flip the edges
  vector<vector<ll>> gt(g.size());
  F(g.size()) {
    FF(g[i].size()) {
      gt[g[i][j]].PB(i);
    }
  }
  vector<bool> v(g.size());
  stack<ll> st;
  F(g.size()) {
    if (!v[i]) stDfs(i, gt, v, st);
  }
  vector<ll> res(g.size(), -1);
  ll comp = 0;
  while (st.size()) {
    markDfs(st.top(), g, res, comp ++);
    while (st.size() && res[st.top()] != -1) st.pop();
  }
  return res;
}

// returns the dag of strongly connected components
// the vertex v_i is for the component with number i
vector<vector<ll>> condensationGraph(vector<vector<ll>>& g) {
  vector<ll> c = strongComp(g);
  ll total = c[0];
  F(c.size()) total = max(total, c[i]);
  vector<vector<ll>> rg(total+1);
  F(g.size()) {
    FF(g[i].size()) {
      if (c[i] != c[g[i][j]]) {
        rg[c[i]].PB(c[g[i][j]]);
      }
    }
  }
  return rg;
}
