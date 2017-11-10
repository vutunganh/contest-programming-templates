// Lazy Segment Tree (Lst) 
//  with interval queries and updates
// O(n log n) Build, O(log n) interval query
 // Value and Lazy value 
//    - can use different operations: e.g. toggle all bits vs. sum of bits
template<typename T,typename LT=T>
struct Lst {
    Lst(vll & a) : Lst(a.size()) { build(a); }
    // Define operations:
    T mrg(T a,T b) { return max(a,b); } // merge 2 values
    T apply(T val, LT l, int len) { // apply lazy value
        return l==-INF ? val : l;
    }
    void comb(LT &a, LT b) { 
        if(b!=-INF) a=b;
    } // combine 2 lazy values
    T DEF = -INF; // default tree value
    LT ZERO = -INF; // default lazy value
    // Internal:
    int n;
    vector<T> seg;
    vector<LT> lazy;
    Lst(int n) : n(n), seg(vector<T>(4*n,DEF)), lazy(vector<LT>(4*n,ZERO)) {}
    int L(int x) { return 2*x; }
    int R(int x) { return 2*x+1; }
    // Build ST from array a
    void build(vll & a, int st=0, int en=-1, int p=1) {
        if(!~en)en=n-1;
        if (st == en)
            seg[p]=a[st];
        else {
            build(a,st,(st+en)/2,L(p));
            build(a,(st+en)/2+1,en,R(p));
            seg[p]=mrg(seg[L(p)],seg[R(p)]);
        }
    }
    // Get value summation (using mrg) of range <st,en> inclusive
    T get(int st, int en, int sst=0, int sen=-1,int p=1) {
        if(!~sen) sen=n-1;
        if(st > sen || en < sst) return T();
        if(st <= sst && en >= sen) return val(p, sst, sen);
        int mid = (sst+sen)/2;
        push(L(p)); push(R(p)); lazy[p]=ZERO; // push current lazy to children
        seg[p]=mrg(val(L(p),sst,mid), val(R(p),mid+1,sen)); // recompute val after ^
        T lt=get(st,en,sst,mid,L(p));
        T rt=get(st,en,mid+1,sen,R(p));
        if (st <= mid && en > mid) return mrg(lt,rt);
        return st <= mid ? lt : rt;
    }
    // Update value on range using Lazy value
    void upd(int st, int en, LT x=1, int sst=0, int sen=-1, int p=1) {
        if(!~sen) sen=n-1;
        if(st > sen || en < sst) return ;
        if(st <= sst && en >= sen) return comb(lazy[p],x); 
        int mid = (sst+sen)/2;
        push(L(p)); push(R(p)); lazy[p]=ZERO; // push current lazy to children
        upd(st,en,x,sst,mid,L(p));
        upd(st,en,x,mid+1,sen,R(p));
        seg[p]=mrg(val(L(p),sst,mid), val(R(p),mid+1,sen));
    }
    T val(int p, int sst, int sen) {
        return apply(seg[p],lazy[p],sen-sst+1);
    }
    void push(int to) {
        comb(lazy[to],lazy[to/2]);
    }
};
