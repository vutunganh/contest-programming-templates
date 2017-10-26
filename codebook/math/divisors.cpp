#include "../template.cpp"

// Finds all divisors of n
// in O(sqrt(n))

vll divisors(ll n){
    vll a,b;
    for (int i = 1; i*i <= n; ++i) {
        if(n % i == 0){
            a.pb(i);
            b.pb(n/i);
        }
    }
    if(b.back()==a.back())b.pop_back();
    reverse(b.begin(),b.end());
    a.insert(a.end(),b.begin(),b.end());
    return a;// list of sorted divisors
}

int main() {
    vll d=divisors(28);
    for(auto i:d)cout<<i<<",";
    cout<<endl;
    return 0;
}
