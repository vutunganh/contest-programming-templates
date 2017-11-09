#include "../../template.cpp"
#include "../../structs/segmentTreeLazy.cpp"

void checkDim(vll & v, ll i, ll j) {
    bool dimOk=i>=0 && j<v.size() && i<=j;
    if(!dimOk) dbg("ERR query dim",i,j,"on",v.size());
    assert(dimOk);
}

ll upd(vll & v, ll i, ll j, ll val) {
    checkDim(v,i,j);
    FOR(k,i,j+1) v[k]+=val;
}
ll q(vll & v, ll i, ll j) {
    checkDim(v,i,j);
    ll ret=-INF;
    FOR(k,i,j+1) ret=max(ret,v[k]);
    return ret;
}

#define T 1000

void testQ(vll &v, Lst<ll> &st) {
    ll n=v.size();
//    ll len=rand()%n;
    ll len=0;
    ll pos=rand()%(n-len);
    ll a=q(v,pos,pos+len), b=st.get(pos,pos+len);
    bool ok = a == b;
    if(!ok) {
        dbg("query failed",pos,pos+len,"ret",a,"segTree:",b);
        F(n) cout<<(i?"\t":"")<<i; cout<<endl;
        F(n) cout<<(i?"\t":"")<<v[i]; cout<<endl;
        F(n) cout<<(i?"\t":"")<<st.get(i,i); cout<<endl;
    }
    assert(ok);
}

void testUpd(vll &v, Lst<ll> &st) {
    ll n=v.size();
//    ll len=rand()%n;
    ll len=0;
    ll pos=rand()%(n-len);
    ll val=rand()%10000;
//    dbg("upd",pos,pos+len,val);
    upd(v,pos,pos+len,val);
    st.upd(pos,pos+len,val);
}

// default max with sums
void testST(ll n) {
    dbg("len",n);
    Lst<ll> st(n);
    vll v(n);
    F(T) {
        testUpd(v,st);
        testQ(v,st);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    FOR(l,1,2049) testST(l);
    return 0;
}
