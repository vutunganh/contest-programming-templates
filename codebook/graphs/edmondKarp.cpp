#include "../template.cpp"

// Edmonds-Karp's impl of Ford Fulkerson 
// maxFlow & mincut
// O(|E|^2 * |V|) (V<=500,E<=5000)

#define MAX 1000 // of nodes
struct Edge { ll from, to, cap; }; // capacity in one way, residue in the other
vector<Edge> edges;
vll ng[MAX]; // indexes of edges
ll back[MAX]; // indexes of edges for reconstructing augment path
bool fromS[MAX]; // for minCut: can get from s when augment not found?

void init(){
    edges.clear();
    F(MAX)ng[i].clear();
    CL(back,0);
    CL(fromS,0);
}

void addEdge(ll from, ll to, ll capacity) { // 2 edges, back is residual, accessible by ^1 (even/odd)
    ng[from].pb(edges.size());
    edges.pb(Edge{from, to, capacity});

    ng[to].pb(edges.size());
    edges.pb(Edge{to, from, 0});
}

bool bfs(ll s, ll t) { // source,sink
    CL(back,-1); back[s] = -2;
    CL(fromS,0);
    queue<ll> q; q.push(s);
    while (!q.empty() && back[t] == -1) { // exists augment path to sink
        ll u = q.front(); q.pop();
        fromS[u]=1;
        F(ng[u].size()) {
            Edge & edge = edges[ng[u][i]];
            if (edge.cap && back[edge.to] == -1) { // has capacity
                back[edge.to] = ng[u][i];
                q.push(edge.to);
            }
        }
    }
    return back[t] != -1;
}

ll maxFlow(ll s, ll t) {
    ll maxFlow = 0;
    while (bfs(s, t)) {
        ll flow = 1<<30, node = t; // from sink to source(=-2)
        // find size of the flow = min capacity on the way:
        while (back[node] != -2) {
            Edge & edge = edges[back[node]];
            flow = min(flow, edge.cap);
            node = edge.from;
        }
        // push the flow:
        node=t;
        while (back[node] != -2) {
            Edge & edge = edges[back[node]],
                 & edge2 = edges[back[node]^1];
            edge.cap -= flow;
            edge2.cap += flow;
            node = edge.from; // going back
        }

        maxFlow += flow;
    }
    cout<<"Max flow: "<< maxFlow <<endl;
    cout<<"Min cut: "; F(edges.size()) {
        if(i&1)continue;
        auto& e=edges[i];
        if(fromS[e.from] != fromS[e.to]) cout<<e.from<<","<<e.to<<" ";
    }cout<<endl;
    return maxFlow;
}

int main() {
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
    maxFlow(0,6);
    return 0;
}
