#include <bits/stdc++.h>
const int MX = 4;

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

#define pb push_back
#define FOR(i, m, n) for (ll i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
#define D(x) cerr << __LINE__ << ": " << #x << " : " << x << endl
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define all(x) begin(x),end(x)
#define IN(n) ll n;cin >> n;
#include "../geometry/convex_hull.cpp"
#include "catch.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE("Convex hull simple", "[convex hull]") {
    pts[0] = pt(0,0);
    pts[1] = pt(1,1);
    pts[2] = pt(2,2);
    pts[3] = pt(3,3);
    n = 4;
    auto res = conv_hull();
    REQUIRE(abs(res[0] - res.back()) < EPS);
    REQUIRE(abs(res[1] - pt(3,3)) < EPS);
    REQUIRE(res.size() == 3);
}



