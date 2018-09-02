void getDivs(vector<int> & res, vector<P> & divs, int t, int i) {
  if (i >= divs.size()) {
    res.push_back(t);
    return;
  }
  int n = t;
  for (int j = 0; j <= divs[i].second; ++j) {
    getDivs(res, divs, n, i + 1);
    n *= divs[i].first;
  }
}

vector<int> fastDivisors(int n, vector<int> & sieve) {
  vector<P> divs = fastFactors(n, sieve);
  vector<int> exp(divs.size(), 0);
  vector<int> result;

  getDivs(result, divs, 1, 0);
  return result;
}

