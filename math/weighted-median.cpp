// vector of pairs {number, counts of number}
// if the sequence is sorted, change to this and remove sort:
//ll weightedMedian(const vector<pair<ll,ll>> & cnts) {
ll weightedMedian(vector<pair<ll,ll>> cnts) {
  sort(cnts.begin(), cnts.end());
  ll sum = 0;
  F(cnts.size()) {
    sum += cnts[i].bb;
  }
  ll pf = 0;
  F(cnts.size()) {
    pf += cnts[i].bb;
    if (pf >= (sum+1)/2) return cnts[i].aa;
  }
  return cnts.back().aa;
}
