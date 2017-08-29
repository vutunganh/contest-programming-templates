#include <bits/stdc++.h>
using namespace std;

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

struct Pt
{
  ld x, y;
  bool operator<(const Pt& o) const
  {
    return x < o.x || (x == o.x && y < o.y);
    // return x < o.x - EPS || EQ(x, o.x)) && y < o.y - EPS;
  }

  Pt operator+(const Pt& o) const { return {x + o.x, y + o.y}; }

  Pt operator-(const Pt& o) const { return {x - o.x, y - o.y}; }

  Pt operator*(ld d) const { return {x * d, y * d}; }

  Pt operator/(ld d) const { return {x / d, y / d}; }
};

bool operator==(const Pt& a, const Pt& b) { return EQ(a.x - b.x, 0) && EQ(a.y - b.y, 0); }

bool operator!=(const Pt& a, const Pt& b) { return !(a == b); }

struct Line
{
  Pt a, b;
  bool operator<(const Line& o) const
  {
    Pt v = b - a, w = o.b - o.a;
    return atan2(v.y, v.x) < atan2(w.y, w.x);
  }
};

struct Segment
{
  Pt a, b;
  bool operator<(const Segment& o) const { return a < o.a || (a == o.a && b < o.b); }
  bool operator==(const Segment& o) const { return (a == o.a && b == o.b) || (a == o.b && b == o.a); }
};

int dcmp(ld x) { return fabs(x) < EPS ? 0 : (x < 0 ? - 1 : 1); }

ld cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; } 

ld dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }

ld rdist(Pt a) { return sqrt(dot(a, a)); }

ld ptptd(Pt a, Pt b) { return rdist(b - a); }

ld angle(Pt a, Pt b) { return dot(a, b) / rdist(a) / rdist(b); }

ld angle(Pt v) { return atan2(v.y, v.x); }

Pt normal(Pt v) { ld n = rdist(v); return {-v.y / n, v.x / n}; }

Pt toLen(Pt v, ld l) { return v * l / rdist(v); }

Pt fromPolar(ld len, ld angle) { return {len * cos(angle), len * sin(angle)}; }

Pt rotate(Pt a, ld rad) { return {a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)}; }

ld lnptd(Line l, Pt p) { return fabs(cross(p - l.a, l.b - l.a) / rdist(l.b - l.a)); }

Pt lnlni(Line p, Line q)
{
  Pt v = p.b - p.a;
  Pt w = q.b - q.a;
  ld t = cross(w, p.a - q.a) / cross(v, w);
  return p.a + v * t;
}

void abcline(Line& l, ld& a, ld& b, ld& c)
{
  a = l.a.y - l.b.y;
  b = l.a.x - l.b.x;
  c = cross(l.a, l.b);
}

ld abcptd(Line l, Pt p)
{
  ld a, b, c;
  abcline(l, a, b, c);
  return fabs(a * p.x + b * p.y + c) / sqrt(a*a + b*b);
}

ostream& operator<<(ostream& os, Pt& p)
{
  os << "[" << p.x << ", " << p.y << "]" << endl;
  return os;
}

ostream& operator<<(ostream& os, Line& l)
{
  os << l.a << " " << l.b << endl;
  return os;
}

int main()
{
  return 0;
}
