ll d(ll s) {
  return s%MOD;
}

struct Matrix {
  Matrix(ll rows, ll columns):
      m(vector<vector<ll>>{rows, vector<ll>(columns, 0)})
      , rows(rows)
      , columns(columns) {
  }

  Matrix(int size, bool unit, int x):
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
    for (ll i = 0; i < rows; ++i) {
      for (ll j = 0; j < rows; ++j) {
        for (ll k = 0; k < rows; ++k) {
          result.m[i][j] = d(d(result.m[i][j]) + d(d(m[i][k]) * d(other.m[k][j])));
        }
      }
    }
    return result;
  }

  vector<vector<ll>> m;
  ll rows, columns;
};
