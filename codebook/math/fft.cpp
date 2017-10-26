#include "../template.cpp"

// Algorithm for fast polynom multiplication using DFFT.
// For polynoms P,Q returs P*Q.
// 
// N(logN) where N = max(|P|,|Q|})
// 
// IN: polynom P, size of P pn, Q, qn, Return polynom R
// OUT: length of polynom R = P*Q


// use on:
// - multiplication of long numbers
// - convolution: constant difference -> constant sum trick
//      reverse second polynom, multiplication will give you 
//      at index i overlapping multiplication after shift by i
//      e.g.   0 1 2
//           3 2 1 0
//      convolution[2]=a[0]*b[2] + a[1]*b[1] + a[2]*b[0]
//      because 0+2 = 1+1 = 0+2 = 2

#define MX >>4*length of P,Q<<

typedef complex<double> cpx;
void dft(const cpx *s,cpx *r,ll n,const cpx &wn,cpx *h){
    if(n==1){*r=*s;return;}
    ll N=n>>1,j(-2),k(-1);;
    cpx *os=h,*es=h+N,*oR=h+2*N,*eR=h+3*N;
    F(N)es[i]=s[j+=2],os[i]=s[k+=2];
    cpx w(1,0),t(wn*wn);
    dft(es,eR,N,t,h+4*N),dft(os,oR,N,t,h+4*N);
    F(N)t=w*oR[i],r[i]=eR[i]+t,r[i+N]=eR[i]-t,w=wn*w;
}
ll fft(ll*P,ll pn,ll*Q,ll qn,ll*R){
    static cpx ra[MX],b[MX],a[MX],rb[MX],tr[MX],wn,o[(MX)<<2];ll N(1),h(max(pn,qn)*2-1),H(pn+qn-1);
    while(N<=h)N<<=1;
    F(N)a[i]=b[i]=ra[i]=rb[i]=tr[i]={0,0};F(pn)a[i].real(P[i]);
    F(qn)b[i].real(Q[i]);
    wn={cos(2*M_PI/N),sin(2*M_PI/N)};
    dft(a,ra,N,wn,o),dft(b,rb,N,wn,o);F(N)tr[i]=ra[i]*rb[i];
    dft(tr,rb,N,pow(wn,-1),o);
    F(N)rb[i].real(rb[i].real()/N);F(H)R[i]=(ll)(rb[i].real()+0.5);
    return H;
}

ll pa[]={1,2,3}, pb[]={1,2};
ll r[6];
int main(void) {
	ios_base::sync_with_stdio(false);
    ll len=fft(pa,3,pb,2,r);
    F(len)cout<<r[i]<<' ';cout<<endl;
    // ret: 1 4 7 6
    // => 1+2x+3x^2 * 1+2x = 1+4x+7x^2+6x^3
    // also 321*21=6741
	return 0;
}
