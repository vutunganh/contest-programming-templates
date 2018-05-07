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

struct V;
struct V {
  // 0, 1
  V* left, *right;
  ll num;
  int bit;

  void insert(ll n) {
    if (bit == 31) {
      num = n;
      return;
    } else {

      ll b = (n & (1 << (30 - bit)));
      if (b == 0) {
        if (left == nullptr) left = new V();
        left->bit = bit + 1;
        left->insert(n);
      } else {
        if (right == nullptr) right = new V();
        right->bit = bit + 1;
        right->insert(n);
      }

    }

  } 

  ll find(ll n) {
    int b = (n & (1 << (30 - bit)));
    //cout << n << " - " << bit << ", " << b << endl;
    ll res;
    if (bit == 31) {
      res = num;
    } else {

      if ((b == 0 && left != nullptr) || right == nullptr) {
        res = left->find(n);
      } else {
        res = right->find(n);
      }
    }

    return res;
  }
};

struct Tree {
  V* root;
  Tree() {
    root = new V();
  }
  void insert(ll n) {
    root->insert(n);
  }
  ll findClose(ll n) {
    ll b = root->find(n);
    //cout << b << endl;
    return b;
  }
};

Tree t;

ll solve(vector<ll> a, int b, V* root) {
  if (root == nullptr) return 0;
  if (a.size() <= 1) return 0;

  // find the edge
  vector<ll> l, r;
  F(a.size()) {
    //cout << a[i] << endl;
    if (((1 << (30 - b)) & a[i]) == 0) l.push_back(a[i]);
    else r.push_back(a[i]);
  }
  if (l.empty()) return solve(r, b + 1, root->right);
  if (r.empty()) return solve(l, b + 1, root->left);

  ll best = numeric_limits<ll>::max();
  if (!l.empty() && !r.empty()) {
    V* rr = root->right;
    F(l.size()) {
      //cout << "!" << l[i] << endl;
      best = min(best, (ll)(l[i] ^ rr->find(l[i])));
    }
  }

  //cout << best << endl;
  return best + solve(l, b + 1, root->left) + solve(r, b + 1, root->right);
}

int main() {
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  F(n) {cin >> a[i]; t.insert(a[i]); }
  cout << solve(a, 0, t.root) << endl;

  return 0;
}
