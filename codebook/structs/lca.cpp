#define NOMAIN 1
#include "rmq.cpp"

// Lowest common ancestor
// <O(NlogN),O(1)> where N=|E|
//
// using from RMQ:
// MAX, ll N, ll A[MAX];
// MAX=2*maximum number of edges

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

int main() {
    addEdge(0,1);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(0,4);
    addEdge(4,5);
    addEdge(5,6);
    addEdge(4,7);
    buildLCA();
    cout<<"LCA(1,4): "<<queryLCA(1,4)<<endl;
    cout<<"LCA(6,4): "<<queryLCA(6,4)<<endl;
    cout<<"LCA(7,6): "<<queryLCA(7,6)<<endl;
    cout<<"LCA(2,3): "<<queryLCA(2,3)<<endl;
    return 0;
}
