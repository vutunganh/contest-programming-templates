// Power of number
// in log time

ll power(ll a, ll p) {
    ll res = 1, x = a;
    while(p) {
    	if (p & 1) res = (res * x);
    	x = (x * x); p >>= 1;
    }
    return res;
}