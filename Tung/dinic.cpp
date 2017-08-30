#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
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

const int NODES = 5000, EDGES = 30000;
int N, M = NODES, source, sink;

struct Edge {
    int from, to;
    long long residue;
} edges[NODES+2*EDGES];
int adj[NODES+2*EDGES], work_adj[NODES+2*EDGES], work_edges[NODES+2*EDGES];

bool bfs() {
    static int dist[NODES], q[NODES];
    int qsz = 0;

    for (int i = 0; i < N; ++i) {
        work_adj[i] = -1;
        dist[i] = N+1;
    }
    int work_M  = NODES;

    q[qsz++] = source;
    dist[source] = 0;
    for (int qi = 0; qi < qsz && dist[q[qi]] + 1 <= dist[sink]; ++qi)
        for (int i = adj[q[qi]]; i >= 0; i = adj[i]) {
            Edge & edge = edges[i];
            if (edge.residue && dist[edge.from] + 1 <= dist[edge.to]) {
                work_adj[work_M] = work_adj[edge.from];
                work_edges[work_M] = i;
                work_adj[edge.from] = work_M++;

                if (dist[edge.to] == N+1) {
                    dist[edge.to] = dist[edge.from] + 1;
                    q[qsz++] = edge.to;
                }
            }
        }
    return dist[sink] != N+1;
}

long long dfs(int node, long long flow) {
    if (!flow || node == sink)
        return flow;

    for (int & i = work_adj[node]; i >= 0; i = work_adj[i]) {
        int eindex = work_edges[i];
        long long fl;
        if (fl = dfs(edges[eindex].to, min(flow, edges[eindex].residue))) {
            edges[eindex].residue -= fl;
            edges[eindex^1].residue += fl;
            return fl;
        }
    }
    return 0;
}

void add_edge(int from, int to, long long cap1, long long cap2) {
    edges[M] = Edge{from, to, cap1};
    adj[M] = adj[from];
    adj[from] = M++;

    edges[M] = Edge{to, from, cap2};
    adj[M] = adj[to];
    adj[to] = M++;
}

long long maxflow() {
    long long total_flow = 0, flow;
    while (bfs())
        while (flow = dfs(source, 1<<30))
            total_flow += flow;
    return total_flow;
}
