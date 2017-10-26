#include "../template.cpp"

// Prime and Factorization sieve in O(n)
// Constructs lp[i] := minimum prime factor of i

// Why works? every i has unique represenation in form i=lp[i] * x where lp[i] <= lp[x]
// Why linear? each step sets value, it is set only once

const int N = 10000000;
int lp[N+1];
vector<int> pr;

void compute() {
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}