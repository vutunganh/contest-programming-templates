#include "../template.cpp"

// Suffix array construction in O(L log^2 L) time.  Routine for
// computing the length of the longest common prefix of any two
// suffixes in O(log L) time. (L=length of str)
//
// INPUT:   string s
//
// OUTPUT:  array suffix[] such that suffix[i] = index (from 0 to L-1)
//          of substring s[i...L-1] in the list of sorted suffixes.
//          That is, if we take the inverse of the permutation suffix[],
//          we get the actual suffix array.

struct SuffixArray {
  const ll L;
  string s;
  vector<vll> P;
  vector<pair<pll,ll>> M;
  // O(L log^2 L)
  SuffixArray(const string &s) : L(s.size()), s(s), P(1, vll(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.pb(vll(L, 0));
      for (int i = 0; i < L; i++) 
             M[i] = {{P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000}, i};
      sort(all(M));
      for (int i = 0; i < L; i++) 
             P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }
  vll GetSuffixArray() { return P.back(); }
  // Returns length of the longest common prefix of s[i...L-1] and s[j...L-1]
  // O(log L)
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  }
};

int main() {

  // bobocel is the 0'th suffix
  //  obocel is the 5'th suffix
  //   bocel is the 1'st suffix
  SuffixArray suffix("bobocel");
  vll v = suffix.GetSuffixArray();
  // Expected output: 0 5 1 6 2 3 4
  //                  2
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  cout << suffix.LongestCommonPrefix(0, 2) << endl;
}