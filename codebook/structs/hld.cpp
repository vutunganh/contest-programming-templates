// SegmentTree with operations init,set,range modify,query
// Graph with vector<vector<int>>


template <class T, int V>
class SegmentTree {
  T seg[V];
public:
  T mrg(T a,T b) {
    return max(a,b);
  }
  T init(ll a) {
    return A[a];
  }
  void build(ll sz=V-1, ll st=0, ll en=V-1, ll p=1) {
    if (st == en)
      seg[p] = st < sz ? init(st) : T();
    else {
      build(sz,st,(st+en)/2,p*2);
      build(sz,(st+en)/2+1,en,p*2+1);
      seg[p] = mrg(seg[p*2],seg[p*2+1]);
    }
  }
  T get(ll st, ll en, ll sst=0,ll sen=V-1,ll p=1) {
    if (st > sen or en < sst) return T();
    if (st <= sst and en >= sen) return seg[p];
    ll mid = (sst+sen)/2;
    T lt = get(st,en,sst,mid,2*p);
    T rt = get(st,en,mid+1,sen,2*p+1);
    if (st <= mid and en > mid) return mrg(lt,rt);
    return st <= mid ? lt : rt;
  }
  T upd(ll pos,T val, ll sst=0,ll sen=V-1,ll p=1) {
    if (sst == sen) return seg[p] = val;
    ll mid = (sst+sen)/2;
    if (pos <= mid) return seg[p] = mrg(upd(pos,val,sst,mid,2*p),seg[2*p+1]);
    else return seg[p] = mrg(seg[2*p],upd(pos,val,mid+1,sen,2*p+1));
  }
}

template <class T, int V>
class HeavyLight {
  int parent[V], heavy[V], depth[V];
  // heavy: root of biggest subtree
  int root[V], treePos[V];
  // root of current chain, position in current chain
  SegmentTree<T> tree;

  template <class G>
  // calculates parent[], depth[] and heavy[]
  int dfs(const G& graph, int v) {
    int size = 1, maxSubtree = 0;
    for (int u : graph[v]) if (u != parent[v]) {
      parent[u] = v;
      depth[u] = depth[v] + 1;
      int subtree = dfs(graph, u);
      if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
      size += subtree;
    }
    return size;
  }

  template <class BinaryOperation>
  void processPath(int u, int v, BinaryOperation op) {
    for (; root[u] != root[v]; v = parent[root[v]]) { // iterate the heavier
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(treePos[u], treePos[v] + 1);
  }

public:
  template <class G>
  void init(const G& graph) {
    int n = graph.size();
    fill_n(heavy, n, -1);
    parent[0] = -1;
    depth[0] = 0;
    dfs(graph, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
      if (parent[i] == -1 || heavy[parent[i]] != i) // iterate chains
        for (int j = i; j != -1; j = heavy[j]) {
          root[j] = i;
          treePos[j] = currentPos++;
        }
    tree.init(n);
  }

  void set(int v, const T& value) {
    tree.set(treePos[v], value);
  }

  // void modifyPath(int u, int v, const T& value) {
  //   processPath(u, v, [this, &value](int l, int r) { tree.modify(l, r, value); });
  // }

  T queryPath(int u, int v) {
    T res = T();
    processPath(u, v, [this, &res](int l, int r) { res.add(tree.query(l, r)); });
    return res;
  }
};