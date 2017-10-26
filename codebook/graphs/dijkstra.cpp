// Dijkstra's algorithm
// shortest paths from src to all vertices in the given graph
// directed, weighted, negative NOT ALLOWED!!

// O(VLogV)

#include "../template.cpp"

#define MX 207
// {neighbour, cost}
vpll dijkstra(vector<vpll>& G, ll s)
{
  ll S = G.size();
  vpll res(S, {0, INF});
  res[s] = {s, 0};
  bitset<MX> closed;
  priority_queue<pll, vpll, greater<pll>> Q;
  Q.push({0, s});
  while (Q.size()) {
    pll top = Q.top(); Q.pop();
    // if (end == top.y) break;
    ll cost = top.x, next = top.y;
    if (!closed[next]) {
      closed[next] = 1;
      F(G[next].size()) {
        ll v = G[next][i].x;
        ll ncost = cost + G[next][i].y;
        if (ncost < res[v].y)
        {
          res[v] = {next, ncost};
          Q.push({ncost, v});
        }
      }
    }
  }
  return res;
}
