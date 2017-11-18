#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
using vvll=vector<vll>;
#define FOR(i,a,b) for(decltype(b) i=a;i<b;++i)
#define ROF(i,a,b) for(decltype(b) i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n)
#define F(n) REP(i,n)
#define FF(n) REP(j,n)
#define aa first
#define bb second
#define pb push_back
#define MOD ((ll)1e9+7)
#define INF (1<<30)
#define LINF (1LL<<61)
#define EPS (1e-10)
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define all(x) x.begin(),x.end()
#define CL(A,I) memset(A,I,sizeof(A))
struct d_{
  template<class T> d_ & operator,(const T& x){cerr<<' '<<x;return *this;}
  template<class T> d_ & operator,(const vector<T>& x){for(auto& x:x)cerr<<' '<<x;return *this;}
}d_t;
#define dbg(args ...) {d_t,"|",__LINE__,"|",":",args,"\n";}

int main(){
  ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  return 0;
}
