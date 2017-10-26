// Fenwick tree data structure (cummulative sums)
// ====
// log(n) get and inc
// Doesn't work with index 0!!!

template<int N,typename T=ll>
struct Ft {
    T ft[N+1];
    Ft() { CL(ft,0); }
    void upd(int i, T val) {
        for(;i < N+1; i += i & -i) ft[i] += val;
    }
    T get(int en) {
        T sum = T();
        for(;en; en -= en & -en) sum += ft[en];
        return sum;
    }
    T get(int st, int en) {
        return get(en) - get(st-1);
    }
};

