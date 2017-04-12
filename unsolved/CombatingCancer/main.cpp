#include <vector>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Vertex {
  vector<int> edge;
  bool visited = false;
  int len;
};

unordered_map<int, int> mapping;
vector<Vertex> tree1;
vector<Vertex> tree2;
int globalCount;











void flood(int cur, int prev, vector<Vertex> & nodes, int depth, int & maxDepth, int & maxDepthIndex) {
  nodes[cur].len = depth;
  for (int i = 0; i < nodes[cur].edge.size(); ++i) {
    if (nodes[cur].edge[i] != prev) {
      flood(nodes[cur].edge[i], cur, nodes, depth + 1, maxDepth, maxDepthIndex);
    }
  }
  if (maxDepth < depth) {
    maxDepth = depth;
    maxDepthIndex = cur;
  }
}

void flood2(int cur, int prev, vector<Vertex> & nodes, int depth, int & maxDepth, int & maxDepthIndex, int* maxPathLen) {
  for (int i = 0; i < nodes[cur].edge.size(); ++i) {
    if (nodes[cur].edge[i] != prev) {
      flood2(nodes[cur].edge[i], cur, nodes, depth + 1, maxDepth, maxDepthIndex, maxPathLen);
    }
  }
  maxPathLen[cur] = max(maxPathLen[cur], depth);
}

vector<int> main2(vector<Vertex> & nodes) {
  ios_base::sync_with_stdio(false);
  int count = nodes.size();
  int maxPathLen[count + 10];
  for (int i = 1; i <= count; i ++) maxPathLen[i] = 0;

    // flood
    int maxDepth = 0;
    int maxDepthIndex = -1;
    flood(1, -1, nodes, 0, maxDepth, maxDepthIndex);

    maxDepth = 0;
    int found = maxDepthIndex;
    flood2(found, -1, nodes, 0, maxDepth, maxDepthIndex, maxPathLen);

    int worst;
    maxDepth = 0;
    for (int i = 1; i <= count; ++i) {
      if (maxDepth < maxPathLen[i]) {
        worst = i;
        maxDepth = maxPathLen[i];
      }
    }

    flood2(worst, -1, nodes, 0, maxDepth, maxDepthIndex, maxPathLen);


    // najdi nejvzdalenejsi od nalezeneho

    // best roots
    int minLen = maxPathLen[0];
    int maxLen = maxPathLen[0];
    vector<int> bestRoots;
    vector<int> worstRoots;
    for (int i = 1; i <= count; ++i) {
      if (maxPathLen[i] < minLen) {
        bestRoots.clear();
        bestRoots.push_back(i);
        minLen = maxPathLen[i];
      } else if (maxPathLen[i] == minLen) {
        bestRoots.push_back(i);
      }

      if (maxPathLen[i] > maxLen) {
        worstRoots.clear();
        worstRoots.push_back(i);
        maxLen = maxPathLen[i];
      } else if (maxPathLen[i] == maxLen) {
        worstRoots.push_back(i);
      }
      //cout << i << ": " << maxPathLen[i] << endl;
    }

    /*cout << "Best Roots  :";
    for (int i = 0; i < bestRoots.size(); ++i)
      cout << " " << bestRoots[i] + 1;
    cout << endl;

    cout << "Worst Roots :";
    for (int i = 0; i < worstRoots.size(); ++i)
      cout << " " << worstRoots[i] + 1;
    cout << endl;*/



  return bestRoots;
}







int hashVector(vector<int> const &vec) {
  std::size_t seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return (int)seed;
}

int dfs(int v, vector<Vertex> & tree) {
  tree[v].visited = true;
  vector<int> types;

  for (int i = 0; i < tree[v].edge.size(); ++ i) {
    if (tree[ tree[v].edge[i] ].visited) continue;
    types.push_back(dfs(tree[v].edge[i], tree));
  }

  sort(types.begin(), types.end());

  int hash = hashVector(types);
  int result;
  if (mapping.find(hash) == mapping.end()) {
    globalCount ++;
    mapping.insert({hash, globalCount});
    result = globalCount;
  } else {
    result = mapping[hash];
  }

  return result;
}

void solve(int n) {
  int center = main2(tree1)[0];
  int target = dfs(center, tree1);
  cout << target << endl;
  vector<int> centers2 = main2(tree2);
  for (int i = 0; i < centers2.size(); ++ i) {
    int x;
    for (int j = 1; j <= n; ++ j) tree2[j].visited = false;
    x = dfs(centers2[i], tree2);
    if (x == target) {
      printf("S\n");
      return;
    }
    cout << x << endl;
  }
  printf("N\n");
}






















int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    mapping.clear();
    globalCount = 0;
    tree1 = vector<Vertex>(n + 5);
    for (int i = 1; i < n; ++ i) {
      int v, u;
      scanf("%d %d", &v, &u);
      tree1[v].edge.push_back(u);
      tree1[u].edge.push_back(v);
    }
    tree2 = vector<Vertex>(n + 5);
    for (int i = 1; i < n; ++ i) {
      int v, u;
      scanf("%d %d", &v, &u);
      tree2[v].edge.push_back(u);
      tree2[u].edge.push_back(v);
    }

    solve(n);
  }

  return 0;
}
