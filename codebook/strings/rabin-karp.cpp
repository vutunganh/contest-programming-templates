#include "../template.cpp"

// -Rabin-Karp Algorithm-
// Pattern matching algo
// - usefull for random distributed or when O(1) space needed
// averige O(n+m), worst case O(n*m)
// n=|txt|, m=|patt|
// O(1) space

#define ABC 256 // size of alphabeth
ll m(ll a, ll q){ return ((a%q)+q)%q; } // mod operation
// q must be PRIME !!!
vll search(string& patt, string& txt, int q) {
    vll found;
    ll M=patt.size(),
       N=txt.size(),
       p=0,  // hash value for pattern
       t=0, // hash value for act window of txt
       h=1;
    // h="pow(ABC, M-1)%q"
    F(M-1) h=(h*ABC)%q;
    F(M){ // calc hash
        p=(ABC*p + patt[i])%q;
        t=(ABC*t + txt[i])%q;
    }
    F(N-M+1) { // if hash of curr wind is ok, check one by one
        if (p==t) {
            bool ok=1;
            FF(M) if(txt[i+j]!=patt[j]) { ok=0;break; }
            if(ok)found.pb(i);
        }
        // recalc hash for next wind
        if (i < N-M) t=m(ABC*(t - txt[i]*h) + txt[i+M], q);
    }
    return found;
}
 
/* Driver program to test above function */
int main()
{
    string txt="aaabcabbabcabbabcabb";
    string patt="abcabbabcabb";
    int q=101;//PRIME
    vll found=search(patt,txt,q);
    for(auto i:found) D(i);
    return 0;
}