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
  int find(int v) {
    return (v == parent[v]) ? v : parent[v] = find(parent[v]);
  }

  // zjisti, jestli jsou dva vektory ve stejne komponente
  bool check(int a, int b) {
    return find(a) == find(b);
  }

  // spoji dva vrcholy do jedne komponenty
  void do_union(int a, int b) {
    if (a == b) return;
    int ar = find(a), br = find(b);
    if (depth[ar] < depth[br]) {
      parent[ar] = br;
    } else if (depth[ar] > depth[br]) {
      parent[br] = ar;
    } else {
      parent[br] = ar;
      depth[ar] ++;
    }
  }
};
