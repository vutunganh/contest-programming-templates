// extended Simon's code

struct ResidualEdge {
  int start;
  int v;
  double cost;
  int flow;
};

struct ResidualGraph {
  vector<vector<ResidualEdge>> g;
  map<pair<int,int>,int> cap;
  map<pair<int,int>, double> cost;
};

struct NetworkEdge {
  int from, to;
  int cap;
  double cost;
  bool allow = true;
  NetworkEdge(int from, int to, int cap, double cost):
    from(from), to(to), cap(cap), cost(cost) {}
};

class Network {
public:
  Network(int n): vertices(n), ng(vector<vector<int>>(n)), back(vector<int>(n)) { }
  void AddEdge(int from, int to, int capacity, double cost);
  int MaxFlow(int start, int target);
  void DeleteEdge(int from, int to) {
    for (int i: edgeToIdx[{from,to}]) {
      edges[i].allow = false;
    }
  }
  map<pair<int,int>, int> flowOnEdge;
  map<pair<int,int>, int> origCap;
  vector<pair<int,int>> origEdges;
  map<pair<int,int>, double> costs;
  void MinCost(int n, ofstream & out);

//private:
  int vertices;
  vector<vector<int>> ng; // indexes of edges
  vector<int> back; // indexes of edges for reconstructing augment path
  vector<NetworkEdge> edges;

  map<pair<int,int>,vector<int>> edgeToIdx;
  map<int,pair<int,int>> idxToEdge;


  bool AugementPath(int s, int t);
  pair<double,vector<int>> BellmanFord();
  ResidualGraph CreateResidual();
  bool BellmanFord(ResidualGraph & g);
};

void Network::AddEdge(int from, int to, int capacity, double cost) { // 2 edges, back is residual, accessible by ^1 (even/odd)
  ng[from].push_back(edges.size());
  edgeToIdx[{from,to}].PB(edges.size());
  idxToEdge[edges.size()] = {from,to};
  edges.push_back(NetworkEdge(from, to, capacity, cost));
  origEdges.PB({from, to});
  costs[{from, to}] = cost;

  ng[to].push_back(edges.size());
  //idxToEdge[edges.size()] = {from,to};
  edgeToIdx[{from,to}].PB(edges.size());
  edges.push_back(NetworkEdge(to, from, 0, cost));
  origCap[{from,to}] = capacity;
}

bool Network::AugementPath(int s, int t) { // source,sink
  for(int i = 0; i < vertices; ++ i) back[i] = -1;
  back[s] = -2;

  stack<int> q; q.push(s);
  while (!q.empty() && back[t] == -1) { // exists augment path to sink
    int u = q.top(); q.pop();
    for (int i : ng[u]) {
      NetworkEdge & edge = edges[i];
      if (!edge.allow) continue;

      if (edge.cap && back[edge.to] == -1) { // has capacity
        back[edge.to] = i;
        q.push(edge.to);
      }
    }
  }
  return back[t] != -1;
}

int Network::MaxFlow(int start, int target) {
  int maxFlow = 0;
  while (AugementPath(start, target)) {
    int flow = 1<<30, node = target; // from sink to source(=-2)
    // find size of the flow = min capacity on the way:
    while (back[node] != -2) {
      NetworkEdge & edge = edges[back[node]];
      flow = min(flow, edge.cap);
      node = edge.from;
    }
    // push the flow:
    node=target;
    while (back[node] != -2) {
      NetworkEdge & edge = edges[back[node]],
          & edge2 = edges[back[node]^1];
      edge.cap -= flow;
      edge2.cap += flow;

      flowOnEdge[idxToEdge[back[node]^1]] -= flow;
      flowOnEdge[idxToEdge[back[node]]] += flow;

      node = edge.from; // going back
    }

    maxFlow += flow;
  }
  return maxFlow;
}

ResidualGraph Network::CreateResidual() {
  ResidualGraph res;
  res.g = vector<vector<ResidualEdge>>(vertices);
  for (int i = 0; i < origEdges.size(); ++ i) {
    int from = origEdges[i].aa, to = origEdges[i].bb;

    res.g[from].PB({from, to, costs[{from,to}], 1});
    res.cap[{from, to}] = origCap[{from, to}] - flowOnEdge[{from, to}];
    res.cost[{from, to}] = costs[{from, to}];

    res.g[to].PB({to, from, -costs[{from,to}], -1});
    res.cap[{to, from}] = flowOnEdge[{from, to}];
    res.cost[{to, from}] = -costs[{from, to}];
  }
  return res;
}

// find negative cycle on a residual graph
bool Network::BellmanFord(ResidualGraph & g) {
  vector<int> p(vertices, -1);
  vector<double> d(vertices, INF);
  int start = 0;
  d[start] = 0;

  F(vertices - 1) {
    FF(vertices) {
      FOR(k,0,g.g[j].size()) {
        if (!g.cap[{j, g.g[j][k].v}]) continue;
        const double nd = d[j] + g.g[j][k].cost;
        if (d[ g.g[j][k].v ] > nd) {
          d[ g.g[j][k].v ] = nd;
          p[ g.g[j][k].v ] = j;
        }
      }
    }
  }

  F(vertices) {
    FF(g.g[i].size()) {
      if (!g.cap[{i, g.g[i][j].v}]) continue;
      const double nd = d[i] + g.g[i][j].cost;
      if (d[ g.g[i][j].v ] > nd) {
        int cur = i, prev = p[i];
        vector<pair<int,int>> cyc;
        int delta = numeric_limits<int>::max();

        set<int> vis;
        cur = prev;
        prev = p[prev];
        FOR(t,0,vertices) {
          cur = prev;
          prev = p[prev];
        }
        while (1) {
          if (vis.count(cur)) break;
          vis.insert(cur);
          cyc.PB({prev, cur});
          delta = min(delta, g.cap[{prev, cur}]);
          cur = prev;
          prev = p[prev];
        }

        F(cyc.size()) {
          g.cap[{cyc[i].aa, cyc[i].bb}] -= delta;
          g.cap[{cyc[i].bb, cyc[i].aa}] += delta;
          if (cyc[i].aa < cyc[i].bb) 
            flowOnEdge[{cyc[i].aa, cyc[i].bb}] += delta;
          else
            flowOnEdge[{cyc[i].bb, cyc[i].aa}] -= delta;
        }
        return true;
      }
    }
  }
  return false;
}

// negative cycle removing, potentially high complexity O(n^2 m^2 U), where U is the upper bound on cost
// finds minimum cost variant of the flow found by MaxFlow
void Network::MinCost(int n, ofstream & out) {
  ResidualGraph rg = CreateResidual();
  while (BellmanFord(rg)) {
  }
  vector<int> perm(n);
  F(n) {
    FF(n) {
      if (flowOnEdge[{i+2, n+j+2}]) { // retrieve solution here
        perm[i] = j;
      }
    }
  }
  // output is here
  F(n-1) out << perm[i]+1 << ' ';
  out << perm[n-1]+1;
}
