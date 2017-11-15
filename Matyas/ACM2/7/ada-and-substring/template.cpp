#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ull=unsigned long long;
using ld=double;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
#define FOR(i,a,b) for(decltype(b) i=a;i<b;++i)
#define REP(i,b) FOR(i,0,b)
#define F(a) REP(i,a)
#define FF(a) REP(j,a)
#define aa first
#define bb second
#define PB push_back
#define pb push_back
#define MOD ((int)1e9+7)
#define INF (1<<30)
#define LINF (1LL<<61)
#define EPS (1e-10)
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define ALL(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()
#define CL(A,I) memset(A,I,sizeof(A))
#ifdef DEBUG
#define DEB cout<<"DEB!\n"
#define DPRINT(X) cout<<#X<<"= "<<X<<endl
#define dout cout
#else
#define DEB do{}while(0)
#define DPRINT(X) do{}while(0)
#define dout 0&&cout
#endif





using namespace std;

using ll = long long;

using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using gr = vector<vll>;
using wgr = vector<vpll>;

#define pb push_back
#define FOR(i, m, n) for (ll i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
struct d_ {
    template<typename T> d_ & operator ,(const T & x) { cerr << ' ' <<  x; return *this;}
    template<typename T> d_ & operator ,(const vector<T> & x) { for(auto x: x) cerr << ' ' <<  x; return *this;}
} d_t;
#define dbg(args ...) { d_t,"|",__LINE__,"|",":",args,"\n"; }
#ifdef DEBUG
	#define D cout
#else
	#define D 0 && cout
#endif
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define all(x) begin(x),end(x)
#define IN(n) ll n;cin >> n;
#define x first
#define y second

#define MX 2010000
struct SA{
    int sa[MX],R[MX],C[MX],s[MX<<1],t[MX<<1],p[MX],S[MX],U[MX];
    void ss(int n,int m,int*s,int*t,int*p){
        int A=t[n-1]=0,c=*R=-1,*r=s+n,x,y;
        for(int i=n-2;~i;--i)t[i]=s[i]^s[i+1]?s[i]>s[i+1]:t[i+1];
        FOR(i,1,n)R[i]=t[i-1]&&!t[i]?(p[A]=i,A++):-1;
        memset(sa,-1,n*4),memset(S,0,4*m);
        F(n)++S[s[i]];F(m)if(i)S[i]+=S[i-1];F(m)U[i]=S[i]-1;
        for(int i=A-1;~i;--i)sa[U[s[p[i]]]--]=p[i];
        FOR(i,1,m)U[i]=S[i-1];
        F(n)if(sa[i]>0&&t[sa[i]-1])sa[U[s[sa[i]-1]]++]=sa[i]-1;
        F(m)U[i]=S[i]-1;
        for(int i=n-1;~i;--i)if(sa[i]>0&&!t[sa[i]-1])sa[U[s[sa[i]-1]]--]=sa[i]-1;
        F(n)if(~(x=R[sa[i]])){
            if(c<1||p[x+1]-p[x]!=p[y+1]-p[y])++c;
            else for(int j=p[x],k=p[y];j<=p[x+1];++j,++k)
                if((s[j]<<1|t[j])^(s[k]<<1|t[k])){++c;break;}
            r[y=x]=c;
        }
        if(c+1<A)ss(A,c+1,r,t+n,p+A);
        else F(A)sa[r[i]]=i;
        F(A)r[i]=p[sa[i]];
        memset(sa,-1,n*4),memset(S,0,4*m);
        F(n)++S[s[i]];F(m)if(i)S[i]+=S[i-1];F(m)U[i]=S[i]-1;
        for(int i=A-1;~i;--i)sa[U[s[r[i]]]--]=r[i];
        FOR(i,1,m)U[i]=S[i-1];
        F(n)if(sa[i]>0&&t[sa[i]-1])sa[U[s[sa[i]-1]]++]=sa[i]-1;
        F(m)U[i]=S[i]-1;
        for(int i=n-1;~i;--i)if(sa[i]>0&&!t[sa[i]-1])sa[U[s[sa[i]-1]]--]=sa[i]-1;
    }
    void sx(int N,const char*r){
        int m,h=*C=0,M=*max_element(r,r+ ++N);
        memset(R,0,4*M+4);
        F(N)R[(int)r[i]]=1;
        F(M)R[i+1]+=R[i];
        F(N)s[i]=R[(int)r[i]]-1;
        m=R[M];
        ss(N,m,s,t,p);
        F(N)R[sa[i]]=i;
        F(N-1){
            while(i+h<N&&sa[R[i]-1]+h<N&&s[i+h]==s[sa[R[i]-1]+h])++h;
            if((C[(int)R[i]]=h))--h;
        }
    }
}Z;


int main(){
  ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
  vector<ll> l(256, 0);
  string s;
  cin >> s;
  F(s.size()) l[s[i]] += s.size() - i;
  Z.sx(s.size(), s.c_str());

  F (s.size() + 1) {
    if (i == 0) continue;
    l[ s[Z.sa[i]] ] -= Z.C[i];
  }
  for (int i = 'a'; i < 'z'; ++ i) cout << l[i] << " ";
  cout << l['z'] << endl;

  return 0;
}
