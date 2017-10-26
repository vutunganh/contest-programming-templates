// Find length of shortest path that visits all cities
// Complexity: O(n^2*2^n)
// Usage tsp(0,(1<<number_of_vertices) - 2)
// graph is represented as matrix dist with distances from i to j
using T = ll;
#define MX
T dist[MX][MX];
T dp[MX][1<<MX];

void init() {
    fill(*dp,*dp+sizeof(dp)/sizeof(T),-1);
}
T tsp(int pos, int vis) {
    if (not vis) return dist[pos][0];
    T& res = dp[pos][vis];
    T mix = INF;
    if (res == -1) {
        F(MX) {
            if ((1<<i) & vis) {
                mix = min(mix,tsp(i,vis ^ (1<<i)) + dist[pos][i]);
            }
        }
    }
    return mix;
}
