// operation for sum on iterval + set all on interval to val
template <class Item>
struct SumAndSet {
  static Item neutral() { return Item(0); } // for sums
  static Item merge(Item a, Item b) { return a+b; }
  static Item lazyToNode(Item lazy, int len) { return len*lazy; }
};

// type of data stored in the segment tree, a struct containing the operations
template <class Item,class Ops>
struct SegmentTree {
  int n;
  vector<Item> a; //# normal value
  vector<Item> lz; //# lazy value
  vector<bool> lzf; //# is lazy set

  Item neutral() { return Ops::neutral(); } // for sums
  Item merge(Item a, Item b) { return Ops::merge(a,b); }
  Item lazyToNode(Item lazy, int len) { return Ops::lazyToNode(lazy, len); }

  int npow2(int n) {return 1 << (int)ceil(log2(n)); }

  SegmentTree(int _n):
    n(npow2(_n)), a(vector<Item>(2*n)), lz(2*n), lzf(2*n) { build(); }

  SegmentTree(vector<Item> in): n(npow2(in.size())), lz(vector<Item>(2*n))
    , lzf(vector<bool>(2*n)) {
    a = vector<Item>(2*n);
    a.fill(a.begin()+n-1, in.begin(), in.end());
    build();
  }

  Item build(ll i = 1) {
    if (i >= n) return a[i];
    else return a[i] = merge(build(2*i), build(2*i + 1));
  }

  void propLazy(int nd, int len) {
    if (lzf[nd]) {
      a[nd] = lazyToNode(lz[nd], len);
      lzf[nd] = false;
      if (nd < n) {
        lz[2*nd] = lz[2*nd + 1] = lz[nd];
        lzf[2*nd] = lzf[2*nd+1] = true;
        lzf[nd] = false;
      }
    }
  }

  //# query left, query right, node, left range, right range
  Item get(ll l, ll r) { return _get(l, r, 1, 0, n-1); }
  Item _get(ll l, ll r, ll nd, ll ndl, ll ndr) {
    propLazy(nd, ndr - ndl + 1);
    if (ndl >= l && ndr <= r) return a[nd];
    else if (ndr < l || ndl > r || ndr < ndl) return neutral(); // neutralni prvek
    else {
      return merge(_get(l, r, nd*2, ndl, ndl+(ndr-ndl)/2)
                ,_get(l, r, nd*2 + 1, ndl+(ndr-ndl)/2+1, ndr));
    }
  }

  void update(ll l, ll r, ll v) { _update(l, r, v, 1, 0, n-1); }
  void _update(ll l, ll r, ll v, ll nd, ll ndl, ll ndr) {
    propLazy(nd, ndr - ndl + 1);
    if (ndl >= l && ndr <= r) { //# fully in range
      a[nd] = lazyToNode(v, ndr - ndl + 1);
      if (nd < n) {
        lz[nd*2] = lz[nd*2+1] = v;
        lzf[nd*2] = lzf[nd*2+1] = true;
      }
    } else if (ndr < l || ndl > r || ndr < ndl) return;
    else {
      _update(l, r, v, nd*2, ndl, ndl+(ndr-ndl)/2);
      _update(l, r, v, nd*2+1, ndl+(ndr-ndl)/2+1, ndr);
      a[nd] = merge(a[nd*2], a[nd*2+1]);
    }
  }
};
