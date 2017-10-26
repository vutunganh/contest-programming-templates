#include "../template.cpp"

// Dinic's algorithm
// maxFlow & mincut
// O(|E| * |V|^2)

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

long long maxFlow(ll s, ll t) {
    source=s;sink=t;
    long long total_flow = 0, flow;
    while (bfs())
        while (flow = dfs(s, 1<<30))
            total_flow += flow;
    return total_flow;
}

void addEdge(int from, int to, long long cap1) {
    edges[M] = Edge{from, to, cap1};
    adj[M] = adj[from];
    adj[from] = M++;

    edges[M] = Edge{to, from, 0};
    adj[M] = adj[to];
    adj[to] = M++;

    N=max(from,to)+1;
}

void init() {
    CL(adj,-1);
    M = NODES;
}

int main()
{
    init();
    addEdge(0,1,1);
    addEdge(0,2,2);
    addEdge(0,3,1);
    addEdge(0,4,1);
    addEdge(1,5,2);
    addEdge(2,5,1);
    addEdge(3,5,2);
    addEdge(4,5,2);
    addEdge(5,6,100);
    cout<<"Max flow: "<< maxFlow(0,6) << endl;
    return 0;
}