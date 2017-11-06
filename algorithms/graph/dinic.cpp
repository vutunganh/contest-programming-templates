#define NODES (5000)
#define EDGES (30000)
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

void add_edge(int from, int to, long long cap1, long long cap2) {
  edges[M] = Edge{from, to, cap1};
  adj[M] = adj[from];
  adj[from] = M++;

  edges[M] = Edge{to, from, cap2};
  adj[M] = adj[to];
  adj[to] = M++;
}

void init(int nodeCnt,int st,int en){
  N=M=nodeCnt;
  source=st;
  sink=en;
}

long long maxflow() {
  long long total_flow = 0, flow;
  while (bfs())
    while (flow = dfs(source, 1<<30))
      total_flow += flow;
  return total_flow;
}

// Morass shitcode
// init pomoci fce ini
#define SZ 512 //pocet nodu
#define ME (1<<14) //pocet edgu
struct Dinic{
  int n,m,h[SZ],l[SZ],s,t,w[SZ];
  struct eg{
    int v,c,f,x;
  }E[ME];
  bool bfs(){
    static int q[SZ];
    F(n)l[i]=-1;
    int B(l[s]=0),E(1);
    q[0]=s;
    while(B<E)for(int k(q[B++]),i(h[k]);~i;i=e[i].x)
      if(e[i].f<e[i].c&&!~l[e[i].v])
        l[e[i].v]=l[k]+1,q[E++]=e[i].v;
    return ~l[t];
  }
  int dfs(int u,int f){
    if(u==t)return f;
    int mf;
    for(int i(w[i]);~i;i=e[i].x)
      if(e[i].f<e[i].c&&l[u]+1==l[e[i].v])
        if((mf=dfs(e[i].v,min(f,e[i].c-e[i].f)))>0)
          return e[i].f+=mf,e[i^1].f-=mf,mf;
    return 0;
  }
  void ini(int N,int f,int d){n=N;s=f;t=d;m=0;F(n)h[i]=-1;}
  void ade(int u,int v,int c=1,int rc=0){
    e[m]=eg{v,c,0,h[u]};
    h[u]=m++;
    e[m]=eg{u,c,0,h[v]};
    h[v]=m++;
  }
  int mf(){
    int a(0),d;
    while(bfs()){
      memcpy(w,h,sizeof(int)*n);
      do a+=d=dfs(s,INF); while(d);
    }
    return a;
  }
};
