// let x be some number inserted into the trie. Then a = find(n) is such that n^x is the smallest possible.
// for example find(0) will find the smallest number
// declare the trie as: V trie;
struct V;
struct V {
  // left is 0, right is 1
  V* left = nullptr, *right = nullptr;
  ll num = 0; // information saved in the node
  int bit = 0; // index of the bit in the saved number
  const int bitlen = 32; // length of number saved in the trie
  ll leaves = 0; // assumes that no number is inserted twice

  void insert(ll n) {
    leaves ++;
    if (bit == bitlen) {
      num = n;
      return;
    } else {

      ll b = (n & (1 << (bitlen - 1 - bit)));
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

  ll find(ll n) const {
    int b = (n & (1 << (bitlen - 1 - bit)));
    //cout << n << " - " << bit << ", " << b << endl;
    ll res;
    if (bit == bitlen) {
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

  // returns the number of numbers x in the trie, such that x xor n >= mx
  ll findGreater(ll n, ll mx) const {
    cout << bit << " " << leaves << endl;
    // current bit of n
    ll b = (n & (1 << (bitlen - 1 - bit)));
    ll m = (mx & (1 << (bitlen - 1 - bit)));
    ll res = 0;
    if (bit == bitlen) {
      res = 1;
    } else {
      if (b == 0 && m == 0) {
        if (right) res += right->leaves;
        if (left) res += left->findGreater(n, mx);
      } else if (b == 0 && m != 0) {
        if (right) res += right->findGreater(n, mx);
      } else if (b != 0 && m == 0) {
        if (left) res += left->leaves;
        if (right) res += right->findGreater(n, mx);
      } else if (b != 0 && m != 0) {
        if (left) res += left->findGreater(n, mx);
      } else {
        assert(false);
      }
    }

    return res;
  }

  void erase(ll n) {
    leaves --;
    if (bit == bitlen) {
      return;
    }

    ll b = (n & (1 << (bitlen - 1 - bit)));
    if (b == 0) {
      left->erase(n);

      if (left->left == nullptr && left->right == nullptr) {
        delete left;
        left = nullptr;
      }
    } else {
      right->erase(n);

      if (right->left == nullptr && right->right == nullptr) {
        delete right;
        right = nullptr;
      }
    }
  }
};
