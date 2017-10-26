// Erdős–Gallai theorem
// Checks whether there exist a graph for given score
// O(n)
#include "../template.cpp"

//v
bool erdosGallai(vll v) {
    ll n = v.size(), degSum = 0;
    sort(all(v),greater<ll>());
    F(n) {
        degSum += v[i];
        ll minDegSum=0;
        FOR(j,i+1,n) minDegSum += min(i+1,v[j]);
        if (degSum > i*(i+1) + minDegSum) return false;
    }
    return true;
}
//^

void test(vll v) {
    cout << " Test: "; 
    F(v.size()) cout<<(i?",":"")<<v[i];
    cout<<": "<<(erdosGallai(v)?"YES":"NO")<<endl;
}

int main(void) {
    test({1,1});
    test({1,2,3,3,4,5});
}

