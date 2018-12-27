// automaton used for finding a set of strings inside another string
struct AhoCorasick {
  vector<string> patterns;
  const int PT = 1024; // number of patterns
  const int AL = 255; // alphabet size
  const int MX = (1 << 17); // max number of states in the automaton

  vector<bool> o = vector<bool>(PT);
  vector<vector<int>> g = vector<vector<int>>(MX, vector<int>(AL));
  vector<int> f = vector<int>(MX);
  int E;
  vector<int> q = vector<int>(MX);
  vector<vector<int>> O = vector<vector<int>>(MX);
  int cnt = 0;

  AhoCorasick() {
    ini();
  }

  void ini() {
    E = 1;
    for (auto&h: O) h.clear();
    F(AL)g[0][i] = 0;
  }

  void add(const string &s) { // call all add you need before build
    int L=s.size(), u = 0, c;
    int I = cnt ++;
    F(L) {
      if (!g[u][c = s[i]]) {
        g[u][c] = E++;
        F(AL) g[E - 1][i] = 0;
      }
      u = g[u][c];
    }
    O[u].PB(I);
  }

  void bld() { // run after running all adds
    int x, r, b = -1, e = 0, u;
    F(AL) if (g[0][i]) f[g[0][i]] = 0, q[e++] = g[0][i];

    while (++b < e) F(AL) {
      x = g[u=q[b]][i], r = g[f[u]][i];
      if (!x) g[u][i] = r;
      else {
        q[e++] = x, f[x] = r;
        for (auto&h: O[r]) O[x].PB(h);
      }
    }
  }

  // return the number of matched strings
  int search(const string & T) {
    int L=T.size(), u = 0, c;
    o = vector<bool>(PT, false);
    F(L) {
      c = T[i];
      while (u && !g[u][c]) u = f[u];
      u = g[u][c];
      for (auto& h: O[u]) {
        o[h] = 1;
      }
    }
    int res = 0;
    F(o.size()) res += o[i];
    return res;
  }
};
