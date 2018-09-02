#define LINF 1LL<<61
#define MX 10000

struct Edge{
  ll v,w; // destination and weight
  bool operator<(const Edge& a)const{return w>a.w;}
};

// node cnt,edge cnt,distances,parents
ll N,M,D[MX],P[MX];
vector<Edge> G[MX];

void add_edge(ll u,ll v,ll w){G[u].PB({v,w});}

void dijkstra(ll s){
  F(N)D[i]=LINF,P[i]=-1;
  D[s]=0;
  priority_queue<Edge> Q;
  Q.push({s,D[s]});
  while(Q.size()){
    auto u=Q.top().v;Q.pop();
    for(auto e:G[u])
      if(D[e.v]>D[u]+e.w)
        D[e.v]=D[u]+e.w,P[e.v]=u,Q.push({e.v,D[e.v]});
  }
}
