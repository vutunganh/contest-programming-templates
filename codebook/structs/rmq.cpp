#include "../template.cpp"

// Range minimum query
// returns index into A
// <O(NlogN),O(1)>
// preprocess=space, query

#define MAX 10000
#define lMAX 20 // log2(MAX)

ll A[MAX]; // input array
ll M[MAX][lMAX]; // rmq struct
ll N;

void buildRMQ(){
    F(N) M[i][0]=i;
    ll lN=(ll)log2(N);
    FOR(j,1,lN+1)
        for(ll i=0;i+(1<<j)-1<N; i++)
            if(A[M[i][j-1]] < A[M[i+(1<<(j-1))][j-1]])
                M[i][j]=M[i][j-1];
            else M[i][j]=M[i+(1<<(j-1))][j-1];
}

// RETURNS INDEX 
ll queryRMQ(ll i,ll j) {
    ll k = (ll)log2(j-i+1);
    if(A[M[i][k]] < A[M[j-(1<<k)+1][k]])
         return M[i][k];
    else return M[j-(1<<k)+1][k];
}

ll cnt=0;
vll ng[MAX];
ll id[MAX]; // id of vertex in rmq array
ll ind[MAX]; // id of rmq pos of vertex 

void addItem(ll u, ll d) { 
    id[cnt]=u;
    ind[u]=cnt;
    A[cnt++]=d;
}
void dfs(ll u,ll d, ll par) {
    addItem(u,d);
    for(auto i:ng[u]) {
        if(i==par)continue;
        dfs(i,d+1,u);
        addItem(u,d);
    }
}
void buildLCA(){
    dfs(0,0,-1);
    N=cnt;
    buildRMQ();
}

ll queryLCA(ll i, ll j){
    ll a=ind[i], b=ind[j]; if(a>b)swap(a,b);
    return id[queryRMQ(a,b)];
}

void addEdge(ll i, ll j) { ng[i].pb(j); ng[j].pb(i); }




#ifndef NOMAIN
int main(void) {
	ios_base::sync_with_stdio(false);
    vll a={5,2,1,6,3,3,2,6,8};
    copy(a.begin(),a.end(),A);
    N=a.size();
    buildRMQ();
    ll lN=(ll)log2(N);
    F(N){FF(lN+1) cout<<A[M[i][j]]<<' '; cout<<endl;}
    F(N)FOR(j,i,N)cout<<"RMQ "<<i<<","<<j<<": "<<A[queryRMQ(i,j)]<<endl;
	return 0;
}
#endif
