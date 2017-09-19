#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define FOR(i,a,b) for (auto i=(a); i<(b); ++i)
#define F(a,b) FOR(i, (a), (b))
#define FF(a,b) FOR(j, (a), (b))
#define aa first
#define bb second
#define PB push_back
#define MOD ((int)1e9+7)
#define INF (1<<30)
#define LINF (1<<62ll)
#define EPS (1e-10)
#define EQ(a,b) (fabs(a-b)<=fabs(a+b)*EPS)

// UNTESTED!!!!!
#define MAXV 10000

struct Node{
  Node(){}
  Node(ll _d,ll _w):d(_d),w(_w){}
  ll d,w;
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
  F(0,MAXV)D[i]=numeric_limits<ll>::max();
  D[0]=0;
  F(0,N)
    for(auto e : E)
      if(D[e.to]>D[e.from]+e.w)
        D[e.to]=D[e.from]+e.w,P[e.to]=e.from;
}

void add_edge(ll from,ll to,ll w){
  G[from].PB(Node(to,w));
  E.PB(Edge(from,to,w));
}

int main(void){
  ios::sync_with_stdio(false);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  return 0;
}
