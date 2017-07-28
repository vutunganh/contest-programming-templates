#include <vector>
using namespace std;
struct UnionFind {
  vector<int> parent;
  vector<int> depth;
  UnionFind(int n): parent(vector<int>(n)), depth(vector<int>(n, 0)) {
    for (int i = 0; i < n; ++ i) parent[i] = i;
  }

  // nalezne koren pro vrchol v
  // O(log*(n))
  int root(int v) {
    return (v == parent[v]) ? v : parent[v] = root(parent[v]);
  }

  // zjisti, jestli jsou dva vektory ve stejne komponente
  bool find(int a, int b) {
    return root(a) == root(b);
  }

  // spoji dva vrcholy do jedne komponenty
  void do_union(int a, int b) {
    if (a == b) return;
    if (depth[a] < depth[b]) {
      parent[a] = b;
    } else if (depth[a] > depth[b]) {
      parent[b] = a;
    } else {
      parent[b] = a;
      depth[a] ++;
    }
  }
};