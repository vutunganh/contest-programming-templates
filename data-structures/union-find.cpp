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

  void clear() {
    hp = 0;
    iota(parent.begin(), parent.end(), 0);
    fill(depth.begin(), depth.end(), 0);
  }
};

// persistentni varianta
UnionFindOp history[(ll)(1e7)]; // TODO: nastavit si konstantu
int hp = 0;

ll n, m, bl;
int st, en;

struct UnionFind {
  vector<int> parent;
  vector<int> depth;
  UnionFind() = default;

  UnionFind(int n): parent(vector<int>(n)), depth(vector<int>(n, 0)) {
    for (int i = 0; i < n; ++ i) parent[i] = i;
    hp = 0;
  }

  // nalezne koren pro vrchol v
  // O(log(n))
  // u perzistentni verze je na datech ~2x rychlejsi nez log*
  int find(int v) {
    assert(v < n);
    if (v == parent[v]) {
      return v;
    } else {
      return find(parent[v]);
    }
  }

  // zjisti, jestli jsou ve stejne komponente
  bool check(int a, int b) {
    return find(a) == find(b);
  }

  // spoji dva vrcholy do jedne komponenty
  void do_union(int a, int b) {
    if (check(a, b)) {
      history[hp] = UnionFindOp(a, parent[a], -1, true); // nic neudela
      hp ++;
      return;
    }
    int ar = find(a), br = find(b);
    assert(hp >= 0 && hp < 1e6);
    if (depth[ar] < depth[br]) {
      history[hp] = (UnionFindOp(ar, parent[ar], -1, true));
      hp ++;
      parent[ar] = br;
    } else if (depth[ar] > depth[br]) {
      history[hp] = (UnionFindOp(br, parent[br], -1, true));
      hp ++;
      parent[br] = ar;
    } else {
      history[hp] = (UnionFindOp(br, parent[br], ar, true));
      hp ++;
      parent[br] = ar;
      depth[ar] ++;
    }
  }

  // move one step back in history
  void goBack() {
    const auto & t = history[hp - 1];
    parent[t.v] = t.hisParent;
    if (t.changedDepth != -1) depth[t.changedDepth] --;
    hp --;
    if (hp > 0 && !history[hp - 1].u) goBack();
  }

  void clear() {
    hp = 0;
    iota(parent.begin(), parent.end(), 0);
    fill(depth.begin(), depth.end(), 0);
  }
};
