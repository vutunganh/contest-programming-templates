const ll MAX_NODES = 100007;
struct TEdge {
    ll start, end, cost;
};

struct TPrio {
    ll node;
    ll pred;
    ll cost;
    bool operator < (const TPrio & p) const {
        return cost > p.cost; // PRIO QUEUE IS MAXIMAL BY DEFAULT
    }
};

vector<TEdge> neighbours[MAX_NODES];
ll dists[MAX_NODES];
bool closed[MAX_NODES];

vector<TEdge> jarnik() {
    vector<TEdge> span_tree;
    priority_queue<TPrio> q;
    q.push({0, -1, 0});
    CL(dists, -1); CL(closed,0);
    while(q.size()) {
        TPrio prio = q.top();
        q.pop();
        if(closed[prio.node]) continue;
        if(prio.pred != -1) {
            span_tree.pb({prio.node, prio.pred, prio.cost});
        }
        closed[prio.node] = true;
        dists[prio.node] = prio.cost;
        for(TEdge edge : neighbours[prio.node]) {
            if(closed[edge.end]) continue;
            ll newcost = edge.cost;
            if(dists[edge.end] == -1 || dists[edge.end] > newcost) {
                dists[edge.end] = newcost;
                q.push({edge.end, prio.node, newcost});
            }
        }
    }
    return span_tree;
}
int main() {
    ll n, m;
    cin >> n >> m;
    REP(i, m) {
        ll x, y, c;
        cin >> x >> y >> c;
        neighbours[x].pb({x,y,c});
        neighbours[y].pb({y,x,c});
    }
    for(TEdge edge : jarnik()) cout << edge.start << ' ' << edge.end << ' ' << edge.cost << endl;
    return 0;
}