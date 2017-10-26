// circles

// 2 circles intersection
vector<pt> cirs_int(pt c1, ptt r1, pt c2, ptt r2) {
    auto cl = c1 - c2;
    auto cln = cl/abs(cl);
    if (eq(norm(cl),0.0)) {
        if(eq(r1,r2)) return {c1+r1,c1-r1,c2-r1}; // return some three points
        return {};
    }
    if (eq(abs(cl),r1 + r2)) {
        return {c2+cln*r2};
    }
    if (abs(cl) > r1 + r2 - EPS) {
        return {};
    }
    auto ang = polar(r2,acos((norm(cl)+r2*r2-r1*r1)/(2*r1*abs(cl))));
    return {c2+cln*conj(ang),c2+cln*ang};
}

// circle and line intersection
vector<pt> cir_ln_int(pt c, ptt r, pt a, pt b) {
    auto prc = a + ((conj(b-a)*c).x)/conj(b-a);
    auto cpr = prc - c;
    auto ul = (b-a)/abs(b-a);
    if (eq(abs(cpr),r)) {
        return {prc};
    }
    if (abs(cpr) > r) {
        return {};
    }
    auto len = sqrt(r*r-norm(cpr));
    return {prc + len*ul,prc - len*ul};
}