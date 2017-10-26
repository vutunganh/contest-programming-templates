// Returns 
// [ d = gcd(a,b);
//   + finds x,y such that d = ax + by ]

ll extended_euclid(ll a,ll b,ll &x,ll &y) {
    if (a == 0) { x = 0; y = 1; return b;}
    ll x1, y1; ll d = extended_euclid(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
