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
#define EPS (1e-10)
#define INF (1LL<<61)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define all(x) begin(x),end(x)
#define IN(n) ll n;cin >> n;
#define xx first
#define yy second

using ptt = double;
using pt = complex<ptt>;
#define x real()
#define y imag()
#define eq(x,y) (abs(x-(y)) <= EPS)
struct ln { 
    ptt a, b, c;
    ptt gx(ptt y) {
        return (b*y + c)/a;
    }
    ptt gy(ptt x) {
        return (a*x + c)/b;
    }
    bool dege() {
        return eq(a,0) or eq(b,0);
    }
};
#define dot(a,b) (conj(a)*(b)).x // dot product
#define crs(a,b) (conj(a)*(b)).y // cross product

//ln tolni(pt a, pt b) {
//    ln l;
//    if (eq(a.x,b.x)) {
//        l.a = 1; l.b = 0; l.c = -a.x;
//    }
//    else {
//        l.a = (b.y - a.y)/(a.x - b.x);
//        l.b = 1;
//        l.c = -l.a*a.x - a.y;
//    }
//    return l;
//}

// for precise calculation (integers)
ln toln(pt a, pt b) {
    ln l;
    l.a = (b.y - a.y);
    l.b = (a.x - b.x);
    l.c = -l.a*a.x - l.b*a.y;
    return l;
}

#define sq(a) ((a)*(a))
// squared distance from point to line
ptt ln2ptdist(ln l, pt p) {
    return sq(l.a*p.x+l.b*p.y+l.c)/(sq(l.a)+sq(l.b));
}

bool para(ln l1, ln l2) {
    if (l1.dege() or l2.dege()) return eq(l1.a,l2.a) or eq(l1.b,l2.b);
    return eq(l1.a*l2.b,l1.b*l2.a);
}

bool same(ln l1, ln l2) {
    if (para(l1,l2)) {
        if (eq(l1.a,0)) return eq(l1.b*l2.c,l1.c*l2.b);
        return eq(l1.a*l2.c,l1.c*l2.a);
    }
    return 0;
}

pt lins(ln l1, ln l2) {
    return {(l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b),
            (l2.a * l1.c - l1.a * l2.c) / (l2.b * l1.a - l1.b * l2.a)};
}

int main(void) {
	ios_base::sync_with_stdio(false);
    ln l1 = {1, 2, 3};
    ln l2 = {2, 4, 6};
    ln l4 = {2, 4, 7};
    ln l3 = {0, 1, 2};
    D(para(l1,l2));
    D(same(l1,l2));
    D(para(l1,l4));
    D(same(l1,l4));
    D(l3.dege());
    ln l = toln(pt(1,1), pt(2,0));
    ln l6 = toln(pt(0,0), pt(0,1));
    D(l.a,l.b,l.c);
    D(ln2ptdist(l,pt(0,0)));
    D(lins(l,l6));
 	return 0;
}

