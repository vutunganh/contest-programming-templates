// working hld with segtree
vector<int> adj[N];
vector<int> edges[N];
vector<int> idx[N];
 
int subSize[N];
int depth[N];
 
int lca[LN][N];
 
int segTree[N<<2];
 
int pos;
int chainNo;
int chainHead[N];
int chainIndex[N];
int arr[N];
int basePos[N];
int endNode[N];
 
void Dfs(int node, int parent, int level) {
    depth[node] = level;
    lca[0][node] = parent;
    subSize[node] = 1;
    int x = adj[node].size();
    while (x--) {
        int next = adj[node][x];
        if (next != parent){
            endNode[idx[node][x]] = next;
            Dfs(next, node, level+1);
            subSize[node] += subSize[next];
        }
    }
}
 
void HLD(int node, int cost, int parent) {
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = node;
    }
    pos++;
    chainIndex[node] = chainNo;
    basePos[node] = pos;
    arr[pos] = cost;
    int specialChild = -1, edgeCost = 0;
    int x = adj[node].size();
    while (x--) {
        int next = adj[node][x];
        if (next != parent) {
            if (specialChild == -1 || subSize[next] > subSize[specialChild]) {
                specialChild = next;
                edgeCost = edges[node][x];
            }
        }
    }
    if (specialChild != -1) {
        HLD(specialChild, edgeCost, node);
    }
    x = adj[node].size();
    while (x--) {
        int next = adj[node][x];
        if (next != parent && next != specialChild) {
            chainNo++;
            HLD(next, edges[node][x], node);
        }
    }
}
 
void initializeLCA(int n) {
    for (int j = 1; j < LN; j++) {
        for (int i = 1; i <= n; i++) {
            lca[j][i] = lca[j - 1][lca[j - 1][i]];
        }
    }
}
 
int LCA(int x, int y) {
    if (depth[x] < depth[y]) {
        std::swap(x, y);
    }
    for (int i = LN - 1; i >= 0; i--) {
        if (depth[x] - (1 << i) >= depth[y]) {
            x = lca[i][x];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = LN - 1; i >= 0; i--) {
        if (lca[i][x] != lca[i][y]) {
            x = lca[i][x];
            y = lca[i][y];
        }
    }
    return lca[0][x];
}
 
void buildSegTree(int node, int u, int v) {
    if(u == v) {
        segTree[node] = arr[u];
        return ;
    }
    int mid = (u + v) >> 1;
    int lc = node << 1;
    int rc = lc | 1;
    buildSegTree (lc, u, mid);
    buildSegTree (rc, mid + 1, v);
    segTree[node] = std::max(segTree[lc], segTree[rc]);
}
 
void updateSegTree(int node, int u, int v, int i, int val) {
    if(u == v) {
        segTree[node] = val;
        return;
    }
    int mid = (u + v) >> 1;
    int lc = node << 1;
    int rc= lc | 1;
    if(i <= mid) {
        updateSegTree(lc, u, mid, i, val);
    } else {
        updateSegTree(rc, mid+  1, v, i, val);
    }
    segTree[node]=std::max(segTree[lc], segTree[rc]);
}
 
int querySegTree(int node, int u, int v, int ql, int qr) {
    if(ql > v || u > qr) {
        return 0;
    }
    if(u >= ql && v <= qr) {
        return segTree[node];
    }
    int mid = (u + v) >> 1;
    int lc = node << 1;
    int rc = lc | 1;
    int lv = querySegTree(lc, u, mid, ql, qr);
    int rv = querySegTree(rc, mid + 1, v, ql, qr);
    return std::max(rv,lv);
}
 
int queryUp(int u,int v) {
    if(u == v) {
        return 0;
    }
    int lchain, rchain = chainIndex[v], ans = -1;
    while (1) {
        lchain = chainIndex[u];
        if(lchain == rchain) {
            if(u == v) {
                break;
            }
            int currAns = querySegTree(1, 1, pos, basePos[v] + 1, basePos[u]);
            ans = std::max(ans, currAns);
            break;
        }
        int currAns = querySegTree(1, 1, pos, basePos[chainHead[lchain]], basePos[u]);
        ans = std::max(ans, currAns);
        u = chainHead[lchain];
        u = lca[0][u];
    }
    return ans;
}
 
void Initialize(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        edges[i].clear();
        idx[i].clear();
        chainHead[i] = -1;
        for (int j = 0; j < LN; j++) {
            lca[j][i]=-1;
        }
    }
}
 
int queryPath(int u, int v) {
    int lca = LCA(u, v);
    int a = queryUp(u, lca);
    int b = queryUp(v, lca);
    return std::max(a, b);
}
 
void Update(int i, int val) {
    int node = endNode[i];
    updateSegTree(1, 1, pos, basePos[node], val);
}
 
int main() {
    int t;
    SI(t);
    while (t--) {
        int n;
        SI(n);
        Initialize(n);
        for (int i=1;i<n;i++) {
            int u, v, w;
            SI(u), SI(v), SI(w);
            adj[u].pb(v);
            edges[u].pb(w);
            idx[u].pb(i);
            adj[v].pb(u);
            edges[v].pb(w);
            idx[v].pb(i);
        }
        Dfs(1, 0, 0);
        initializeLCA(n);
        pos = -1;
        chainNo = 1;
        HLD(1, 0, 0);
        buildSegTree(1, 1,pos);
        char str[10];
        scanf("%s", str);
        while (str[0] != 'D') {
            int type, u ,v;
            SI(u);
            SI(v);
            if (str[0] == 'Q') {
                PI(queryPath(u, v));
                printf("\n");
            } else {
                Update(u, v);
            }
            scanf("%s", str);
        }
    }
}