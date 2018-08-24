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
  bool v = false;
  int depth;
  vector<P> query;
};

// O(n + m)
// vraci posloupnost indexu odpovidajici topologickemu usporadani
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

void treeDiameterRec(vector<Vertex> & g, int n, int depth, int & maxD, int & maxDIdx) {
  if (g[n].v) return;
  g[n].v = true;
  g[n].depth = depth;
  if (depth > maxD) {
    maxD = depth;
    maxDIdx = n;
  }

  for (int i = 0; i < g[n].e.size(); ++i) {
    treeDiameterRec(g, g[n].e[i], depth + 1, maxD, maxDIdx);
  }
}

int startOfLongestPath, endOfLongestPath;

// spocte sirku stromu (delku nejdelsi cesty)
int treeDiameter(vector<Vertex> & g) {
  int maxD = 0, maxDIdx;
  treeDiameterRec(g, 0, 0, maxD, maxDIdx);
  for (int i = 0; i < g.size(); ++i) g[i].v = false;
  startOfLongestPath = maxDIdx;

  maxD = 0;
  treeDiameterRec(g, maxDIdx, 0, maxD, maxDIdx);
  for (int i = 0; i < g.size(); ++i) g[i].v = false;
  endOfLongestPath = maxDIdx;

  return maxD;
}

// pomocna funkce
pair<bool, int> treeCenterRec(vector<Vertex> & g, int n, int depth, int diameter, int end) {
  if (g[n].v) return {false, -1};
  g[n].v = true;
  g[n].depth = depth;

  bool foundEnd = false;
  int endIdx = -1;
  if (n == end) {
    foundEnd = true;
  }

  for (int i = 0; i < g[n].e.size(); ++i) {
    auto a = treeCenterRec(g, g[n].e[i], depth + 1, diameter, end);
    foundEnd |= a.first;
    if (a.second != -1) {
      endIdx = a.second;
      break;
    }
  }

  if (foundEnd && depth == diameter/2) {
    endIdx = n;
    return {true, endIdx};
  }

  return {foundEnd, endIdx};
}

// nalezne nejaky stredu stromu
// O(n)
int treeCenter(vector<Vertex> & g) {
  int diameter = treeDiameter(g);
  int result = treeCenterRec(g, startOfLongestPath, 0, diameter, endOfLongestPath).second;
  for (int i = 0; i < g.size(); ++i) g[i].v = false;
  return result;
}

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

