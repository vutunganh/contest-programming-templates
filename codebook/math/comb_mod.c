ll mod = 1000000007ll;

const int X = 400007;

ll P[X], I[X];
ll comb(ll x, ll y, ll mod) {
    return P[x] * I[y] % mod * I[x - y] % mod;
}
void init(ll n, ll mod){
    P[0] = 1;
    F(n) P[i+1] = P[i]*(i+1) % mod;
    I[n-1] = modinv(P[n-1], mod);
    FF(n-1) {
		ll i=n-2-j;
        I[i] = I[i+1] * (i+1) % mod;
    }
}

int main () {
	init(30, mod);
	cout << comb(20, 10, mod) << endl;

    return 0;
}
