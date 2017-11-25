// N - velikost 1. partity
// t - pomyslny stok, nemusi se do nej sahat
// vrati velikost toku a v P[u] se da najit, na co se naparoval vrchol u,
//   popr nenaparoval a je t
#define MAXN1 (10000)
#define MAXN2 (10000)
#define TOT (MAXN1+MAXN2+1)
ll t=TOT-1,D[TOT],P[TOT],N;
vll G[TOT];

void add_edge(ll u,ll v){G[u].PB(v);G[v].PB(u);}

bool bfs(){
  queue<ll> Q;
  F(N)
    if(P[i]==t)D[i]=0,Q.push(i);
    else D[i]=LINF;
  D[t]=LINF;
  while(Q.size()){
    int v=Q.front();Q.pop();
    if(D[v]<D[t])
      for(auto w:G[v])
        if(D[P[w]]==LINF)
          D[P[w]]=D[v]+1,Q.push(P[w]);
  }
  return D[t]!=LINF;
}

bool dfs(ll v){
  if(v!=t){
    for(auto w:G[v])
      if(D[P[w]]==D[v]+1&&dfs(P[w]))
        return P[w]=v,P[v]=w,true;
    D[v]=LINF;
    return false;
  }
  return true;
}

ll hopcroft_karp(){
  F(TOT)P[i]=t;
  ll res=0;
  while(bfs())F(N)if(P[i]==t&&dfs(i))++res;
  return res;
}
