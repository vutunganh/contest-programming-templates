ll d(ll s) {
  return s%MOD;
}

struct Matrix {
  Matrix(int rows, int columns):
      m(vector<vector<ll>>{rows, vector<ll>(columns, 0)})
      , rows(rows)
      , columns(columns) {
  }
  Matrix(int size, bool unit = false):
      m(vector<vector<ll>>{size, vector<ll>(size, 0)})
    , rows(size), columns(size) {
    if (unit) {
      for (int i = 0; i < size; ++i) {
        m[i][i] = 1;
      }
    }
  }

  Matrix operator * (const Matrix & other) const {
    Matrix result(rows, columns);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          result.m[i][j] = d(d(result.m[i][j]) + d(d(m[i][k]) * d(other.m[k][j])));
        }
      }
    }
    return result;
  }

  vector<vector<ll>> m;
  int rows, columns;
};


