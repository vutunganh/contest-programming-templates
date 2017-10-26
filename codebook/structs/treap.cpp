#include "../template.cpp"
using namespace std;

// Treap data structure
// ========
// Set structure with logarithmic inserts and deletes.
// - Heap(min) order on priority, BST ordered on key
// Usage:
// - Fast and short SET and MAP (just add val propery to node)
// - Fast implementation of array if merges are required: key=index of elem
// - When priority is randomized hash of value, treap provides unique binary tree representation of content

// All complexities are O(log n) avg, O(n) worst case
// Unique keys only!
// Remember to srand!

#define MOD 1000000007
using T=ll;

typedef struct _Node {
    _Node(T k) : key(k), prt(rand() % MOD), l(0), r(0) {}
    T key;
    ll prt;
    _Node * l, * r;
} *Node;

bool find(T x, Node n) {
    if (!n)
        return 0;
    if (n->key == x)
        return 1;
    if (n->key > x)
        return find(x, n->l);
    return find(x, n->r);
}

// values of one have to be strictly smaller than the other!!!
Node merge(Node l, Node r) {
    if (!l || !r)
        return l ? l : r;
    if (l->prt > r->prt) {
        l->r = merge(l->r, r);
        return l;
    }
    r->l = merge(l, r->l);
    return r;
}

void split(T x, Node n, Node& l, Node& r) {
    if (!n)
        l = r = 0;
    else if (x < n->key)
        split(x, n->l, l, n->l), r = n;
    else
        split(x, n->r, n->r, r), l = n;
}

void ins(Node x, Node& n) {
    if (!n)
        n = x;
    else if (x->prt > n->prt)
        split(x->key, n, x->l, x->r), n = x;
    else
        ins(x, x->key < n->key ? n->l : n->r);
}

void del(T x, Node& n) {
    if (n->key == x) {
        delete n;
        n = merge(n->l, n->r);
    } else {
        del(x, x < n->key ? n->l : n->r);
    }
}

void prt(Node n, vll& ret) {
    if (!n) return ;
    ret.pb(n->key);
    prt(n->l,ret);prt(n->r,ret);
}

// just for test:
void test(vll& nums) {
    Node tree = 0;
    for (auto i : nums) {
        ins(new _Node(i), tree);
    }
    for (auto i : nums) {
        assert(find(i, tree));
        del(i, tree);
        assert(!find(i, tree));
    }
}

int main() {
    srand(time(NULL));
    vll t1 = {10, 5, 12, 13, 14, 3, 7}, t2 = {1, 2, 3, 4, 5},
        t3 = {5, 4, 3, 2, 1}, t4;
    set<ll> s;
    REP(i, 1000) {
        ll x = rand() % MOD;
        while (s.count(x))
            x = rand() % MOD;
        s.insert(x);
        t4.pb(x);
    }
    test(t1);test(t2);test(t3);test(t4);
}