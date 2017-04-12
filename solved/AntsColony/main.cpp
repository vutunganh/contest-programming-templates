#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  Edge(uint64_t len, int v) : len(len), v(v) {}
  Edge() = default;

  uint64_t len;
  int v;
};

struct Vertex {
  Vertex(): visited(false) {};
  vector<Edge> edges;
  unsigned long long depth;
  bool visited = false;
  vector<pair<int, int>> query;
};

vector<unsigned long long> results;
vector<int> parent;

int FindParent(vector<Vertex> & vertex, int a) {
  //if (a != parent[a]) return FindParent(vertex, parent[a]);
  //return a;
  return (a == parent[a]) ? a : parent[a] = FindParent(vertex, parent[a]);
}

// calculate depth
void DFS(vector<Vertex> & vertex, int cur, uint64_t depth) {
  //cout << " " << cur << endl;
  //cout << vertex[cur].edges[0].v << endl;

  vertex[cur].depth = depth;
  vertex[cur].visited = true;

  for (int i = 0; i < vertex[cur].query.size(); ++i) {
    if (vertex[ vertex[cur].query[i].second ].visited) {
      int p = FindParent(vertex, vertex[cur].query[i].second);
      results[vertex[cur].query[i].first] = vertex[cur].depth
                                             + vertex[ vertex[cur].query[i].second ].depth
                                             - 2 * vertex[p].depth;
    }
  }

  for (int i = 0; i < vertex[cur].edges.size(); ++ i) {
    if (vertex[ vertex[cur].edges[i].v ].visited == false) {
      DFS(vertex, vertex[cur].edges[i].v, depth + vertex[cur].edges[i].len);
      parent[vertex[cur].edges[i].v] = cur;
    }
  }
}

int main() {
  while (true) {
    int N;
    scanf("%d", &N);
    if (N == 0) break;

    vector<Vertex> vertex(N);
    parent = vector<int>(N);
    for (int i = 0; i < N; i ++) parent[i] = i;

    for (int i = 1; i <= N - 1; ++i) {
      unsigned long long Ai, Li;
      scanf("%llu %llu", &Ai, &Li);
      //cout << Ai << " " << Li << endl;
      vertex[i].edges.push_back(Edge(Li, (int)Ai));
      vertex[Ai].edges.push_back(Edge(Li, i));
    }

    int Q;
    scanf("%d", &Q);
    results = vector<unsigned long long>(Q);

    for (int i = 0; i < Q; ++i) {
      int S, T;
      scanf("%d %d", &S, &T);
      vertex[S].query.push_back({i, T});
      vertex[T].query.push_back({i, S});
    }

    DFS(vertex, 0, 0);

    for (int i = 0; i < Q - 1; ++ i) {
      printf("%llu ", results[i]);
    }
    printf("%llu\n", results[Q - 1]);
  }
  return 0;
}