using ptt = double;
using pt = complex<ptt>;
#define x real()
#define y imag()
#define eq(a,b) (abs(a-(b)) <= EPS)
#define crs(a,b) (conj(a)*(b)).y
pt pts[MX];
ll n;
// returns set of points oriented counter clockwise with 1st point having
// minimal X and then Y coordinate
// first point and the last point is the same! (polygon representation)
// comment last push_back if you want just the vertices
// edit (1) to add also collinear points
vector<pt> conv_hull() {
    int lp = 0;
    FOR(i,1,n)
    if (pts[i].x < pts[lp].x || (eq(pts[i].x,pts[lp].x) && pts[i].y < pts[lp].y)) lp = i;
    swap(pts[0],pts[lp]);
    vector<pt> res;
    if (n < 3) {
        F(n) res.pb(pts[i]);
        res.pb(pts[0]);
        return res;
    }
    pt piv = pts[0];
    sort(pts+1,pts+n,[&](pt a, pt b) {
        pt d1 = a - piv;
        pt d2 = b - piv;
        if (eq(crs(d1,d2),0)) return norm(d1) < norm(d2);
        return crs(d1,d2) > 0; });
    res.pb(pts[0]); res.pb(pts[1]);
    ll i = 2;
    while (i < n) {
        ll j = res.size()-1;
        if (j == 0 or crs(res[j] - res[j-1],pts[i] - res[j]) > 0 + EPS) res.pb(pts[i++]); // (1) change + EPS to -EPS to add collinear segments as well
        else res.pop_back();
    }
    res.pb(pts[0]);
    return res;
}
