// UNTESTED!!!!!
#define MAXV 10000

struct Node{
  Node(){}
  Node(ll _d,ll _w):d(_d),w(_w){}
  ll d,w; // destination, weight
};

struct Edge{
  Edge(){}
  Edge(ll _f,ll _t,ll _w):from(_f),to(_t),w(_w){}
  ll from,to,w;
};

vector<Node> G[MAXV];
vector<Edge> E;
ll D[MAXV];
ll P[MAXV];
ll N; // node count

void bellmanford(){
  F(MAXV)D[i]=numeric_limits<ll>::max();
  D[0]=0;
  F(N)
    for(auto e:E)
      if(D[e.to]>D[e.from]+e.w)
        D[e.to]=D[e.from]+e.w,P[e.to]=e.from;
}

void add_edge(ll from,ll to,ll w){
  G[from].PB(Node(to,w));
  E.PB(Edge(from,to,w));
}
