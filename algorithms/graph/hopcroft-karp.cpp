using vi = vector<int>;
#define FOR(i,a,b) for(auto i=a;i<b;++i)
#define F(a) FOR(i,0,a)
#define FF(a) FOR(j,0,a)
#define MAXN1 (10000)
#define MAXN2 (10000)
#define TOT (MAXN1 + MAXN2 + 1)
#define INF (1<<31)

// N - velikost 1. partity
// t je "stok", ktery se musi nastavit jako N+velikost 2. partity+1
// mozna se da nastavit na cokoliv, co nekoliduje s cisly vrcholu
// vrati velikost toku a v P[u] se da najit, na co se naparoval vrchol u,
//   popr nenaparoval a je INF
// EXPERIMENTALNI ZMENA, ZMERGOVANI PE1 A PE2
int t,D[TOT],P[TOT],N;
vi G[TOT];

void add_edge(int u,int v){G[u].PB(v);G[v].PB(u);}

bool bfs(){
  queue<int> Q;
  F(N)
    if(P[i]==t)D[i]=0,Q.push(i);
    else D[i]=INF;
  D[t]=INF;
  while(Q.size()){
    int v=Q.front();Q.pop();
    if(D[v]<D[t])
      for(auto w:G[v])
        if(D[P[w]]==INF)
          D[P[w]]=D[v]+1,Q.push(P[w]);
  }
  return D[t]!=INF;
}

bool dfs(int v){
  if(v!=t){
    for(auto w:G[v])
      if(D[P[w]]==D[v]+1&&dfs(P[w]))
        return P[w]=v,P[v]=w,true;
    D[v]=INF;
    return false;
  }
  return true;
}

int hopcroft_karp(){
  F(TOT)P[i]=t;
  int res=0;
  while(bfs())F(N)if(P[i]==t&&dfs(i))++res;
  return res;
}
