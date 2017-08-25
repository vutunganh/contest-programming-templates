#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define FOR(i,a,b) for (auto i = (a); i < (b); ++i)
#define F(a,b) FOR(i, (a), (b))
#define FF(a,b) FOR(j, (a), (b))
#define aa first
#define bb second
#define PB push_back
#define MOD ((int)1e9+7)
#define INF (1<<30)
#define LINF (1<<62LL)
#define EPS (1e-10)
#define EQ(a,b) (fabs(a - b) <= fabs(a + b) * EPS)

// tested http://www.spoj.com/problems/EZDIJKST/
#define NODES 10000

struct Edge
{
  int u;
  ull w;

  bool operator<(const Edge& a) const { return w < a.w; }
};

int s, t, N, M; // start, target, node count, vertex count
ull D[NODES]; // distances
vector<Edge> G[NODES]; // graph
int P[NODES]; // parents

void add_edge(int u, int v, ull w) { G[u].PB({v, w}); }

void dijkstra()
{
  F (0, NODES) D[i] = INF, P[i] = -1;
  D[s] = 0;
  priority_queue<Edge> Q;
  Q.push({s, D[s]});
  while (!Q.empty()) {
    int v = Q.top().u; Q.pop();
    for (const auto& e : G[v]) {
      if (D[e.u] > D[v] + e.w)
        D[e.u] = D[v] + e.w, P[e.u] = v, Q.push(e);
    }
  }
}

void solve()
{
  scanf(" %d %d", &N, &M);
  F (0, NODES) G[i].clear();
  F (0, M) {
    int u, v, w;
    scanf( "%d%d%d", &u, &v, &w);
    add_edge(u - 1, v - 1, w);
  }
  scanf("%d%d", &s, &t);
  s -= 1; t -= 1;
  dijkstra();
  if (D[t] == INF)
    printf("NO\n");
  else
    printf("%lld\n", D[t]);
}

int main(void)
{
  ios::sync_with_stdio(false);
  int T; scanf(" %d", &T);
  F (0, T)
    solve();

  return 0;
}
