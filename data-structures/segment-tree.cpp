// operation for sum on iterval + set all on interval to val
template <class Item>
struct SumAndAdd {
  static Item neutral() { return Item(0); } // for sums
  static Item merge(Item a, Item b) { return a+b; }
  static Item lazyToNode(Item node, Item lazy, ll len) { return node + len*lazy; }
  static Item lazyToLazy(Item old, Item newV) { return old + newV; }
};

template <class Item>
struct SumAndSet {
  static Item neutral() { return Item(0); } // for sums
  static Item merge(Item a, Item b) { return a+b; }
  static Item lazyToNode(Item node, Item lazy, int len) { return len*lazy; }
  static Item lazyToLazy(Item old, Item newV) { return newV; }
};

// type of data stored in the segment tree, a struct containing the operations
template <class Item,class O,class LazyItem = Item>
struct SegmentTree {
  int n;
  Item* a;
  LazyItem *lz;
  bool* lzf;

  ~SegmentTree() {
    delete [] a;
    delete [] lz;
    delete [] lzf;
  }

  int npow2(int n) {return 1 << (int)ceil(log2(n)); }

  void alloc(int n) {
    a = new Item[2*n];
    lz = new LazyItem[2*n];
    lzf = new bool[2*n];
    F(2*n) lz[i] = O::neutral();
    memset(lzf, 0, 2*n*sizeof(bool));
    F(2*n) a[i] = O::neutral();
  }

  SegmentTree(int _n):
    n(npow2(_n)) { alloc(n); build(); }

  SegmentTree(vector<Item> & in): n(npow2(in.size())) {
    alloc(n);
    FOR(i,n,n+in.size()) a[i] = in[i-n];
    build();
  }

  Item build(ll i = 1) {
    if (i >= n) return a[i];
    else return a[i] = O::merge(build(2*i), build(2*i + 1));
  }

  void propLazy(int nd, ll len) {
    if (lzf[nd]) {
      a[nd] = O::lazyToNode(a[nd], lz[nd], len);
      if (nd < n) {
        lz[2*nd] = O::lazyToLazy(lz[2*nd], lz[nd]);
        lz[2*nd+1] = O::lazyToLazy(lz[2*nd+1], lz[nd]);
        lzf[2*nd] = lzf[2*nd+1] = true;
      }
      lzf[nd] = false;
      lz[nd] = O::neutral();
    }
  }

  //# query left, query right, node, left range, right range
  Item get(ll l, ll r) { 
    return (r < l) ? O::neutral() : _get(l, r, 1, 0, n-1);
  }
  Item _get(ll l, ll r, ll nd, ll ndl, ll ndr) {
    propLazy(nd, ndr - ndl + 1);
    if (ndl >= l && ndr <= r) return a[nd]; 
    else if (ndr < l || ndl > r || ndr < ndl) return O::neutral(); // neutralni prvek
    else return O::merge(_get(l, r, nd*2, ndl, ndl+(ndr-ndl)/2)
                ,_get(l, r, nd*2 + 1, ndl+(ndr-ndl)/2+1, ndr));
  }

  Item realVal(ll nd, ll len) {
    if (lzf[nd]) return O::lazyToNode(a[nd], lz[nd], len);
    else return a[nd];
  }

  Item update(ll l, ll r, ll v) { 
    return (r < l) ? O::neutral() : _update(l, r, v, 1, 0, n-1);
  }
  Item _update(ll l, ll r, ll v, ll nd, ll ndl, ll ndr) {
    if (ndr < l || ndl > r || ndr < ndl) return O::neutral();
    const ll len = ndr - ndl + 1;
    if (ndl >= l && ndr <= r) { //# fully in range
      lzf[nd] = true;
      lz[nd] = O::lazyToLazy(lz[nd], v);
      propLazy(nd, len);
      return a[nd];
    } else {
      propLazy(nd, len);
      _update(l, r, v, nd*2, ndl, ndl+(ndr-ndl)/2);
      _update(l, r, v, nd*2+1, ndl+(ndr-ndl)/2+1, ndr);
      return a[nd] = O::merge(realVal(nd*2, len/2), realVal(nd*2+1, len/2));
    }
  }
};
