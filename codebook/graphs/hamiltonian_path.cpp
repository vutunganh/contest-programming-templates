// Finds Hamilnonian path or cycle in O(n^2*2^n)
// Usage: ham(starting_vertex,((1<<number_of_vertices)-1) ^ (1 << starting_vertex))
// graph is in g as adjacency list
// If you want to find hamiltonian path you need to check all vertices
// Also modify checking for right path (1)
// For hamiltonian cycle use 0 as starting vertex (no need to loop through all)
// In dp is next vertex to choose if you are at pos with vis vertices to visit
#define MX 
vll g[MX];

int dp[MX][1<<MX];
void init() {
    CL(dp,-1);
}

int ham(int pos,int vis) {
    int& res = dp[pos][vis];
    if (res == -1) {
        res = -2;
        if (not vis) {
            for (auto& e : g[pos]) if (e == 0) res = 0; // hamiltonian cycle
            //res = 0; // (1) hamiltonian path
        }
        else {
            for(auto& e : g[pos]) {
                if (vis & (1 << e) and ham(e,vis ^ (1 << e)) != -2) res = e;
            }
        }
    }
    return res;
}

int print() {
    int nx = 0;
    int vis = (1 << 20/* number of vertices */) - 2;
    while(vis) {
        cout << nx << endl;
        nx = ham(nx, vis);
        vis ^= (1 << nx);
    }
    cout << nx << endl;
}
