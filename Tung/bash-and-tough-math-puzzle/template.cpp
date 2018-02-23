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

#define ARRAY_SIZE 200001
#define TREE_SIZE (20*ARRAY_SIZE)

ll N,A[ARRAY_SIZE],tree[TREE_SIZE],P[ARRAY_SIZE],X,MAXN=1;

ll gcd(ll a,ll b){
  return b==0?a:gcd(b,a%b);
}

void print(int cnt=1,int id=1){
  if(cnt>MAXN)return;
  FOR(i,id,id+cnt)cout<<i<<":"<<tree[i]<<" ";
  cout<<endl;
  print(2*cnt,id+=cnt);
  if(cnt==1)cout<<"========================================"<<endl;
}

void query(const int l,const int r,ll& ans,int ql=1,int qr=MAXN,int n=1){
  if(ql>qr||ql>r||qr<l||r<l)return;
  if(l<=ql&&qr<=r){
    if(tree[n]%X==0)return;
    else{
      while(n<MAXN){
        if(tree[2*n]%X){
          if(tree[1+2*n]%X){
            ans+=2;
            return;
          }
          n*=2;
        }else
          n=1+2*n;
      }
      ++ans;
      return;
    }
  }
  int mid=(ql+qr)/2;
  query(l,r,ans,ql,mid,2*n);
  if(ans>1)return;
  query(l,r,ans,mid+1,qr,1+2*n);
}

void upd(ll i,ll y){
  ll cur=i+MAXN-1;
  tree[cur]=y;
  cur/=2;
  while(cur){
    tree[cur]=gcd(tree[2*cur],tree[1+2*cur]);
    cur/=2;
  }
}

int main(){
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  cin>>N;
  while(MAXN<N)MAXN*=2;
  FOR(i,MAXN,MAXN+N)cin>>tree[i];
  ROF(i,MAXN-1,1)tree[i]=gcd(tree[2*i],tree[1+2*i]);
  ll _;
  cin>>_;
  while(_--){
    ll t;
    cin>>t;
    if(t==1){
      ll l,r,ans=0;
      cin>>l>>r>>X;
      query(l,r,ans);
      cout<<(ans<=1?"YES":"NO")<<endl;
    }else{
      ll i,y;
      cin>>i>>y;
      upd(i,y);
    }
    // print();
  }

  return 0;
}
