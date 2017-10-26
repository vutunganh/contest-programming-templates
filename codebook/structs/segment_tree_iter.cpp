/// WORK IN PROGRESS!!!

// Segment tree
// - efficient and succinct
// - values are stored on positions <n, 2n)
// - ! Works only for commutative (a+b = b+a) operations

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];
int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];

ll E = 0; // neutral
ll mrg(ll a, ll b) {
    return a+b;
}

void buildTree() {
    for (int i = n - 1; i > 0; --i)
        t[i] = mrg(t[i<<1], t[i<<1|1]);
}

void apply(int p, int value, int k) {
  t[p] = mrg(t[p], value);
  if (p < n) d[p] = mrg(d[p], value);
}

void applyLazy(int p) {
  while (p > 1)
      p >>= 1, t[p] = mrgLazy(mrg(t[p<<1], t[p<<1|1]),  d[p]);
}

// push all lazy values one step down
void push(int p) { 
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      applyLazy(i<<1, d[i], k);
      applyLazy(i<<1|1, d[i], k);
      d[i] = 0;
    }
  }
}

void upd(int l, int r, int value) {
  l += n, r += n;
  int l0 = l, r0 = r, k=1;
  for (; l < r; l >>= 1, r >>= 1, k<<=1) {
    if (l&1) apply(l++, value, k);
    if (r&1) apply(--r, value, k);
  }
  applyLazy(l0);
  applyLazy(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = E;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = mrg(res, t[l++]);
    if (r&1) res = mrg(t[--r], res);
  }
  return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}
