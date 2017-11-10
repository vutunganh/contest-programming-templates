// prefixovy maximum
// nepouzivat t[0]
// neumi odecitat
#define MX (100009)
struct FW{
  int t[MX],L;
  void ud(int x,int v){while(x<=L)t[x]=max(t[x],v),x+=x&-x;}
  int MAX(int x){int X=-INF;while(x)X=max(X,t[x]),x-=x&-x;return X;}
  void clr(int N){L=N;F(N)t[i]=-INF;}
}FT;
