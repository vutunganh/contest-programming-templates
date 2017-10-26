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
#define x first
#define y second
#include "../math/gem.cpp"

void print(mt m, int r) {
    auto res = gem(m,r);
    for(auto e : res.y) cout << e << " "; cout << endl;
    for(auto r : res.x) { for(auto e : r) cout << setw(15) << e; cout << endl; }
}

int main() {
    vector<vector<double>> m = {{1,3,1,9},{1,1,-1,1},{3,11,5,35}};
    vector<vector<double>> m2 = {{2,-1,0,1,0,0},{-1,2,-1,0,1,0},{0,-1,2,0,0,1}};
    mt a = { {1,2,3,4},{1,0,1,0},{5,3,2,4},{6,1,4,6} };
    mt b = { {1,2},{4,3},{5,6},{8,7} };
    mt eye(4,vector<double>(4));
    F(4) eye[i][i] = 1;
    print(merge(a,eye),4);
    print(merge(a,b),4);
    print(m,3);
    print(m2,3);
}

