#include <vector>
#include <cstdio>
#include <cstdint>
#include <iostream>

using namespace std;
struct Vertex {
  vector<int> edge;
  bool visited = false;
  int maxPath = 0;
};

vector<Vertex> vertex;

// max depth, max path
pair<int, int> dfs(int v, int d) {
  vertex[v].visited = true;

  int maxPath = 0;
  int d1 = 0, d2 = 0;
  int realMaxDepth = 0;
  bool visitedAny = false;
  for (int i = 0; i < vertex[v].edge.size(); ++ i) {
    if (vertex[ vertex[v].edge[i] ].visited) continue;
    visitedAny = true;

    pair<int, int> t = dfs(vertex[v].edge[i], d + 1);

    realMaxDepth = max(realMaxDepth, t.first);
    maxPath = max(maxPath, t.second);
    d2 = max(d2, t.first - d);
    if (d2 > d1) swap(d1, d2);
  }

  if (!visitedAny) {
    return make_pair(d, 0);
  }

  vertex[v].maxPath = max(d1 + d2, maxPath);
  vertex[v].visited = false;
  //cout << realMaxDepth << endl;
  return make_pair(realMaxDepth, vertex[v].maxPath);
}

int main() {
  int n;
  scanf("%d", &n);
  vertex = vector<Vertex>(n + 1);
  for (int i = 0; i < n - 1; ++ i) {
    int v, u;
    scanf("%d %d", &v, &u);
    vertex[v].edge.push_back(u);
    vertex[u].edge.push_back(v);
  }
  int R;
  scanf("%d", &R);

  dfs(R, 0);

  int Q;
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    int S;
    scanf("%d", &S);
    printf("%d\n", vertex[S].maxPath);
  }

  return 0;
}
