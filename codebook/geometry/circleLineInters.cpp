vector<pt> cir_ln_int(pt c, ptt r, pt a, pt b) {
    auto prc = a + ((conj(c-a)*(b-a).x)/conj(b-a);
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
