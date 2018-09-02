// *** Floyd warshall
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
// ***
