#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
typedef long long ll;
vector<vector<int>> g;
vector<bool> v;
vector<bool> d;
int dfs(int n, int de) {
  if (v[n]) return 0;
  v[n] = true;
  d[n] = de;
  int ret = 0;
  for (int i = 0; i < g[n].size(); ++ i) {
    if (d[g[n][i] == de - 2 && v[g[n][i]]]) ret ++;
    dfs(g[n][i], de + 1);
  }
  return ret;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++ i) {
    int u, v;
    g = vector<vector<int>>(n);
    v = vector<bool>(n, false);
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll p3 = 0;
  for (int i = 0; i < n; ++ i) {
    p3 += (g[i].size())*(g[i].size()-1)/2LL;
  }
  cout << p3 - dfs(0, 0)*3 << endl;
}
