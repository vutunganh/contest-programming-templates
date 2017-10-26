struct mt : vector<vector<ll>> {
    using vector::vector;
    int w() const { return at(0).size(); }
    int h() const { return size(); }
    mt(int h,int w) : vector<vector<ll>>(h,vector<ll>(w)) {};
    mt operator*(const mt ot) const {
        mt res(h(),ot.w());
        REP(i,h()) REP(j,ot.w()) REP(k,w()) {
            res[i][j] += (*this)[i][k]*ot[k][j];
            res[i][j] %= mod;
        }
        return res;
    }
};

mt pw(mt a, int n) {
    mt x(a.h(),a.w());
    F(min(a.h(),a.w())) x[i][i] = 1;
    while (n) {
        if (n & 1) {
            x = x * a;
        }
        a = a * a;
        n >>= 1;
    }
    return x;
}
