#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

#define pb push_back
#define FOR(i, m, n) for (ll i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
struct d_ {template<typename T> d_ & operator ,(const T & x) { cerr << ' ' <<  x; return *this;}} d_t;
#define D(args ...) { d_t,"|",__LINE__,"|",#args,":",args,"\n"; }
#define dbg(args ...) D(args)
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define all(x) begin(x),end(x)
#define IN(n) ll n;cin >> n;
#define x first
#define y second

struct pt{
    double x, y, z;
    pt(){};
    pt(double _x, double _y, double _z){ x=_x; y=_y; z=_z; }
    pt operator+ (pt p) { return pt(x+p.x, y+p.y, z+p.z); }
    pt operator- (pt p) { return pt(x-p.x, y-p.y, z-p.z); }
    pt operator* (double c) { return pt(x*c, y*c, z*c); }
};

double dot(pt a, pt b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

pt crs(pt a, pt b) {
    return pt(a.y*b.z-a.z*b.y,
                 a.z*b.x-a.x*b.z,
                 a.x*b.y-a.y*b.x);
}

double norm(pt a) {
    return dot(a,a);
}

double abs(pt a) {
    return sqrt(norm(a));
}

// compute a, b, c, d such that all pts lie on ax + by + cz = d. TODO: test this
void planeFromPts(pt p1, pt p2, pt p3, double& a, double& b, double& c, double& d) {
	pt normal = crs(p2-p1, p3-p1);
	a = normal.x; b = normal.y; c = normal.z;
	d = -a*p1.x-b*p1.y-c*p1.z;
}

// project pt onto plane. TODO: test this
pt ptPlaneProj(pt p, double a, double b, double c, double d) {
	double l = (a*p.x+b*p.y+c*p.z+d)/(a*a+b*b+c*c);
	return pt(p.x-a*l, p.y-b*l, p.z-c*l);
}

// distance from pt p to plane aX + bY + cZ + d = 0
double ptPlaneDist(pt p, double a, double b, double c, double d){
    return abs(a*p.x + b*p.y + c*p.z + d) / sqrt(a*a + b*b + c*c);
}

// distance between parallel planes aX + bY + cZ + d1 = 0 and
// aX + bY + cZ + d2 = 0
double planePlaneDist(double a, double b, double c, double d1, double d2){
    return fabs(d1 - d2) / sqrt(a*a + b*b + c*c);
}

// square distance between pt and line
double ptLineDistSq(pt x1, pt x2, pt x0){
    return norm(crs(x2-x1,x1-x0))/norm(x2-x1);
}

// Distance between lines ab and cd.
double lineLineDistanceSq(pt x1, pt x2, pt x3, pt x4) {
    pt a = x2 - x1;
    pt b = x4 - x3;
    pt c = x3 - x1;
    return norm(dot(c,crs(a,b)))/norm(crs(a,b));
}

double signedTetrahedronVol(pt A, pt B, pt C, pt D) {
	double A11 = A.x - B.x;
	double A12 = A.x - C.x;
	double A13 = A.x - D.x;
	double A21 = A.y - B.y;
	double A22 = A.y - C.y;
	double A23 = A.y - D.y;
	double A31 = A.z - B.z;
	double A32 = A.z - C.z;
	double A33 = A.z - D.z;
	double det =
		A11*A22*A33 + A12*A23*A31 +
		A13*A21*A32 - A11*A23*A32 -
		A12*A21*A33 - A13*A22*A31;
	return det / 6;
}

// Parameter is a vector of vectors of pts - each interior vector
// represents the 3 pts that make up 1 face, in any order.
// Note: The polyhedron must be convex, with all faces given as triangles.
double polyhedronVol(vector<vector<pt> > poly) {
	int i,j;
	pt cent(0,0,0);
	for (i=0; i<poly.size(); i++)
		for (j=0; j<3; j++)
			cent=cent+poly[i][j];
	cent=cent*(1.0/(poly.size()*3));
	double v=0;
	for (i=0; i<poly.size(); i++)
		v+=fabs(signedTetrahedronVol(cent,poly[i][0],poly[i][1],poly[i][2]));
	return v;
}

int main() {
    D(lineLineDistanceSq(pt(0,0,0),pt(1,1,1),pt(0,1,1),pt(1,0,2)));
}
