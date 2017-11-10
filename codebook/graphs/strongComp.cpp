#include "../template.cpp"

// Identifies strong connected components in O(|V|+|E|)
// (Condensation)
// Works on cutting list components method, after identifying order of
// visiting them (order of closing vertices in dfs of reverse graph)
void dfs(gr &g, ll u, stack<ll> &z, bitset<MX> &vis) {
    if(vis[u]) return;
    vis[u]=1;
    for(auto i: g[u]) if(!vis[i]) dfs(g,i,z,vis);
    z.push(u);
}
void dfs(gr &g, ll u, ll v, vll &comp) {
    if(~comp[u]) return;
    comp[u]=v;
    for(auto i: g[u]) if(!~comp[i]) dfs(g,i,v,comp);
}
// returns array of ids of components for each vertex
vll strongComp(gr &g) {
    bitset<2*MX> vis;
    gr gT(g.size()); // reverse graph
    F(g.size()) for(auto j: g[i]) gT[j].pb(i);
    stack<ll> Z;
    vll comp(g.size(),-1);
    F(gT.size()) if(!vis[i]) dfs(gT,i,Z,vis);
    // Z now sorted by out(v)
    while(Z.size()) {
        ll u=Z.top(); Z.pop();
        if(!~comp[u]) 
            dfs(g, u, u, comp); // it is a drain in cop dag, no other component will be visited
    }
    return comp;
}