ull choose(ull n, ull k) {
    if (k > n) return 0;
    ull r = 1;
	F(k){
        r *= n--;
        r /= i+1;
    }
    return r;
}