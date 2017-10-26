#include "../template.cpp"

#define mod (ll)(1e9+7)
ll m(ll x) { return ((x%mod)+mod)%mod; }

ll fib(ll n) {
    if(!n) return 0;
    ll fk=1,fk1=1,tmp;
    ll i=floor(log2(n)) - 1;
    while(i>=0) {
        ll t_fk=fk;
        fk=fk*(2*fk1-fk);
        fk1=m(fk1*fk1) + m(t_fk*t_fk);
        if(n&(1ll<<i)) {
            ll t_fk1=fk1;
            fk1=m(fk1+fk);
            fk=t_fk1;
        }
        i--;
    }
    return fk;
}

int main() {
    F(15) dbg(i,"th fib = ",fib(i));
    dbg(1e18,"th fib (mod 1e9+7) = ",fib(1e18));
    return 0;
}
