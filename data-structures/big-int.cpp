struct BigInt {
  typedef int NUM;
  vector<NUM> n; // change to char for memory efficiency
  int base = 10;

  BigInt() = default;
  BigInt(int m): n(vector<NUM>()) {
    if (m == 0) return;

    int sign = (m >= 0) ? 1 : -1;
    if (m < 0) m *= -1;
    while (m > 0) {
      n.push_back(m % base);
      m /= base;
    }
    fixRep();
    if (sign == -1) {
      *this = - *this;
    }
  }
  BigInt(const string & a) {
    if (a.size() == 0) return;
    if (a[0] == '-') {
      n = vector<NUM>(a.size() - 1);
      fromString(a, 1);
      *this = -*this;
    } else {
      n = vector<NUM>(a.size());
      fromString(a, 0);
    }
  }

  void fromString(const string & a, int start) {
    for (int i = 0; i < a.size() - start; ++i) {
      n[i] = a[a.size() - 1 - i] - '0';
    }
  }

  // addition
  void operator += (const BigInt & r) {
    if (r.size() > size())
      n.resize(r.size(), 0);

    for (int i = 0; i < size(); ++i) n[i] += r.n[i];

    fixNegatives();
    fixRep();
  }

  BigInt operator - () const {
    BigInt result = *this;
    for (int i = 0; i < result.size(); ++i) result.n[i] *= -1;
    result.fixNegatives();
    return result;
  }

  void operator -= (const BigInt & r) {
    *this += (- r);
  }

  BigInt operator + (const BigInt & r) const {
    BigInt result;
    result = *this;
    result += r;
    return result;
  }

  BigInt operator - (const BigInt & r) const {
    BigInt result = *this;
    result -= r;
    return result;
  }

  // multiplication
  void operator *= (const BigInt & r) {
    if (*this == 0 || r == 0) {
      *this = 0;
      return;
    }
    BigInt m;
    bool neg = (r < 0 != *this < 0);
    if (*this < 0) *this = -*this;
    if (r < 0) m = -r;
    else m = r;

    vector<vector<NUM>> matrix = vector<vector<NUM>>(size(), vector<NUM>(size() + m.size() + 1, 0));

    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < m.size(); ++j) {
        matrix[i][j + i] = n[i] * m.n[j];
      }
      // fix the base representation
      for (int j = 0; j < m.size() + 1; ++j) {
        matrix[i][j + i + 1] += matrix[i][j + i]/base;
        matrix[i][j + i] %= base;
      }
    }
    // sum together
    for (int i = 1; i < size(); ++i) {
      for (int j = 0; j < size() + m.size() + 1; ++j) {
        matrix[i][j] += matrix[i - 1][j];
      }
    }
    const int s = size();
    n.resize(size() + m.size() + 2, 0);
    for (int i = 0; i < s + m.size() + 1; ++i) {
      n[i] = matrix[s - 1][i];
    }
    fixRep();

    if (neg) *this = -*this;
  }

  BigInt operator * (const BigInt & r) const {
    BigInt result = *this;
    result *= r;
    return result;
  }

  // comparision
  bool operator == (const BigInt & r) const {
    if (r.size() != size()) return false;
    for (int i = 0; i < r.size(); ++i) {
      if (r.n[i] != n[i]) return false;
    }
    return true;
  }

  bool operator < (const BigInt & r) const {
    if (isNegative() && !r.isNegative()) return true;
    else if (!isNegative() && r.isNegative()) return false;
    else if (isNegative() && r.isNegative()) {
      return (-r < -*this);
    }
    if (r.size() > size()) return true;
    else if (r.size() < size()) return false;

    for (int i = r.size() - 1; i >= 0; --i) {
      if (r.n[i] > n[i]) return true;
      else if (r.n[i] < n[i]) return false;
    }
    return false;
  }

  bool operator > (const BigInt & r) const {
    return r < *this;
  }

  bool operator <= (const BigInt & r) const {
    return !(*this > r);
  }

  bool operator >= (const BigInt & r) const {
    return !(*this < r);
  }

  // O(n) kde n je pocet cifer
  void leftShift() {
    n.insert(n.begin(), 0);
  }

  bool isNegative() const {
    return (size() > 0 && n[size() - 1] < 0);
  }

  void fixNegatives() {
    for (int i = 0; i < size() - 1; ++i) {
      if (n[i] < 0) {
        n[i] += base;
        n[i + 1] --;
      }
    }
  }

  void fixRep() {
    for (int i = 1; i < size(); ++i) {
      n[i] += n[i - 1]/base;
      n[i - 1] %= base;
    }

    if (size() >= 1 && abs(n[size() - 1]) >= base) {
      n.push_back(n[size() - 1]/base);
      n[size() - 2] %= base;
    }
    // removed excess zeroes
    while (size() > 0 && n[size() - 1] == 0) n.pop_back();
  }

  int size() const { return (int) n.size(); }

  operator string() const {
    if (size() == 0) { return "0"; }
    string result;
    if (n[size() - 1] >= 0) {
      for (int i = size() - 1; i >= 0; --i) {
        result.push_back(n[i] + '0');
      }
    } else {
      result = "-" + (string)(- *this);
    }
    return result;
  }
};

