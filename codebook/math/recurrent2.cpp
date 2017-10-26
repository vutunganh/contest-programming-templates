/*
    Calculates nth member of linear recurrence
    f(i) = c1 * f(i - 1) +  ... + ck * f(i - k)
    ----
    creates matrix:
       | 0 1 0 0 ... 0 |   | f(n-K)   |
       | 0 0 1 0 ... 0 |   | f(n-K+1) |
f(n) = | 0 0 0 1 ... 0 | * | f(n-K+3) |
       | ...           |   | ...      |
       | ck  ...    c1 |   | f(n-1)   |
    and caltulates n-k th power by square & multiply
    and multiplies it with init vector
*/

#define REP(i,b) for(int i=0;i<=b;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)

typedef vector<vector<int> > TMatrix;
int K; // level of recurrence
int n0 = 1; // first init val is n0-th member of recurrence

// computes A * B
TMatrix mul(TMatrix A, TMatrix B)
{
    TMatrix C(K, vector<int>(K));
    REP(i, K-1) REP(j, K-1) REP(k, K-1)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
TMatrix pow(TMatrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    TMatrix X = pow(A, p/2);
    return mul(X, X);
}

int nth(vector<int> c, vector<int> init,int n) {
    K = c.size();
    TMatrix T(K, vector<int>(K));
    REP(i, K-2) {
        REP(j,K-1) {
            if (i == j-1)
                T[i][j] = 1;
            else
                T[i][j] = 0;
        }
    }
    REP(j,K-1) T[K-1][j] = c[j]; // coeficients
    T = pow(T, n-K+n0);
    int res = 0;
    REP(i, K-1)
        res = (res + T[1][i] * init[i]) % MOD;
    return res;
}

int main(int argc, char const *argv[])
{
    // 6th fib:
    cout << nth({1,1}, {1,1}, 6) << endl;
    // 6th f(i) = 2*f(i-1) + f(i-3):
    cout << nth({1,0,2}, {0,1,2}, 6) << endl;
    return 0;
}
