// operation for sum on iterval + set all on interval to val
template <class Item>
struct SumAndSet {
  static Item neutral() { return Item(0); } // for sums
  static Item merge(Item a, Item b) { return a+b; }
  static Item lazyToNode(Item lazy, int len) { return len*lazy; }
};


template <class Item>
struct GcdAndSet {
  static Item neutral() { return Item(0); } // for sums
  static Item merge(Item a, Item b) { return gcd(a,b); }
  static Item lazyToNode(Item lazy, Item node, int len) { return lazy; }
};

// type of data stored in the segment tree, a struct containing the operations
template <class Item,class O>
struct SegmentTree {
  int n;
  Item* a, *lz;
  bool* lzf;
  bool useLazy = true; // forbid lazy if TLe

  ~SegmentTree() {
    delete [] a;
    if (useLazy) {
      delete [] lz;
      delete [] lzf;
    }
  }

  int npow2(int n) {return 1 << (int)ceil(log2(n)); }

  void alloc(int n) {
    a = new Item[2*n];
    if (useLazy) {
      lz = new Item[2*n];
      lzf = new bool[2*n];
      F(2*n) lz[i] = O::neutral();
      memset(lzf, 0, 2*n*sizeof(bool));
    }
    F(2*n) a[i] = O::neutral();
  }

  SegmentTree(int _n):
    n(npow2(_n)) { alloc(n); build(); }

  SegmentTree(vector<Item> in): n(npow2(in.size())) {
    alloc(n);
    FOR(i,n,n+in.size()) a[i] = in[i-n];
    build();
  }

  Item build(ll i = 1) {
    if (i >= n) return a[i];
    else return a[i] = O::merge(build(2*i), build(2*i + 1));
  }

  void propLazy(int nd, int len) {
    if (!useLazy) return;
    if (lzf[nd]) {
      a[nd] = O::lazyToNode(lz[nd], len);
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
    if (useLazy) propLazy(nd, ndr - ndl + 1);
    if (ndl >= l && ndr <= r) return a[nd];
    else if (ndr < l || ndl > r || ndr < ndl) return O::neutral(); // neutralni prvek
    else {
      return O::merge(_get(l, r, nd*2, ndl, ndl+(ndr-ndl)/2)
                ,_get(l, r, nd*2 + 1, ndl+(ndr-ndl)/2+1, ndr));
    }
  }

  void update(ll l, ll r, ll v) { _update(l, r, v, 1, 0, n-1); }
  void _update(ll l, ll r, ll v, ll nd, ll ndl, ll ndr) {
    if (useLazy) propLazy(nd, ndr - ndl + 1);
    if (ndl >= l && ndr <= r) { //# fully in range
      a[nd] = O::lazyToNode(v, ndr - ndl + 1);
      if (nd < n && useLazy) {
        lz[nd*2] = lz[nd*2+1] = v;
        lzf[nd*2] = lzf[nd*2+1] = true;
      }
    } else if (ndr < l || ndl > r || ndr < ndl) return;
    else {
      _update(l, r, v, nd*2, ndl, ndl+(ndr-ndl)/2);
      _update(l, r, v, nd*2+1, ndl+(ndr-ndl)/2+1, ndr);
      a[nd] = O::merge(a[nd*2], a[nd*2+1]);
    }
  }
};
