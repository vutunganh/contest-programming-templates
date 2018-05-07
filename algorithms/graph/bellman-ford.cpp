// 0 je start
// N je pocet vrcholu
// D[i] je min sled do i
// P[i] je parent v min sledu vrcholu i
// cyc[i] je jestli je na i zaporny cyklus
#define MAXV 10000

struct Edge{
  Edge(){}
  Edge(ll _f,ll _t,ll _w):from(_f),to(_t),w(_w){}
  ll from,to,w;
};

vector<Edge> E;
ll N,D[MAXV],P[MAXV];
// bool cyc[MAXV];

void bellmanford(){
  F(N)D[i]=LINF,P[i]=-1,cyc[i]=0;
  D[0]=0;
  F(N)
    for(auto e:E)
      if(D[e.from]<LINF) // pokud nas zajimaji pouze zaporne cykly, ktere jsou dosazitelne ze startu
        if(D[e.from]+e.w<D[e.to])
          D[e.to]=D[e.from]+e.w,P[e.to]=e.from;
  for(auto e:E)
    if(D[e.from]<LINF&&D[e.from]+e.w<D[e.to])
      cyc[e.to]=1; // nebo staci return true, pokud nas zajima existence
  // F(N) // zpropaguje zaporny cyklus cyc[i] vsude, kam to jde
  //   for(auto e:E)
  //     if(cyc[e.from])cyc[e.to]=1;
}

void add_edge(ll from,ll to,ll w){E.PB(Edge(from,to,w));}
