#include "../template.cpp"

double horner(vector<double> v, double x) {
    double s = 0;
    for(ll i=v.size()-1; i>=0; i--) s=s*x+v[i];
    return s;
}

int main() {
    cout << horner({1,2,3}, 3.0) << endl;
    return 0;
}
