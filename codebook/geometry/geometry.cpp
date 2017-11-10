#define M_PI   3.14159265358979323846264338327950288
using ptt = double;
using pt = complex<ptt>;
using vpt = vector<pt>;
#define x real()
#define y imag()
#define eq(x,y) (abs(x-(y)) <= EPS)
// no basic function use this handy defines but you can use them
pt I(0,1);
#define dot(a,b) (conj(a)*(b)).x // dot product
#define crs(a,b) (conj(a)*(b)).y // cross product
pt projp(pt p, pt a, pt b) { return a+dot(p-a,b-a)/conj(b-a); } // project point onto line (a,b)
pt reflep(pt p, pt a,pt b) { return a+conj((p-a)/(b-a))*(b-a); } // reflect point across line (a,b)
pt rotp(pt a, pt p, ptt ang) { return (a-p) * polar(1.0, ang) + p; } // rotate point around p ang radians
#define sgn(x) ((x > -EPS) - (x < EPS)) // signum function

template<class T>
istream& operator>> (istream& is, complex<T>& p) {
    T value;
    is >> value;
    p.real(value);
    is >> value;
    p.imag(value);
    return is;
}

/*
(defined) Dot product: (conj(a) * b).x

(defined) Cross product: (conj(a) * b).y

Squared distance: norm(a - b)
 
Relative stretch: (b / a).x

Euclidean distance: abs(a - b)

Angle of elevation: arg(b - a)

Slope of line (a, b): tan(arg(b - a))

Polar to cartesian: polar(r, theta)

Cartesian to polar: point(abs(p), arg(p))

Rotation about pivot p: (a-p) * polar(1.0, theta) + p

Angle ABC: abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))

remainder normalizes the angle to be between [-PI, PI]. Thus, we can get the positive non-reflex angle by taking its abs value.
*/

pt ins(pt a, pt b, pt p, pt q) { // intersection; lines are represented by start and endpoint
    auto c1 = (conj(p - a)*(b - a)).y, c2 = (conj(q - a)*(b - a)).y;
    return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

// Polygons

// dependency: cross product (crs)
ptt area(vector<pt> pts) {
    ptt ar = 0;
    F(pts.size()-1) ar += crs(pts[i],pts[i+1]);
    return fabs(ar)/2;
}

// Compute centroid 
// (average of all points, intersection of median lines of triangle)
// - dependency: area, crs
pt centroid(const vector<polt> &pol) {
  pt c(0,0);
  ptt sc = 6.0 * area(pol);
  F(pol.size()-1) {
    c = c + (pol[i]+pol[i+1])*(pol[i].x*pol[i+1].y - pol[i+1].x*pol[i].y);
  }
  return c / sc;
}

// cuts polygon pol along the line
// keeps that polygon that is on the left side of line
// dependency: cross product (crs) and line intersection (ins)
vector<pt> cut(vector<pt> pol, pt a, pt b) {
    vector<pt> lp;
    for (int i = 0; i < pol.size(); i++) {
        ptt l1 = crs(b-a, pol[i]-a), l2 = 0;
        if (i != pol.size()-1) l2 = crs(b-a, pol[i+1]-a);
        if (l1 > -EPS) lp.pb(pol[i]);
        if (l1*l2 < -EPS) lp.pb(ins(pol[i], pol[i+1], a, b));
    }
    if (!lp.empty() && !(lp.back() == lp[0]))
        lp.pb(lp[0]);
    return lp;
}

// check whether point is inside a polygon
// dependency: cross product (crs)
bool isIn(pt p, vector<pt>& pol) {
    int wn=0;
    int n=pol.size()-1;
    for(int i=0;i<n;i++) {
        pt& p1=pol[i];
        pt& p2=pol[i+1];
        pt tmp = (p-p1)/(p2-p1);
        if(eq(tmp.y,0) and tmp.x >= -EPS and tmp.x <= 1 + EPS) return true; // on the edge
        auto k = crs(p2-p1,p-p1);
        auto d1= p1.y-p.y;
        auto d2= p2.y-p.y;
        if(k > EPS && d1 < EPS && d2 > EPS) wn++;
        if(k < -EPS && d2 < EPS && d1 > EPS) wn--;
    }
    return wn!=0;
}

// is polygon convex
// dependency: crs
bool is_conv(vector<pt> pol) {
    int sz = pol.size();
    if (sz <= 3) return 1; // degenerative (choose arbitrary)
    ptt pr = crs(pol[sz-1]-pol[0],pol[1]-pol[0]);
    F(sz-2) {
        ptt ac = crs(pol[i+1]-pol[i],pol[i+2]-pol[i]);
        if (ac*pr < -EPS) return 0;
        if (abs(ac) > pr) pr = ac;
    }
    return 1;
}

// projections onto line

// project point onto line segment
// dependency: projp
pt projpls(pt p,pt a,pt b) {
    ptt i = ((p-a)/(b-a)).x;
    return i < 0 + EPS ? a : i > 1 - EPS ? b : projp(p,a,b);
}

// add implicit ordering for complex numbers (beware that arg is slow as hell)

struct pt : complex<ptt> {
    using complex<ptt>::complex;
    bool operator<(const pt& o) const {
        return crs(*this,o) > EPS;
    }
};


