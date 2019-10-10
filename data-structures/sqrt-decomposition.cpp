#define SQR 320
 
struct Block {
  Block(ll *a, ll start, ll end): a(a), start(start), end(end), sum(0), sub(0) {
    init();
  }
 
  ll get(ll st, ll en) {
    //cout << "st: " << st << ", en: " << en << endl;
    //cout << "my st: " << start << ", en: " << end << endl;
    if (st <= start && en >= end) return sum;
    else {
      ll res = 0;
      for (ll i = max(st, start); i <= min(en, end); ++ i) {
        // TODO: change here
      }
      return res;
    }
  }
 
  void set(ll st, ll en, ll val) {
    if (st <= start && en >= end) setAll(val);
    else {
      for (ll i = max(st, start); i <= min(en, end); ++ i) {
        // TODO: change here
      }
    }
  }
 
  // original data
  ll *a;
  ll start, end;
 
  void init() {
    // TODO: change here
  }
 
  void setAll(ll val) {
    // TODO: change here
  }
 
  void setEl(ll k, ll val) {
    // TODO: change here
  }
};
 
struct SqrtDecomp {
  SqrtDecomp(ll *a, ll n): a(a), n(n), blocks(vector<Block>()) {
    F((n + SQR - 1) / SQR) {
      blocks.PB(Block(a, i*SQR, min((i+1)*(SQR) - 1, n - 1)));
    }
  }
 
  ll get(ll st, ll en) {
    ll res = 0;
    F(blocks.size()) res += blocks[i].get(st, en); // TODO: change the operation here
    return res;
  }
 
  void set(ll st, ll en, ll val) {
    F(blocks.size()) blocks[i].set(st, en, val);
  }
  
  vector<Block> blocks;
  ll* a;
  ll n;
};
