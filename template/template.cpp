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
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define INF (1<<30)
#define LINF (1LL<<61)
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
struct d_{
  template<class T> d_ & operator,(const T& x){cerr<<' '<<x;return *this;}
  template<class T> d_ & operator,(const vector<T>& x){for(auto& a:x)cerr<<' '<<a;return *this;}
}d_t;
#define dbg(args ...) {d_t,__LINE__,"|",args,"\n";}

int main(){
  ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  return 0;
}
