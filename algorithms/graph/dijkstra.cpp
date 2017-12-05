#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
using vvll=vector<vll>;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define ROF(i,a,b) for(ll i=a;i>=(ll)b;--i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))

#define LINF 1LL<<61
#define MX 10000

struct Edge{
  ll v,w; // destination and weight
  bool operator<(const Edge& a)const{return w<a.w;}
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

int main(){
  ios::sync_with_stdio(0);
  int _;cin>>_;
  while(_--){
    cin>>N>>M;
    F(MX)G[i].clear();
    F(M){
      ll u,v,w;
      cin>>u>>v>>w;
      add_edge(u-1,v-1,w);
    }
    ll s,t;
    cin>>s>>t;
    --s,--t;
    dijkstra(s);
    if(D[t]==LINF)cout<<"NO"<<endl;
    else cout<<D[t]<<endl;
  }

  return 0;
}
