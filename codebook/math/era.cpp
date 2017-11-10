#define MX 10000
bitset<MX> era;
// ll sp[MX]; // for prime factorization (can be ommited)
           // also in init function
vll pri;
void init() {
    era.set(); // all ones
    era[0] = era[1] = 0;
    for(int i = 2; i < MX; i += i > 2 ? 2 : 1) {
        if (!era[i]) continue;
        pri.pb(i);
        // sp[i] = i;
        for (int m = 2; i*m < MX; m++) {
            // if (era[i*m]) sp[i*m]=i;
            era[i*m] = 0;
        }
    }
}
