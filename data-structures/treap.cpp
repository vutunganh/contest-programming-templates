#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct TP{
  using tp=ll;
  tree<tp,null_type,less<tp>,rb_tree_tag,tree_order_statistics_node_update> T;
  void add(tp a){T.insert(a);}
  void del(tp a){T.erase(a);}
  int cnt(tp a){return T.order_of_key(a);} // returns index 'a' starting with 0
  tp kth(int a){return *T.find_by_order(a);}
  int gt(tp b,tp e){return cnt(e+1)-cnt(b);} // number of elements between 'b' and 'e' inclusive
  int sz(){return T.size();}
};
