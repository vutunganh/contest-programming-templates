#include "../template.cpp"


ll cost[MX][MX];
ll tc[MX][MX];
ll minCost(ll cost[R][C], ll m, ll n){
     ll i, j;
     tc[0][0] = cost[0][0];
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j]; 
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j-1], min(tc[i-1][j], tc[i][j-1])) + cost[i][j];
 
     return tc[m][n];
}
