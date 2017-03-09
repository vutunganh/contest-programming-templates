#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
  vector<int> links;
  int len;
  bool worst;
  int prev;
  int color;
};

void flood(int cur, int prev, Node* nodes, int depth, int & maxDepth, int & maxDepthIndex) {
  nodes[cur].len = depth;
  for (int i = 0; i < nodes[cur].links.size(); ++i) {
    if (nodes[cur].links[i] != prev) {
      int isDifferent;
      if (nodes[cur].color != nodes[nodes[cur].links[i]].color) isDifferent = 1;
      else isDifferent = 0;
      flood(nodes[cur].links[i], cur, nodes, depth + isDifferent, maxDepth, maxDepthIndex);
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
      int isDifferent;
      if (nodes[cur].color != nodes[nodes[cur].links[i]].color) isDifferent = 1;
      else isDifferent = 0;
      flood2(nodes[cur].links[i], cur, nodes, depth + isDifferent, maxDepth, maxDepthIndex, maxPathLen);
    }
  }
  maxPathLen[cur] = max(maxPathLen[cur], depth);
}

int main() {
  ios_base::sync_with_stdio(false);
  int count;
  cin >> count;

  while (true) {
    Node nodes[count + 1];
    int maxPathLen[count + 1];
    for (int i = 1; i <= count; ++i) { maxPathLen[i] = -1; }

    for (int i = 1; i <= count; ++i) {
      int n;
      cin >> n;
      nodes[i].color = n;
    }

    for (int i = 1; i <= count - 1; ++i) {
      int n, m;
      cin >> n >> m;
      nodes[m].links.push_back(n);
      nodes[n].links.push_back(m);
    }

    // flood
    int maxDepth = 0;
    int maxDepthIndex = -1;
    flood(1, -1, nodes, 1, maxDepth, maxDepthIndex);

    maxDepth = 0;
    int found = maxDepthIndex;
    flood2(found, -1, nodes, 1, maxDepth, maxDepthIndex, maxPathLen);

    int worst;
    maxDepth = 0;
    for (int i = 1; i <= count; ++i) {
      if (maxDepth < maxPathLen[i]) {
        worst = i;
        maxDepth = maxPathLen[i];
      }
    }

    flood2(worst, -1, nodes, 1, maxDepth, maxDepthIndex, maxPathLen);


    // najdi nejvzdalenejsi od nalezeneho

    // best roots
    int minLen = maxPathLen[1];
    int maxLen = maxPathLen[1];
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
    //cout << maxLen << endl;
    cout << floor(maxLen/2) << endl;
    break;
  }
  return 0;
}