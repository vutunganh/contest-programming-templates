struct SmartMatrix {
  // rows, columns
  ll n, m;
  void buildpf() {
    pf[0][0] = a[0][0];
    FOR(j,1,m) pf[0][j] = pf[0][j-1] + a[0][j];
    FOR(i,1,n) pf[i][0] = pf[i-1][0] + a[i][0];
    FOR(i,1,n) {
      FOR(j,1,m) {
        pf[i][j] = pf[i][j-1] + pf[i-1][j] - pf[i-1][j-1] + a[i][j];
      }
    }
  }
  SmartMatrix(ll n, ll m): n(n), m(m), a(vector<vector<ll>>(n, vector<ll>(m)))
  , pf(vector<vector<ll>>(n, vector<ll>(m))) {
  };
  vector<vector<ll>> a;
  vector<vector<ll>> pf;
  /*
     X(r1, c1)
          

            X(r2, c2)
     */
  ll sum(ll r1, ll c1, ll r2, ll c2) {
    ll res = pf[r2][c2];
    if (c1 > 0) res -= pf[c1 - 1][r2];
    if (r1 > 0) res -= pf[c2][r1 - 1];
    if (r1 > 0 && c1 > 0) res += pf[c1 - 1][r1 - 1];
    return res;
  }
};
