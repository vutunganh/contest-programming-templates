// can add only add intervals of size 1
// WARNING: Can be rather slow!
struct Intervals {
  int n;
  map<int,int> stToEnd;
  map<int,int> enToSt;

  // change depending on the problem
  ll cmp(ll x) { return x*(x+1)/2; }

  void eraseByEnd(int x) {
    int start = enToSt[x];
    enToSt.erase(x);
    stToEnd.erase(start);
    val -= cmp(x - start + 1);
  }
  void eraseByStart(int x) {
    int end = stToEnd[x];
    enToSt.erase(end);
    stToEnd.erase(x);
    val -= cmp(end - x + 1);
  }
  void addInterval(int start, int end) {
    stToEnd[start] = end;
    enToSt[end] = start;
    val += cmp(end - start + 1);
  }

  int add(int x) {
    // merge two neighboring together
    if (stToEnd.find(x + 1) != stToEnd.end() && enToSt.find(x - 1) != enToSt.end()) {
      ll end = stToEnd[x + 1];
      ll start = enToSt[x - 1];

      eraseByEnd(end);
      eraseByStart(start);
      addInterval(start, end);
    } else if (stToEnd.find(x + 1) != stToEnd.end()) {
      int end = stToEnd[x + 1];
      eraseByStart(x + 1);
      addInterval(x, end);
    } else if (enToSt.find(x - 1) != enToSt.end()) {
      int start = enToSt[x - 1];
      eraseByEnd(x - 1);
      addInterval(start, x);
    } else addInterval(x, x);
    return val;
  }

  int remove(int x) {
    //cout << "removing " << x << endl;
    if (stToEnd.find(x) != stToEnd.end() && enToSt.find(x) != enToSt.end()) {
      eraseByStart(x);
    } else if (stToEnd.find(x) != stToEnd.end()) {
      int end = stToEnd[x];
      eraseByStart(x);
      addInterval(x + 1, end);
    } else if (enToSt.find(x) != enToSt.end()) {
      int start = enToSt[x];
      eraseByEnd(x);
      addInterval(start, x - 1);
    } else {
      // split interval
      auto f = enToSt.lower_bound(x);
      int start = f->second;
      int end = f->first;
      if (start < x) {
        eraseByStart(start);
        addInterval(start, x - 1);
        addInterval(x + 1, end);
      }
    }
    return val;
  }

  // sum of squares of sizes of intervals
  ll val;
};
