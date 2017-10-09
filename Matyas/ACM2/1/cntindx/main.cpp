#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


ll fn(ll i, vector<int> & a) {
  if (i < 0) return INT_MIN;
  if (i >= a.size()) return INT_MAX;
  return a[i];
}

// nalezne prvni >= val
pair<ll,int> lowerBound(int l, int r, ll val, vector<int> & a) {
  if (r >= l) {
    const int mid = (r + l) / 2;

    ll res = fn(mid, a);
    ll resPrev = fn(mid - 1, a);

    if (res >= val && resPrev < val) {
      return {res, mid};
    } else if (res >= val) {
      return lowerBound(l, mid - 1, val, a);
    } else {
      return lowerBound(mid + 1, r, val, a);
    }
  }
  // nenalezeno
  return {0, -1};
};


// nalezne posledni prvek, pro ktery plati, ze je <= val
// napr kdyz hledame maximum nejake funkce omezene podminkou
// vraci (hodnota, index)
// pokud nenalezeno => index == -1
// O( fn * log(n) )
pair<ll,int> rightmostFind(int l, int r, ll val, vector<int> & a) {
  if (r >= l) {
    const int mid = (r + l) / 2;

    ll res = fn(mid, a);
    ll resNext = fn(mid + 1, a);

    if (res <= val && resNext > val) {
      return {res, mid};
    } else if (res > val) {
      return rightmostFind(l, mid - 1, val, a);
    } else {
      return rightmostFind(mid + 1, r, val, a);
    }
  }
  // nenalezeno
  return {0, -1};
}



int main() {
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  stack<int> st;
  map<int,vector<int>> mp;
  for (int i = 0; i < q; ++ i) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      st.push(x);
      if (mp.find(x) == mp.end())
        mp[x] = vector<int>();

      mp[x].push_back(st.size());
    } else if (op == 0) {
      if (st.empty()) {
        cout << "invalid" << endl;
      } else {
        mp[st.top()].pop_back();
        st.pop();
      }
    } else if (op == 2) {
      int x, ii, ji;
      cin >> x >> ii >> ji;

      auto left = lowerBound(0, mp[x].size(), ii, mp[x]);
      auto right = rightmostFind(0, mp[x].size(), ji, mp[x]);
      cout << right.second - left.second + 1 << endl;
    }
  }
}
