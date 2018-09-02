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
