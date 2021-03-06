using vi = vector<int>;
#define FOR(i,a,b) for (auto i = (a); i < (b); ++i)
#define F(a,b) FOR(i, (a), (b))

#define MAXN1 (10000)
#define MAXN2 (10000)
#define TOT (MAXN1 + MAXN2 + 1)

int t, D[TOT], PE1[TOT], PE2[TOT];
vi G[TOT];

void add_edge(int u, int v)
{
  G[u].PB(v); G[v].PB(u);
}

bool bfs()
{
  queue<int> Q;
  F (0, N)
    if (PE1[i] == t)
      D[i] = 0, Q.push(i);
    else
      D[i] = INF;
  D[t] = INF;
  while(!Q.empty()) {
    int v = Q.front(); Q.pop();
    if (D[v] < D[t])
      for (auto w : G[v])
        if (D[PE2[w]] == INF)
          D[PE2[w]] = D[v] + 1, Q.push(PE2[w]);
  }
  return D[t] != INF;
}

bool dfs(int v)
{
  if (v != t) {
    for (auto w : G[v])
      if (D[PE2[w]] == D[v] + 1 && dfs(PE2[w]))
        return PE2[w] = v, PE1[v] = w, true;
    D[v] = INF;
    return false;
  }
  return true;
}

int hopcroft_karp()
{
  F (0, TOT)
    PE1[i] = t, PE2[i] = t;

  int res = 0;
  while(bfs())
    F (0, N)
      if (PE1[i] == t && dfs(i))
        ++res;

  return res;
}
