#include "../template.cpp"

// Tarjan's offline lowest common ancestor (LCA) algorithm
// =====
// Answers offline 'm' LCA queries on tree of 'n' vertices
// O(n+m * ackr(n))

// Usage: 1) init with queries, 2) add edges, 3) run TarjanOLCA(root, -1)
// answers in order of 'queries' array appears in 'ret' array

#define MX >>#nodes<<

vll ng[MX];
vpll q[MX];
bool col[MX];
ll anc[MX];
vll ret;

// Union Find:
ll uf[MX];
int find(int e) { return uf[e] == e ? e : uf[e] = find(uf[e]); }
void mrg(int i, int j) { uf[find(i)] = find(j); }

 vll TarjanOLCA(ll u, ll par) {
    uf[u]=u;
    anc[u]=u;
    for (auto v: ng[u]) {
     	if(v==par)continue;
         TarjanOLCA(v,u);
         mrg(u,v);
         anc[find(u)]=u;
     }
     col[u]=1;
     for(auto v: q[u]) {
         if (col[v.x])
         	ret[v.y] = anc[find(v.x)];
         }
}

void init(vpll & qrs) {
	F(MX) ng[i].clear();
	CL(col,0);
	ret=vll(qrs.size());
	F(qrs.size()) q[qrs[i].x].pb({qrs[i].y,i}),q[qrs[i].y].pb({qrs[i].x,i});
}

void addEdge(ll a, ll b) {
	ng[a].pb(b); ng[b].pb(a);
}

int main() {
	vpll qrs = {{0, 1},{2,3},{5,6},{2,6},{0,0},{6,3}};
	init(qrs);
	addEdge(0,1); addEdge(1,2); addEdge(1,3); addEdge(3,4); addEdge(4,5);  addEdge(3,6);
	TarjanOLCA(0,-1);
	F(qrs.size()){
		cout<<"lca("<<qrs[i].x<<","<<qrs[i].y<<") = "<<ret[i]<<endl;
	}
	return 0;
}