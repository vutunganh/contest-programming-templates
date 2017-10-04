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

struct Pt {
  ld x, y;
  bool operator<(const Pt& o) const {
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

struct Line {
  Pt a, b;
  bool operator<(const Line& o) const {
    Pt v = b - a, w = o.b - o.a;
    return atan2(v.y, v.x) < atan2(w.y, w.x);
  }
};

struct Segment {
  Pt a, b; // begin and end of segment
  bool operator<(const Segment& o) const { return a < o.a || (a == o.a && b < o.b); }
  bool operator==(const Segment& o) const { return (a == o.a && b == o.b) || (a == o.b && b == o.a); }
};

struct Circ {
  Pt s;
  ld r;
  Pt point(double ag) const { return {s.x + cos(ag) * r, s.y + sin(ag) * r}; }
  bool operator<(const Circ& o ) { return r < o.r; }
};

// basics
int dcmp(ld x) { return fabs(x) < EPS ? 0 : (x < 0 ? - 1 : 1); }

ld eps(ld x) { return x / EPS; }

// vector
ld cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; } 

ld dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }

ld rdist(Pt a) { return sqrt(dot(a, a)); }

ld ppd(Pt a, Pt b) { return rdist(b - a); }

ld angle(Pt a, Pt b) { return dot(a, b) / rdist(a) / rdist(b); }

ld angle(Pt v) { return atan2(v.y, v.x); }

Pt normal(Pt v) { ld n = rdist(v); return {-v.y / n, v.x / n}; }

// transformations
Pt toLen(Pt v, ld l) { return v * l / rdist(v); }

Pt fromPolar(ld len, ld angle) { return {len * cos(angle), len * sin(angle)}; }

Pt rotate(Pt a, ld rad) { return {a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)}; }

ld degToRad(ld deg) { return deg / 180 * M_PI; }

// lines
ld lpd(Line l, Pt p) { return fabs(cross(p - l.a, l.b - l.a) / rdist(l.b - l.a)); }

// TODO: y dis work?
ld langle(Line l) { 
  ld tmpa = angle(l.b - l.a);
  if (tmpa < 0) tmpa += M_PI;
  return tmpa;
}

bool lle(Line p, Line q) {
  return EQ(cross(p.a - q.b, q.a - q.b), 0) &&
         EQ(langle(p), langle(q));
}

bool llparallel(Line p, Line q) { return EQ(langle(p), langle(q)); }

Pt lli(Line p, Line q) {
  Pt v = p.b - p.a;
  Pt w = q.b - q.a;
  ld t = cross(w, p.a - q.a) / cross(v, w);
  return p.a + v * t;
}

Pt lpvert(Line l, Pt p) {
  Pt v = normal(l.b - l.a);
  return lli(l, {p, p + v});
}

// segments
bool sgsgcolinear(const Segment& p, const Segment& q) { return p.b - p.a == q.b - q.a || p.b - p.a == q.a - q.b; }

bool sgsgbeg(const Segment& p, const Segment& q) { return p.a == q.a || p.a == q.b || p.b == q.a || p.b == q.b; }

// abc lines
void abcline(Line& l, ld& a, ld& b, ld& c) {
  a = l.a.y - l.b.y;
  b = l.a.x - l.b.x;
  c = cross(l.a, l.b);
}

ld abcptd(Line l, Pt p) {
  ld a, b, c;
  abcline(l, a, b, c);
  return fabs(a * p.x + b * p.y + c) / sqrt(a*a + b*b);
}

ostream& operator<<(ostream& os, Pt& p) {
  os << "[" << p.x << ", " << p.y << "]" << endl;
  return os;
}

ostream& operator<<(ostream& os, Line& l) {
  os << l.a << " " << l.b << endl;
  return os;
}

int main()
{
  Line l = {{-1, -1}, {1, 1}};
  Line k = {{1, 1}, {-1, -1}};
  assert(lle(l, k));
  assert(llparallel(l, k));
  l = k;
  assert(lle(l, k));
  assert(llparallel(l, k));
  l = {{-1, 1}, {1, -1}};
  k = {{1, -1}, {-1, 1}};
  assert(lle(l, k));
  assert(llparallel(l, k));
  l = {{0, 0}, {0, 10}};
  k = {{400, 500}, {400, 15525.2}};
  assert(llparallel(l, k));
  return 0;
}
