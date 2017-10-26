using mt = vector<vector<double>>;
// gauss elimination O(n^3) with partial pivoting
// returns a matrix in upper triangular form with
// Usage:
//    mt A = { {1,2,3,4},{1,0,1,0},{5,3,2,4},{6,1,4,6} }; 
//    mt b = { {1,2},{4,3},{5,6},{8,7} };
//    mt I(4,vector<double>(4));
//    F(4) I[i][i] = 1;
//    gem(merge(A,I),4);  // inverse is in last four columns of result
//    gem(merge(A,b),4); // solutions are as last two columns of result

// Helper function to concatenate two matrixes side by side
mt merge(mt a, mt b) {
    mt res(a.size());
    F(a.size()) {
        res[i].insert(res[i].end(),all(a[i]));
        res[i].insert(res[i].end(),all(b[i]));
    }
    return res;
}

// output fields
double det = 1;
int rnk = -1;
vll ord;
mt gem(mt m, int cols) {
    int h = m.size();
    int w = m[0].size();
    int nncs = cols;
    ord.resize(cols);
    iota(all(ord),0);
    F(min(h,nncs)) {
        pair<double,int> mx = {abs(m[i][i]),i};
        // find pivot
        FOR(j,i,h) mx = max(mx,{abs(m[j][i]),j});
        // null column
        if (mx.x < EPS) {
            FF(w) swap(m[nncs-1][j],m[i][j]);
            swap(ord[i],ord[mx.y]);
            i--;
            nncs--;
            continue;
        }
        det *= ((mx.y - i) % 2 ? -1 : 1); // swapping rows affects determinant
        // swap rows
        swap(m[i],m[mx.y]);

        FOR(j,i+1,h) {
            double val = -m[j][i]/m[i][i];
            FOR(k,i,w) {
                m[j][k] = m[j][k] + val*m[i][k];
            }
        }
    }
    rnk = min(h,nncs);
    
    F(h) {
         det *= m[i][i];
    }
    
    // Stop here for just Gauss Jordan elimination
    // Upper triangular form
    // return m;
    
    // Backpropagation
    // Full gauss elimination
    // ones on diagonal
    for(int i=rnk-1; i>= 0; i--) {
        double val = m[i][i];
        FOR(j,i,w) {
            m[i][j] /= val;
        }
    }
    for(int i=rnk-1; i>0; i--) {
        for(int j=i-1; j>=0;j--) {
            double val = -m[j][i];
            FOR(k,i,w) {
                m[j][k] = m[j][k] + val*m[i][k];
            }
        }
    }
    // upper left diagonal form (diagonal if matrix has full rank)
    return m;
}
