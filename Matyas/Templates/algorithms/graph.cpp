//
// Created by maty on 7/8/17.
//

#include <climits>
#include <vector>

using namespace std;

struct Vertex {
  vector<int> e;
  int deg_in;
};

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

inline vector<vector<int>> createFloydWarsharMatrix(int v) {
  auto result = vector<vector<int>>{v, vector<int>(v, INT_MAX)};
  for (int i = 0; i < v; ++i) {
    result[i][i] = 0;
  }
  return result;
}
void floydWarshall(vector<vector<int>> & dist) {
  const int n = dist.size();
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }
}