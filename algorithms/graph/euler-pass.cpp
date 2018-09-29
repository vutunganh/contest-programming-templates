void _euler(vector<vector<ll>> &g, ll k, vector<pair<ll,ll>> &res, vector<bool> & v, ll &time) {
  if (v[k]) return;
  v[k] = true;
  res[k].first = time;
  time ++;
  F(g[k].size())
    _euler(g,g[k][i], res, v, time);
  res[k].second = time;
  time ++;
}
// euler pass, use if you want to make interval operations on subtrees
// for vertex i, result[i] = (start, end) of the subtree in the pass
vector<pair<ll,ll>> euler(vector<vector<ll>> &g, ll root) {
  vector<pair<ll,ll>> res(g.size()*2);
  vector<bool> v(g.size());
  ll time = 0;
  _euler(g, root, res, v, time);
  return res;
}
