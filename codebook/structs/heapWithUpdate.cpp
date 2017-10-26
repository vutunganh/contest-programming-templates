// Heap with updates on indexes
// - can be used as Array with deletes, updates and getMax in log(N)

#include "../template.cpp"

template<typename T=ll, typename I=ll, class Comp = greater<pair<T,I>>>
struct UpdHeap {
    UpdHeap() {}
    UpdHeap(vector<T> v) { emplace(v); }
    void clear() {
        mapping.clear(); prio.clear();
    }
    pair<I,T> extractMax() {
        auto ret = getMax();
        mapping.erase(ret.first);
        prio.erase(prio.begin());
        return ret;
    }
    pair<I,T> getMax() {
        auto ret = *prio.begin();
        return {ret.second, ret.first};
    }
    void push(I ind, T val) {
        mapping[ind]=val;
        prio.insert({val,ind});
    }
    void erase(I ind) {
        T oldval = mapping[ind];
        prio.erase(prio.find({oldval,ind}));
    }
    void emplace(vector<T>& v) {
        clear();
        for(int i=0; i<(int)v.size(); i++) push(i,v[i]);
    }
    void update(I ind, T val) {
        erase(ind);
        push(ind,val);
    }
    void incr(I ind, T add) {
        update(ind, mapping[ind]+add);
    }
    unordered_map<I,T> mapping;
    set<pair<T,I>,Comp> prio;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    UpdHeap<> uh({8,7,6,5,2,10});
    for(auto p: uh.prio) dbg(p.y, p.x);
    dbg(uh.getMax().first, uh.getMax().second);
    auto r1=uh.extractMax(); dbg("extracted", r1.x, r1.y);
    for(auto p: uh.prio) dbg(p.y, p.x);
    dbg(uh.getMax().first, uh.getMax().second);
    auto r2=uh.extractMax(); dbg("extracted", r2.x, r2.y);
    for(auto p: uh.prio) dbg(p.y, p.x);
    return 0;
}
