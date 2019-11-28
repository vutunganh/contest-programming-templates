// O(N * ALPHA) construction
// taken from garbage collectors templates
struct SuffixTree {
  // Change N, ALPHA and toi
  enum { N = 400010, ALPHA = 'Z' - 'A' + 1 };
  int toi(char c) { return c - 'A'; }
  string a; // v = cur node, q = cur position
  int t[N][ALPHA],l[N],r[N],p[N],s[N],v=0,q=0,m=2;

  void ukkadd(int i, int c) {
suff:
    if (r[v]<=q) {
      if (t[v][c]==-1) { t[v][c]=m; l[m]=i;
        p[m++]=v; v=s[v]; q=r[v]; goto suff; }
      v=t[v][c]; q=l[v];
    }
    if (q==-1 || c==toi(a[q])) q++; else {
      l[m+1]=i; p[m+1]=m; l[m]=l[v]; r[m]=q;
      p[m]=p[v]; t[m][c]=m+1; t[m][toi(a[q])]=v;
      l[v]=q; p[v]=m; t[p[m]][toi(a[l[m]])]=m;
      v=s[p[m]]; q=l[m];
      while (q<r[m]) { v=t[v][toi(a[q])]; q+=r[v]-l[v]; }
      if (q==r[m]) s[m]=v; else s[m]=m+2;
      q=r[v]-(q-r[m]); m+=2; goto suff;
    }
  }

  SuffixTree(string a) : a(a) {
    fill(r,r+N,sz(a));
    memset(s, 0, sizeof(s));
    memset(t, -1, sizeof(t));
    fill(t[1],t[1]+ALPHA,0);
    s[0] = 1; l[0] = l[1] = -1; r[0] = r[1] = p[0] = p[1] = 0;
    rep(i,0,sz(a)) ukkadd(i, toi(a[i]));
  }

  // example : find longest common substring ( uses ALPHA = 28)
  pair<int,int> best;
  int lcs(int node, int i1, int i2, int olen) {
    if (l[node] <= i1 && i1 < r[node]) return 1;
    if (l[node] <= i2 && i2 < r[node]) return 2;
    int mask = 0, len = node ? olen + (r[node] - l[node]) : 0;
    rep(c,0,ALPHA) if (t[node][c] != -1)
      mask |= lcs(t[node][c], i1, i2, len);
    if (mask == 3)
      best = max(best, {len, r[node] - len});
    return mask;
  }
  static pair<int,int> LCS(string s, string t) {
    SuffixTree st(s + (char)('z' + 1) + t + (char)('z' + 2));
    st.lcs(0, sz(s), sz(s) + 1 + sz(t), 0);
    return st.best;
  }

  // example : find longest common prefix of any suffix of a and q.substr(idx);
  // shows how to walk through the tree
  int findCommon(string & q, int idx = 0) {
    return findCommonRec(t[0][toi(q[idx])], q, idx);
  }

  int findCommonRec(int node, string & q, int idx) {
    for (int i = l[node]; i < r[node] && idx < (ll)q.size(); ++ i) {
      if (a[i] != q[idx]) return idx;
      idx ++;
    }

    if (idx >= (ll)q.size() || t[node][toi(q[idx])] == -1) return idx;
    return findCommonRec(t[node][toi(q[idx])], q, idx);
  }
};
