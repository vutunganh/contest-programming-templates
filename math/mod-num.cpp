// cisla pro pocitani v modulu
// 1) deleni ma log(n) slozitost
// 2) deleni funguje pouze pro prvociselne moduly
// 3) u nasobeni muze dojit k preteceni
struct mll {
  const long long m = 1000000007; // set mod here
  long long v;
  mll(): v(0) {}
  mll(long long v): v(v%m) {}
  mll(int v): v(v%m) {}

  mll operator += (const mll & a) {
    v += a.v;
    v %= m;
    return v;
  }

  mll operator *= (const mll & a) {
    v *= a.v;
    v %= m;
    return v;
  }

  mll operator -= (const mll & a) {
    return v = (v%m - a.v%m + m) % m;
  }

  mll operator /= (const mll & a) {
    long long b = a.v;
    long long ex = m - 2;
    if(b==1)return v;
    long long r=1;
    while(ex){
      if(ex&1)r=(r*b)%m;
      ex>>=1;
      b=(b*b)%m;
    }
    v *= r;
    v %= m;
    return v;
  }

  mll operator %= (const mll & a) {
    v %= a.v;
    return v;
  }

  mll operator + (const mll & a) const {
    mll res(*this);
    res += a;
    return res;
  }

  mll operator - (const mll & a) const {
    mll res(*this);
    res -= a;
    return res;
  }

  mll operator * (const mll & a) const {
    mll res(*this);
    res *= a;
    return res;
  }

  mll operator / (const mll & a) const {
    mll res(*this);
    res /= a;
    return res;
  }

  mll operator % (const mll & a) {
    mll res(*this);
    res %= a.v;
    return res;
  }

  bool operator == (const mll & a) const { return v == a.v; }
  bool operator != (const mll & a) const { return v != a.v; }
  bool operator < (const mll & a) const { return v < a.v; }
  bool operator > (const mll & a) const { return v > a.v; }
  bool operator <= (const mll & a) const { return v <= a.v; }
  bool operator >= (const mll & a) const { return v >= a.v; }

  friend ostream & operator << (ostream & stream, const mll & a) {
    stream << a.v;
    return stream;
  }
};
