ll pw(int a,int n,int M){
    ll P(a),r=1;
    while(n){
        if(n&1)r=(r*P)%M;
        P=(P*P)%M,n>>=1;
    }
    return r;
}
bool wt(int a,int n){
    int t(1),u(n>>1);
    ll p,c;
    while(!(u&1))
        u>>=1,++t;
    p=pw(a,u,n);
    F(t){
        c=(p*p)%n;
        if((c==1)&&(p!=1)&&(p!=n-1))return 1;
        p=c;
    }
    return c!=1;
}

bool isP(int n){
    if(((!(n&1))&&n!=2)||(n<2)||(!(n%3)&&n!=3))return 0;
    if(n<1373653){
        for(int k=1;36*k*k-12*k<n;++k)
            if(!(n%(6*k+1))||!(n%(6*k-1)))return 0;
        return 1;
    }
    if(n<9080191)return !wt(31,n)&&!wt(73,n);
    return !wt(2,n)&&!wt(7,n)&&!wt(61,n);
}