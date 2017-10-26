#include "../../math/eraLinear.cpp"

int main(void) {
    ios_base::sync_with_stdio(false);

    compute();
    FOR(i,2,20) dbg(i, lp[i]);

    return 0;
}
