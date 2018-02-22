// let x be some number inserted into the trie. Then a = find(n) is such that a^x is the smallest possible.
struct V;
struct V {
  // 0, 1
  V* left, *right;
  ll num;
  int bit;

  void insert(ll n) {
    if (bit == 31) {
      num = n;
      return;
    } else {

      ll b = (n & (1 << (30 - bit)));
      if (b == 0) {
        if (left == nullptr) left = new V();
        left->bit = bit + 1;
        left->insert(n);
      } else {
        if (right == nullptr) right = new V();
        right->bit = bit + 1;
        right->insert(n);
      }

    }

  } 

  ll find(ll n) {
    int b = (n & (1 << (30 - bit)));
    //cout << n << " - " << bit << ", " << b << endl;
    ll res;
    if (bit == 31) {
      res = num;
    } else {

      if ((b == 0 && left != nullptr) || right == nullptr) {
        res = left->find(n);
      } else {
        res = right->find(n);
      }
    }

    return res;
  }
};
