ll n; // number of vertices

// union find
ll uf[MX];
int find(int e) { return uf[e] == e ? e : uf[e] = find(uf[e]); }
void mrg(int i, int j) { uf[find(i)] = find(j); }
bool same(int i, int j) { return find(i) == find(j); }

vector<pair<ll,ll>> g[MX]; // graph with edges from i to j with price as a second part

using edg = tuple<ll,ll,ll>;
vector<edg> ali2edgs() { // adjacency list representation (in g) to vector of edges
    vector<edg> edgs;
    F(n) for(auto& e : g[i]) edgs.pb({e.y,i,e.x});
    return edgs;
}

//ll mst() { // return cost of minimum-spanning tree (swap commenting in return)
vector<edg> mst() { // returns all edges used in minimum-spanning tree
    auto edgs = ali2edgs();
    ll m = edgs.size();
    vector<edg> res;

    F(n) uf[i] = i;
    sort(edgs);
    int cv = 1;
    int k = 0;
    ll rp = 0;

    REP(k,m and cv < n) {
        ll prc, i, j;
        tie(prc,i,j) = edgs[k];
        if (find(i) != find(j)) {
                mrg(i,j);
                cv++;
                res.pb(edgs[k]);
                rp += prc;
        }
    }
    assert(cv==n);
    return res;
    //return rp;
}


