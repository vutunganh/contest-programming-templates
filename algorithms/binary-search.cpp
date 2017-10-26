#include <utility>
#include <climits>

//
// Created by maty on 8/13/17.
//
typedef long long ll;
using namespace std;

// dotazovana funkce pri binarnim vyhledavani
// nutne dodefinovat zacatek/konec pole jako -INF/+INF
ll fn(ll i) {
  //if (i < 0) return INT_MIN;
  //if (i >= a.size()) return INT_MAX;
  //return a[i];
}

// nalezne posledni prvek, pro ktery plati, ze je <= val
// napr kdyz hledame maximum nejake funkce omezene podminkou
// vraci (hodnota, index)
// pokud nenalezeno => index == -1
// O( fn * log(n) )
pair<ll,int> rightmostFind(int l, int r, ll val) {
  if (r >= l) {
    const int mid = (r + l) / 2;

    ll res = fn(mid);
    ll resNext = fn(mid + 1);

    if (res <= val && resNext > val) {
      return {res, mid};
    } else if (res > val) {
      return rightmostFind(l, mid - 1, val);
    } else {
      return rightmostFind(mid + 1, r, val);
    }
  }
  // nenalezeno
  return {0, -1};
}

// nalezne libovolny prvek = val
pair<ll,int> binarySearch(int l, int r, ll val) {
  if (r >= l) {
    const int mid = (r + l) / 2;

    ll res = fn(mid);

    if (res == val) {
      return {res, mid};
    } else if (res > val) {
      return binarySearch(l, mid - 1, val);
    } else {
      return binarySearch(mid + 1, r, val);
    }
  }
  // nenalezeno
  return {0, -1};
};

// nalezne prvni > val
pair<ll,int> upperBound(int l, int r, ll val) {
  if (r >= l) {
    const int mid = (r + l) / 2;

    ll res = fn(mid);
    ll resPrev = fn(mid - 1);

    if (res > val && resPrev <= val) {
      return {res, mid};
    } else if (res > val) {
      return upperBound(l, mid - 1, val);
    } else {
      return upperBound(mid + 1, r, val);
    }
  }
  // nenalezeno
  return {0, -1};
};

// nalezne prvni >= val
pair<ll,int> lowerBound(int l, int r, ll val) {
  if (r >= l) {
    const int mid = (r + l) / 2;

    ll res = fn(mid);
    ll resPrev = fn(mid - 1);

    if (res >= val && resPrev < val) {
      return {res, mid};
    } else if (res >= val) {
      return lowerBound(l, mid - 1, val);
    } else {
      return lowerBound(mid + 1, r, val);
    }
  }
  // nenalezeno
  return {0, -1};
};