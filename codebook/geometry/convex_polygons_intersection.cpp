// Convex polyghons intersection in O(n)
// dependency: isin
vector<pt> conv_pol_ins(vector<pt> pa, vector<pt> qa) {
    int n = pa.size()-1;
    int m = qa.size()-1;
    int pi = 0;
    int qi = 0;
    vector<pt> res;
    char inside = ' ';
    int cnt = 0;
    bool fst = 0;
    auto fin = pt(0,0);
    while(cnt < 2*n + 2*m) {
        auto p = pa[pi];
        auto q = qa[qi];
        auto p_ =  pa[(pi+n-1)%n];
        auto q_ =  qa[(qi+m-1)%m];
        auto pd = p -  p_;      
        auto qd = q - q_;
        auto a1 = crs(pd,q-p_);
        auto a2 = crs(pd,q_-p_);
        auto b1 = crs(qd,p-q_);
        auto b2 = crs(qd,p_-q_);
        if ((a1*a2 < 0 + EPS and b1*b2 < 0 + EPS and max(max(abs(a1),abs(a2)),max(abs(b1),abs(b2))) > EPS)) {
            auto in = ins(p,p_,q,q_);
            if (res.empty() or !eq(abs(res.back()-in),0))
            res.pb(in);
            if (fst and eq(abs(in-fin),0)) break;
            if (not fst) fin = in,fst=1;
            if (a1 < 0 - EPS) inside = 'P';
            else inside = 'Q';
        }
        if (crs(qd,pd) >= 0 + EPS) {
            if(crs(qd,p-q_) >= 0 - EPS) {
                qi = (qi+1)%m;
                if (inside=='Q')
                    if (!eq(abs(res.back()-q),0))
                    res.pb(q);
            }
            else {
                pi = (pi+1)%n;
                if (inside=='P')
                    if (!eq(abs(res.back()-p),0))
                        res.pb(p);
            }
        }
        else {
            if(crs(pd,q-p_) >= 0 - EPS) {
                pi = (pi+1)%n;
                if (inside=='P') if (!eq(abs(res.back()-p),0)) res.pb(p);
            }
            else {
                qi = (qi+1)%m;
                if (inside=='Q') if (!eq(abs(res.back()-q),0)) res.pb(q);
            }
        }
        cnt++;
    }
    if (res.empty()) {
        if (isin(qa[0], pa)) return qa;
        if (isin(pa[0], qa)) return pa;
    }
    
    return res;
}
