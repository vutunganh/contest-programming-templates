// line equation
struct ln { 
    ptt a, b, c;
    ptt gx(ptt yv) {
        return (b*yv + c)/-a;
    }
    ptt gy(ptt xv) {
        return (a*xv + c)/-b;
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
