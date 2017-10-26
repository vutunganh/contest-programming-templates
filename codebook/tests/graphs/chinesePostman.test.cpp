#include "../../graphs/chinesePostman.cpp"

const ll N=6;
vector<vpll> g(N);
void addEdge(ll i, ll j, ll c) {
    g[i].pb({j,c});
    g[j].pb({i,c});
}

int main() {
    addEdge(0,1, 1);
    addEdge(1,2, 2);
    addEdge(2,3, 3);
    addEdge(3,0, 4);
    addEdge(4,0, 1);
    addEdge(5,0, 1);
    // circuit 0->1->2->3->0 + 0,4 + 0,5
    // =sum (12) + 4->0->5 (fake edge 4-5 c=2) = 14
    cout << chinesePostman(g) << endl;
    return 0;
}
