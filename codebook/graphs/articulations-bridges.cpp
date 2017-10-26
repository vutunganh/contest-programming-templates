#include "../template.cpp"

// Finds all articulations and bridges in graph
// O(V+H)

#define MAX 10007 // max edges
#define UNVISITED 0

ll n;
vll neigh[MAX];

ll num[MAX];
ll low[MAX];
int cnt=1;

int dfsRoot, rootChildred;

set<ll> articPts;
vpll bridges;

void dfs(ll u, ll par) {
    low[u]=num[u] = cnt++;
    ll childs=0; 
    for (auto v : neigh[u]) {
        if (num[v]==0) { // unvisited
            childs++; // root
            dfs(v, u);
            if (low[v] >= num[u] && par!=-1) articPts.insert(u); // back edges goes only lower or into 'u'; root resolve later
            if (low[v] > num[u]) bridges.pb({u, v}); // goes only lower
            low[u] = min(low[u], low[v]); // remin lowest point
        } else if (v != par) { // zpetna hrana: remin kam vede
            low[u] = min(low[u], num[v]);
        }
    }
    // For root
    if(par==-1 && childs>1) articPts.insert(u);
}

void addEdge(int u,int v) {
    neigh[u].pb(v);
    neigh[v].pb(u);
}

int main ()
{
    n=4;
    addEdge(0,1);   
    addEdge(2,1);   
    addEdge(2,3);   
    addEdge(3,1);   
    F(n) if (!num[i]) dfs(i, -1);
    cout<<"Articulation points: "; for(auto i:articPts) cout<<i<<' '; cout<<endl;
    cout<<"Bridges: "; for(auto i:bridges) cout<<i.x<<"-"<<i.y<<",";  cout<<endl;
}
