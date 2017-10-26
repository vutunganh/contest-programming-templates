// Find euler path stored in forward_list in O(n) - rather slow
// Initialize by add_edge (uncomment if bidirectional)
// Check whether euler path exist:
// 1) not oriented: number of vertices with odd rank 
//     should be 0 or 2
// 2) oriented: all except 0 or 2 vertices should have
//     same number of in and out edges, 1 can have 1 more out
//     and the other one 1 more in
#define MX 
vector<pll> g[MX]; // number of vertices
bitset<MX> used; // number of edges
deque<ll> pth;
int ec;
void init() {
    ec = 0;
    F(MX) g[i].clear();
    used.reset();
    pth.clear();
}

void add_edge(int f, int t) {
    //g[t].pb({f,ec}); // if bidirectional
    g[f].pb({t,ec++});
}

void path(int i) {
    for(auto& e : g[i]) {
        if (used[e.y]) continue;
        used[e.y] = 1;
        path(e.x);
    }
    pth.push_front(i);
}
deque<ll> euler_path(int st) {
    path(st);
    return pth;
}
