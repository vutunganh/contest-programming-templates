#include <iostream>
#include <vector>

// http://codeforces.com/problemset/problem/734/E

using namespace std;

struct Node {
  vector<int> links;
  int len;
  bool worst;
  int prev;
};

void flood(int cur, int prev, Node* nodes, int depth, int & maxDepth, int & maxDepthIndex) {
  nodes[cur].len = depth;
  for (int i = 0; i < nodes[cur].links.size(); ++i) {
    if (nodes[cur].links[i] != prev) {
      flood(nodes[cur].links[i], cur, nodes, depth + 1, maxDepth, maxDepthIndex);
    }
  }
  if (maxDepth < depth) {
    maxDepth = depth;
    maxDepthIndex = cur;
  }
}

void flood2(int cur, int prev, Node* nodes, int depth, int & maxDepth, int & maxDepthIndex, int* maxPathLen) {
  for (int i = 0; i < nodes[cur].links.size(); ++i) {
    if (nodes[cur].links[i] != prev) {
      flood2(nodes[cur].links[i], cur, nodes, depth + 1, maxDepth, maxDepthIndex, maxPathLen);
    }
  }
  maxPathLen[cur] = max(maxPathLen[cur], depth);
}

int main() {
  ios_base::sync_with_stdio(false);
  int count;
  while (cin >> count) {
    Node nodes[count];
    int maxPathLen[count];
    for (int i = 0; i < count; ++i) { maxPathLen[i] = -1; }

    for (int i = 0; i < count; ++i) {
      int n;
      cin >> n;
      for (int j = 0; j < n; ++j) {
        int k;
        cin >> k;
        nodes[i].links.push_back(k - 1);
      }
    }

    // flood
    int maxDepth = 0;
    int maxDepthIndex = -1;
    flood(0, -1, nodes, 0, maxDepth, maxDepthIndex);

    maxDepth = 0;
    int found = maxDepthIndex;
    flood2(found, -1, nodes, 0, maxDepth, maxDepthIndex, maxPathLen);

    int worst;
    maxDepth = 0;
    for (int i = 0; i < count; ++i) {
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
    for (int i = 0; i < count; ++i) {
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
    cout << "Best Roots  :";
    for (int i = 0; i < bestRoots.size(); ++i)
      cout << " " << bestRoots[i] + 1;
    cout << endl;

    cout << "Worst Roots :";
    for (int i = 0; i < worstRoots.size(); ++i)
      cout << " " << worstRoots[i] + 1;
    cout << endl;
  }
  return 0;
}
