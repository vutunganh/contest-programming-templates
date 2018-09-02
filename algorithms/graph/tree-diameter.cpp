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

