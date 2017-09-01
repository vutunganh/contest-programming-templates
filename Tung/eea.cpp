#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define FOR(i,a,b) for (auto i = (a); i < (b); ++i)
#define F(a,b) FOR(i, (a), (b))
#define FF(a,b) FOR(j, (a), (b))
#define aa first
#define bb second
#define PB push_back
#define MOD ((int)1e9+7)
#define INF (1<<30)
#define LINF (1<<62LL)
#define EPS (1e-10)
#define EQ(a,b) (fabs(a - b) <= fabs(a + b) * EPS)

int xGCD(int a, int b, int &x, int &y) {
  if(b == 0) return x = 1, y = 0, a;

  int x1, y1, res = xGCD(b, a % b, x1, y1);
  return res = xGCD(b, a % b, x1, y1), x = y1, y = x1 - (a / b) * y1, res;
}

int main(void)
{
  ios::sync_with_stdio(false);
  return 0;
}
