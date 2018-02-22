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

map<ll, int> nToComp;
vector<ll> allComps;

struct V;
struct V {
  // 0, 1
  V* left, *right;
  set<int> comps;
  ll num;
  int bit;

  void insert(ll n, int comp) {
    if (bit == 31) {
      num = n;
      comps.insert(comp);
      return;
    } else {

      ll b = (n & (1 << (30 - bit)));
      if (b == 0) {
        if (left == nullptr) left = new V();
        left->bit = bit + 1;
        left->insert(n, comp);
      } else {
        if (right == nullptr) right = new V();
        right->bit = bit + 1;
        right->insert(n, comp);
      }

    }

    if ((left != nullptr && left->comps.find(comp) != left->comps.end())
        && (right != nullptr && right->comps.find(comp) != right->comps.end())) {
      left->comps.erase(comp);
      right->comps.erase(comp);
      comps.insert(comp);
    }
  } 

  void fixComp(ll comp) {
    if (left != nullptr) {
      left->fixComp(comp);
    }
    if (right != nullptr) {
      right->fixComp(comp);
    }
    if ((left != nullptr && left->comps.find(comp) != left->comps.end())
        && (right != nullptr && right->comps.find(comp) != right->comps.end())) {
      left->comps.erase(comp);
      right->comps.erase(comp);
      comps.insert(comp);
    }
    if (left == nullptr && right != nullptr) {
      right->comps.erase(comp);
      comps.insert(comp);
    }
    if (right == nullptr && left != nullptr) {
      left->comps.erase(comp);
      comps.insert(comp);
    }
  }

  ll find(ll n) {
    int b = (n & (1 << (30 - bit)));
    //cout << n << " - " << bit << ", " << b << endl;
    ll res;
    if (bit == 31) {
      nToComp[n] = nToComp[num];
      allComps[nToComp[n]] = nToComp[num];
      comps.insert(nToComp[n]);
      cout << "!" << nToComp[n] << endl;
      res = num;
    } else {

      if ((b == 0 && left != nullptr && left->comps.find(nToComp[n]) == left->comps.end()) || (right == nullptr || (right != nullptr && right->comps.find(nToComp[n]) != right->comps.end()))) {
        res = left->find(n);
      } else {
        res = right->find(n);
      }
    }

    if ((left != nullptr && left->comps.find(nToComp[n]) != left->comps.end())
        && (right != nullptr && right->comps.find(nToComp[n]) != right->comps.end())) {
      left->comps.erase(nToComp[n]);
      right->comps.erase(nToComp[n]);
      comps.insert(nToComp[n]);
    }
    return res;
  }
};

struct Tree {
  V* root;
  Tree() {
    root = new V();
  }
  void insert(ll n, int comp) {
    root->insert(n, comp);
  }
  ll findClose(ll n, int comp) {
    cout << "comp: " << comp << endl;
    ll b = root->find(n);
    cout << b << endl;
    return b;
  }
};

int main(){
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  int n;
  cin >> n;
  allComps = vector<ll>(n);
  vector<ll> a(n);
  F(n) allComps[i] = i;
  Tree t;
  F(n) {cin >> a[i]; t.insert(a[i], allComps[i]); nToComp[a[i]] = i; }
  F(n) t.root->fixComp(i);
  ll res = 0;

  F(n - 1) res += (a[i] ^ t.findClose(a[i], nToComp[a[i]]));
  cout << res << endl;

  return 0;
}
