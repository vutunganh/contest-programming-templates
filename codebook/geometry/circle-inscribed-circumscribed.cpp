// triangles
// inscribed circle center (uses ins)
pt incirc(pt a, pt b, pt c) {
    pt ct1 = (a + b)/2.0;
    pt ct2 = (b + c)/2.0;
    pt an(1,1);
    return ins(ct1,ct1*an,ct2,ct2*an);
}
// circumscribed circle center (for radius output abs(ct1 - ins(...))  (uses ins)
// radius using only lengths R = a × b × c/(4 × A).
pt circirc(pt a, pt b, pt c) {
    pt ct1 = (a+b)/2.0;
    pt ct2 = (b+c)/2.0;
    return ins(c,ct1,a,ct2);
}
