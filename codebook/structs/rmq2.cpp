#include "../template.cpp"

struct Rmq {
   vll A; // input array
   vector<vll> M; // rmq struct
   ll N;
   Rmq(vll & v) {
       N=v.size();
       ll lN=(ll)log2(N);
       A=v; M=vector<vll>(N,vll(lN+1));
       F(N) M[i][0]=i;
       FOR(j,1,lN+1)
           for(ll i=0;i+(1<<j)-1<N; i++)
               if(A[M[i][j-1]] < A[M[i+(1<<(j-1))][j-1]])
                   M[i][j]=M[i][j-1];
               else M[i][j]=M[i+(1<<(j-1))][j-1];
   }

   // RETURNS INDEX 
   ll query(ll i,ll j) {
       ll k = (ll)log2(j-i+1);
       if(A[M[i][k]] < A[M[j-(1<<k)+1][k]])
           return M[i][k];
       else return M[j-(1<<k)+1][k];
   }
};

#ifndef NOMAIN
int main(void) {
	vll v({1,2,3,2,1});
	Rmq rmq(v);
	F(v.size()) cout<<rmq.query(i,i)<<endl;; 
	return 0;
}
#endif
