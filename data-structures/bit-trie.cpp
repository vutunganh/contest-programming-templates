// let x be some number inserted into the trie. Then a = find(n) is such that n^x is the smallest possible.
// for example find(0) will find the smallest number
// declare the trie as: V trie;
struct V;
struct V {
  // 0, 1
  V* left = nullptr, *right = nullptr;
  ll num = 0; // information saved in the node
  int bit = 0; // index of the bit in the saved number
  const int bitlen = 32; // length of number saved in the trie

  void insert(ll n) {
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

  void erase(ll n) {
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
