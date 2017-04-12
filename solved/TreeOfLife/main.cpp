
#include <vector>
#include <cstdio>
#include <cstdint>
#include <iostream>

using namespace std;
struct Vertex {
  vector<int> edge;
  bool visited = false;
};

vector<Vertex> vertex;

int dfs(int v, int d = 0) {
  if (vertex[v].visited) return 0;
  if (d == 2) return 1;

  vertex[v].visited = true;

  int result = 0;
  for (int i = 0; i < vertex[v].edge.size(); ++ i) {
    result += dfs(vertex[v].edge[i], d + 1);
  }
  vertex[v].visited = false;
  return result;
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
  unsigned long long result = 0;
  for (int i = 1; i <= n; ++ i) {
    result += dfs(i, 0);
  }
  result = result / 2;
  //printf("%llu\n", result);
  cout << result << endl;

  return 0;
}