#include "../template.cpp"

struct sat2 {
    gr g;
    // init with num of variables => each var gets 2 vertices (0,1)
    sat2(ll n) : g(n<<1) {}
    
    bool is() {
        vll comp = strongComp(g);
        F(g.size()>>1) if (comp[i<<1]==comp[i<<1|1]) return false;
        return true;
    }

    void addOr(ll a, ll b) {
        // (a v b) ==> (^a => b) ^ (^b => a)        
        addImpl(a^1,b);
        addImpl(b^1,a);
    }

    void addTrue(ll a) {
        addImpl(a^1, a); // if something would lead to ^a, we don't want it
    }
    void addImpl(ll a, ll b) { g[a].pb(b); }
};
