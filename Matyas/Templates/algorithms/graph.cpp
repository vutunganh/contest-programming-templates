//
// Created by maty on 7/8/17.
//

#include <climits>
#include <vector>
#include "../data-structures/union-find.cpp"

using namespace std;
typedef pair<int,int> P;

struct Vertex {
  vector<int> e;
  int deg_in;
  bool visited = false;
  int depth;
  vector<P> query;
};

// O(n + m)
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

// nalezne nejblizsi polecne predky na stromu pro predem zadanou mnozinu dvojic vrcholu.
// O(n * log*(n))
void treeLCA(int v = 0, vector<Vertex> & g, UnionFind & uf, vector<int> & results, int depth = 0) {
  g[v].visited = true;
  g[v].depth = depth;

  for (int i = 0; i < g[v].query.size(); ++i) {
    const int u = g[v].query[i].second;
    const int resultIndex = g[v].query[i].first;
    if (g[u].visited) {
      // vypocita vzdalenost dvou vrcholu (pocet hran cesty)
      // d(visited, u) = u.depth + v.depth - 2*lca(u, visited).depth
      results[resultIndex] = g[u].depth + g[v].depth - 2*g[ uf.root(u) ].depth;

      // vypocita nejblizsiho spolecneho predka
      //results[resultIndex] = uf.root(u);
    }
  }

  for (int i = 0; i < g[v].e.size(); ++i) {
    if (!g[ g[v].e[i] ].visited) {
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
