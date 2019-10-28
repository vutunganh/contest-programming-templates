// includes position of the maximum
struct MinAndAddPos {
  // value, position
  static pair<ll,ll> zero(ll idx) { return mp( 0, idx ); } // for sums
  static pair<ll,ll> lazyZero(ll idx) { return mp( 0, idx ); }
  static pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b) {
    return min(a, b);
  }
  // TOOO: lazy not tested
  static pair<ll,ll> lazyToNode(pair<ll,ll> node, pair<ll,ll> lazy, int len) {
    return {node.aa + lazy.aa, node.bb};
  }
  static pair<ll,ll> lazyToLazy(pair<ll,ll> old, pair<ll,ll> newV) {
    return {old.aa + newV.aa, old.bb};
  }
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
    F(2*n) lz[i] = O::lazyZero(0);
    memset(lzf, 0, 2*n*sizeof(bool));
    F(2*n) a[i] = O::zero(i - n);
  }

  SegmentTree() = default;

  SegmentTree(int _n):
    n(npow2(_n)) { alloc(n); build(); }

  SegmentTree(const SegmentTree & o): n(o.n) {
    alloc(n);
    memcpy(a, o.a, sizeof(*a) * 2*n);
    memcpy(lz, o.lz, sizeof(*lz) * 2*n);
    memcpy(lzf, o.lzf, sizeof(*lzf) * 2*n);
  }

  SegmentTree & operator = (const SegmentTree & o) {
    if (this == &o) return *this;
    n = o.n;
    alloc(n);
    memcpy(a, o.a, sizeof(*a) * 2*n);
    memcpy(lz, o.lz, sizeof(*lz) * 2*n);
    memcpy(lzf, o.lzf, sizeof(*lzf) * 2*n);
    return *this;
  }

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
      lz[nd] = O::lazyZero(-1);
    }
  }

  //# query left, query right, node, left range, right range
  Item get(ll l, ll r) { 
    assert(l <= r);
    return (r < l) ? O::zero(-1) : _get(l, r, 1, 0, n-1);
  }

  // closed interval, ie. [l, r]
  Item _get(ll l, ll r, ll nd, ll ndl, ll ndr) {
    propLazy(nd, ndr - ndl + 1);
    if (ndl >= l && ndr <= r) return a[nd]; 
    else if (ndr < l || ndl > r || ndr < ndl) return O::zero(-1); // zeroni prvek
    else return O::merge(_get(l, r, nd*2, ndl, ndl+(ndr-ndl)/2)
                ,_get(l, r, nd*2 + 1, ndl+(ndr-ndl)/2+1, ndr));
  }

  Item realVal(ll nd, ll len) {
    if (lzf[nd]) return O::lazyToNode(a[nd], lz[nd], len);
    else return a[nd];
  }

  Item update(ll l, ll r, ll v) { 
    assert(l <= r);
    return (r < l) ? O::zero(-1) : _update(l, r, v, 1, 0, n-1);
  }
  Item _update(ll l, ll r, ll v, ll nd, ll ndl, ll ndr) {
    if (ndr < l || ndl > r || ndr < ndl) return O::zero(-1);
    const ll len = ndr - ndl + 1;
    if (ndl >= l && ndr <= r) { //# fully in range
      lzf[nd] = true;
      lz[nd] = O::lazyToLazy(lz[nd], {v,0});
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
