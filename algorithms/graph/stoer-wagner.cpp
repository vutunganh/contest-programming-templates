// vstupem je pocet vrcholu
// vystupem je vysledna velikost rezu
// zvladne i vice testcasu v jednom submitu
// G[f][t] je vaha hrany f do t
// cislujeme vrcholy od 0
// funguje pouze na neorientovanych grafech
// vsechny inty muzeme flipnout na longy, akorat nastavit spravne B pred whilem
#define MX 150
int G[MX][MX];
int sw(int n){
  static bool a[MX];
  static int v[MX],w[MX],B,p;
  iota(v,v+n,0);
  B=INF;
  while(n>1){
    a[*v]=1;
    FOR(k,1,n)a[v[k]]=0,w[k]=G[p=*v][v[k]];
    FOR(k,1,n){
      int zj=-1;
      FOR(k,1,n)if(!a[v[k]]&&(!~zj||w[k]>w[zj]))zj=k;
      a[v[zj]]=1;
      if(k==n-1){
        B=min(B,w[zj]);
        F(n)G[v[i]][p]=G[p][v[i]]+=G[v[zj]][v[i]];
        v[zj]=v[--n];
        break;
      }
      p=v[zj];
      FOR(k,1,n)if(!a[v[k]])w[k]+=G[v[zj]][v[k]];
    }
  }
  return B;
}

