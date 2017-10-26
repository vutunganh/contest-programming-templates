// tested http://www.spoj.com/problems/EZDIJKST/
#define NODES 10000

struct Edge
{
  int u;
  ull w;
  bool operator<(const Edge& a) const { return w < a.w; }
};

int s,t,N,M; // start, target, node count, vertex count
ull D[NODES]; // distances
vector<Edge> G[NODES]; // graph
int P[NODES]; // parents

void add_edge(int u,int v,ull w){G[u].PB({v,w});}

void dijkstra(){
  F(NODES)D[i]=INF,P[i]=-1;
  D[s]=0;
  priority_queue<Edge> Q;
  Q.push({s, D[s]});
  while(!Q.empty()){
    int v=Q.top().u;Q.pop();
    for(const auto& e:G[v]){
      if(D[e.u]>D[v]+e.w)
        D[e.u]=D[v]+e.w,P[e.u]=v,Q.push(e);
    }
  }
}

void solve(){
  scanf(" %d %d",&N,&M);
  F(NODES)G[i].clear();
  F(M){
    int u,v,w;
    scanf(" %d %d %d",&u,&v,&w);
    add_edge(u-1,v-1, w);
  }
  scanf(" %d %d",&s,&t);
  s-=1;t-=1; //numbering was 1 based
  dijkstra();
  if(D[t]==INF)
    puts("NO");
  else
    printf("%lld\n",D[t]);
}

int main(void)
{
  ios::sync_with_stdio(false);
  int T;scanf(" %d",&T);
  while(T--)solve();

  return 0;
}
