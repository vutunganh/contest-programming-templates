#include "../template.cpp"
//<<<
// Set of elements with O(log N) operations
// Enables bot Position and Key approach to elements.
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T=int,class Comp=less<T>>
struct KeyOrderSet{
    tree<
    	T, // Key type
    	null_type, // Mapped-policy
    	Comp,  // Key comparison functor
    	rb_tree_tag,
    	tree_order_statistics_node_update 
    > _t;
    void ins(T a) { _t.insert(a); }
    void del(T a) { _t.erase(a); }
    int size() { return _t.size(); }
    int order(T a) { // return position of element if it would be in this set
    	return _t.order_of_key(a);
    }
    T kth(int a) { // return kth (zero based) element in set
    	return *_t.find_by_order(a);
    }
    bool has(T a) { // contains element?
    	return _t.find(a) !=_t.end();
    } // and other set-like features (begin(),end(),...) can be added...
};

// usage example: pair with descending first, ascending second:
struct cmp {bool operator()(const pll &a, const pll &b) const {
	return a.x==b.x ? a.y < b.y : a.x > b.x;   ; // x DESC, y ASC
}};
int main() {
	KeyOrderSet<pll,cmp> kos;
	kos.ins({1,1});
	kos.ins({1,1});
	kos.ins({4,4});
	dbg("Size: ", kos.size());
	dbg("Order {1,1}: ", kos.order({1,1}));
	dbg("Contains {1,1}? ", kos.has({1,1})?"True":"False");
	dbg("Contains {1,2}? ", kos.has({1,2})?"True":"False");
}
//>>>